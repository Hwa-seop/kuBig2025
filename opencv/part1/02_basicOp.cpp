#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    Point_<int> p1(1, 2); // 템플릿형태
    cout << p1 << endl;
    cout << "x : " << p1.x << " y : " << p1.y << endl;

    Point p2(3, 4); // 타입디파인형태
    Point2f p3(1.23, 4.56);
    Point2d p4(1.1, 2.2);

    cout << p2 << p3 << p4 << endl;

    return 0;
}