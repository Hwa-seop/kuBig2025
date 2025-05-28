#include <iostream>
#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, white);
    int a = 0, b = 0, c = 0;

    while (true)
    {
        img.setTo(white);
        putText(img, "This is kubig2025 test text.", Point(20 + a, 50), FONT_HERSHEY_SIMPLEX, 2, red);
        putText(img, "This is kubig2025 test text.", Point(20 + a, 120), FONT_ITALIC, 2, green);
        putText(img, "This is kubig2025 test text.", Point(20 + a, 220), FONT_HERSHEY_DUPLEX, 3, blue);
        putText(img, "This is kubig2025 test text.", Point(20 + a, 320), FONT_HERSHEY_PLAIN, 4, black);

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
        a += 1;
        b -= 1;
        c += 1;
    }
    destroyAllWindows();
    return 0;
}
