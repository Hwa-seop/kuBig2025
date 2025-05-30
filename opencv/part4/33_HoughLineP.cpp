#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";
int main()
{
    VideoCapture cap(0);
    Mat img, edge;
    int low_v, high_v, h_thresh;
    namedWindow("img1");
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);
    createTrackbar("h_thresh", "img1", &h_thresh, 255);

    vector<Vec4i> lines;
    Point pt1, pt2;
    float rho, cos_t, sin_t, x0, y0, alpha, theta;

    // vector img show 코드
    while (true)
    {
        cap >> img;
        Canny(img, edge, low_v, high_v);
        HoughLinesP(edge, lines, 1, CV_PI / 180, h_thresh, 50, 5);

        for (auto l : lines)
            line(img, Point(l[0], l[1]), Point(l[2], l[3]), red, 2, LINE_AA);
        imshow("img1", edge);
        imshow("img", img);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}