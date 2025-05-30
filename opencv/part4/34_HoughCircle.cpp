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
    Mat img = imread(folderPath + "coins.png");
    if (img.empty())
    {
        cerr << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }
    vector<Mat> images;

    Mat gray, blurred;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    blur(gray, blurred, Size(3, 3));

    vector<Vec3f> circles;
    HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30); // p329

    for (auto &c : circles)
    {
        Point center(cvRound(c[0]), cvRound(c[1]));
        int radius = cvRound(c[2]);
        circle(img, center, radius, red, 2, LINE_AA);
    }
    images.push_back(img);
    images.push_back(blurred);

    // vector img show 코드
    int i = 1;
    for (auto img : images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    waitKey();
    destroyAllWindows();
    return 0;
}