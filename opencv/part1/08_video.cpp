#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    Mat frame;
    while (true)
    {
        cap >> frame;
        imshow("frame", frame);
        if (waitKey(33) == 27) // fps 조절 숫자,27=은 esc를뜻함, 숫자가 커질수록 동영상이 느려짐
            break;
    }

    return 0;
}