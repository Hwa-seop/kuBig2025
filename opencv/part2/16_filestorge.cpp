#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
// #include </home/hwaseop/ku_lhs2025/opencv/part2/array.h>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    // data
    String name = "Johaeun";
    int age = 31;
    Point pt1(100, 200);
    vector<int> scores = {100, 100, 100};
    Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);
    // Array array(10);

    String filename = folderPath + "mydata1.yml";
    FileStorage fs;
    fs.open(filename, FileStorage::WRITE);
    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "scores" << scores;
    fs << "data" << mat1;
    // fs << "array" << array; // 빌드 통과 못함!

    fs.release();

    return 0;
}