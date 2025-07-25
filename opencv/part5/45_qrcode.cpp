#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    VideoCapture cap(0);

    QRCodeDetector qrDetector;
    vector<Point> points;
    String info;
    Mat img;
    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        info = qrDetector.detectAndDecode(img, points);

        if (!info.empty())
        {
            polylines(img, points, true, red, 2);
            putText(img, info, Point(10, 30), FONT_HERSHEY_DUPLEX, 1, black);
        }

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}