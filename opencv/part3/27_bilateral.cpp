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
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img.clone()); // images[0]
    Mat noise(img.size(), CV_32SC1);
    randn(noise, 0, 15);
    add(img, noise, img, Mat(), CV_8U);
    images.push_back(img);      // images[1]
    images.emplace_back(Mat()); // images[2]
    images.emplace_back(Mat()); // images[3]
    GaussianBlur(img, images[2], Size(), 5);
    bilateralFilter(img, images[3], -1, 10, 5);

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