#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "building.jpg");
    vector<Mat> images;
    images.push_back(img);
    vector<KeyPoint> keypoints;
    FAST(img, keypoints, 60, true);

    for (auto &k : keypoints)
    {
        circle(img, Point(k.pt.x, k.pt.y), 5, red, 2);
    }

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