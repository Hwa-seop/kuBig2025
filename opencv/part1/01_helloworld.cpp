#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    cout << "hello, world" << endl;

    Mat img = imread(folderPath + "pochaco.bmp");
    if (img.empty())
    {
        cerr << "이미지 불러오기 실패!";
        return -1;
    }

    // cout << img << endl;
    // namedWindow("pochaco", WINDOW_AUTOSIZE);
    // namedWindow("pochaco", WINDOW_FREERATIO);
    namedWindow("pochaco", WINDOW_NORMAL);
    setWindowProperty("pochaco", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);

    // Size size(640, 480);
    // resizeWindow("pochaco", size);

    imshow("pochaco", img);
    waitKey();
    vector<int> jpg_params;
    jpg_params.push_back(IMWRITE_JPEG_QUALITY);
    jpg_params.push_back(20);

    imwrite(folderPath + "pochaco_save_20.jpg", img, jpg_params);

    return 0;
}