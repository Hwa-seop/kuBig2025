#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";
void printMat(InputArray _mat, OutputArray _output);

int main()
{
    Mat img = Mat(10, 5, CV_8UC1, Scalar(125)); // 행,열,값
    cout << img << endl;
    cout << "   " << endl;

    Mat mat2;
    printMat(img, mat2);
    cout << mat2 << endl;
    return 0;
}

void printMat(InputArray _mat, OutputArray _output)
{
    Mat img = _mat.getMat();
    cout << img << endl;
    cout << "   " << endl;
    Mat img2 = img + 3;
    img2.copyTo(_output);
}