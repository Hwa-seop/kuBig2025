#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

void on_level_change(int pos, void *data);

int main()
{
    Mat img = Mat::zeros(1000, 1000, CV_8UC1);

    namedWindow("img");
    int pos;

    createTrackbar("level", "img", &pos, 255, on_level_change, (void *)&img);
    int keycode;
    while (true)
    {
        img.setTo(pos);
        imshow("img", img);
        keycode = waitKey(33);
        if (keycode == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}

void on_level_change(int pos, void *data)
{
    cout << pos << endl;
}
