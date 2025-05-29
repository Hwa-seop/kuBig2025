#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    Mat img1 = imread(folderPath + "lenna.bmp");
    Mat img2 = imread(folderPath + "mask_smile.bmp", IMREAD_GRAYSCALE);

    img1.setTo(yellow, img2);
    imshow("img", img1);

    Mat airplane = imread(folderPath + "airplane.bmp");
    Mat maskAirplane = imread(folderPath + "mask_plane.bmp");
    Mat sky = imread(folderPath + "field.bmp");

    airplane.copyTo(sky, maskAirplane);
    // airplane.copyTo(sky, airplane);

    imshow("sky", sky);

    waitKey();
    destroyAllWindows();

    return 0;
}
