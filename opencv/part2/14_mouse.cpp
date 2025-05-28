#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

void on_mouse(int event, int x, int y, int flags, void *data);

int main()
{
    Mat img = imread(folderPath + "pochaco.bmp");
    namedWindow("img");
    setMouseCallback("img", on_mouse, (void *)&img);
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        i = getTickCount();
        imshow("img", img);
        keycode = waitKey(33);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
}

void on_mouse(int event, int x, int y, int flags, void *data)
{
    static Point pt01d;
    static bool pushed;

    Mat *img = (Mat *)data;
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        pt01d = Point(x, y);
        pushed = true;
        // circle(*img, Point(x, y), 4, red, -1);
        break;
    case EVENT_LBUTTONUP:
        pushed = false;
        // circle(*img, Point(x, y), 4, red, -1);
        break;
    case EVENT_MOUSEMOVE:
        if (pushed)
        {
            line(*img, pt01d, Point(x, y), red, 2);
            // circle(*img, pt01d, Point(x, y), 4, red, -1);
            pt01d = Point(x, y);
        }
        break;

    case EVENT_RBUTTONDOWN:
        cout << "마우스 오른쪽 버튼이 눌렸다!" << endl;
        circle(*img, Point(x, y), 4, yellow, -1);
        break;

    default:
        // cout << "마우스 이벤트!!" << endl;
        break;
    }
}
