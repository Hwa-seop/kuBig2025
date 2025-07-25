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

    bool b1 = (p1 == p2);
    cout << b1 << endl;
    int d1 = p1.dot(p2);
    bool b2 = p2.inside(Rect(1, 1, 5, 5));
    cout << b2 << endl;

    // Size Class
    Size sz1;
    Size sz2(10, 20);
    sz1.width = 10;
    sz1.height = 20;

    Size2f sz3(3.14, 6.78);
    cout << "sz1.area() : " << sz1.area() << " sz1.aspectRatio() : " << sz1.aspectRatio() << endl;

    // Rect Class
    Rect rc1;
    Rect rc2(10, 10, 20, 20);
    Rect rc3 = rc1 + Size(50, 40);
    Rect rc4 = rc2 + Point(10, 10);
    Rect rc5 = rc3 & rc4;
    Rect rc6 = rc3 | rc4;

    cout << "rc5 : " << rc5 << endl;
    cout << "rc6 : " << rc6 << endl;
    cout << rc6.contains(p1);

    // RotatedReat Class
    RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f); // degree
    Point2f pts[4];
    rr1.points(pts);

    Rect br = rr1.boundingRect();
    cout << "rr1 points : ";
    for (int i = 0; i < 4; i++)
    {
        cout << pts[i];
    }
    cout << "bounding Rect : " << br << endl;
    return 0;
}