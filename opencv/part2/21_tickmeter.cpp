#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    auto i = getTickCount();
    int keycode;
    TickMeter tm1;
    TickMeter tm2;
    int fps = 100;
    while (true)
    {
        tm1.start();
        tm2.start();
        keycode = waitKey(3);
        cout << "keycode: " << keycode << endl;
        cout << "i: " << i << endl;
        tm1.stop();
        if (tm1.getFPS() > fps)
        {
            auto sleep_duration = static_cast<int>(1000 * (tm1.getFPS() - fps) / tm1.getFPS() / fps);
            this_thread::sleep_for(chrono::milliseconds(sleep_duration));
        }
        tm2.stop();
        cout << "fps1 : " << tm1.getFPS() << endl;
        cout << "fps2 : " << tm2.getFPS() << endl;
        imshow("img", img);
        if (keycode == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}