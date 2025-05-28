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

        line(img, Point(100, 50), Point(200 + a, 100 + a), blue, 1, LINE_AA); // 선을 그림
        line(img, Point(70, 70), Point(220, 120), blue, 3, LINE_4);
        line(img, Point(90, 90), Point(240, 140), blue, 3, LINE_8);

        arrowedLine(img, Point(110, 110), Point(260, 160), orange, 3, LINE_8);
        arrowedLine(img, Point(130, 130), Point(280, 180), orange, 3, LINE_8, 0, 0.05); // 화살표 있는 선

        drawMarker(img, Point(50 + a, 200 + b), red, MARKER_CROSS);
        drawMarker(img, Point(50, 200), black, MARKER_DIAMOND);
        drawMarker(img, Point(50, 200), green, MARKER_STAR);

        rectangle(img, Rect(500, 50, 50 + c, 50 + c), red, 2, LINE_AA); // 사각형
        rectangle(img, Rect(500, 100, 50, 50), red, -1, LINE_AA);

        circle(img, Point(320, 100), 50, yellow, 2, LINE_AA); // 원
        circle(img, Point(320, 150), 50, yellow, -1, LINE_AA);

        ellipse(img, Point(400, 50), Size(60, 30), 20, 0, 50, cyan, FILLED, LINE_AA); // 타원
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
