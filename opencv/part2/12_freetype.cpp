#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/freetype.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

// 한글 사용하기위한 함수정의
Ptr<cv::freetype::FreeType2> rapperFreeTypeCenterSetup(const String &fontpath)
{
    Ptr<cv::freetype::FreeType2> ft2 = freetype::createFreeType2();
    ft2->loadFontData(fontpath, 0);
    return ft2;
}
void rapperFreeTypeCenter(Mat &img, Ptr<cv::freetype::FreeType2> ft2, const String &text, const int &textHeight,
                          const int &thickness, const int &line_type, const Scalar &color, const Point &textOrg)
{
    Size textSize = ft2->getTextSize(text, textHeight, -1, 0);
    Point org((textOrg.x - textSize.width) / 2, (textOrg.y - textSize.height) / 2);
    ft2->putText(img, text, org, textHeight, color, thickness, line_type, true);
}

int main()
{
    Mat img(400, 600, CV_8UC3, white);

    int a = 0, b = 0, c = 0;
    auto ft2 = rapperFreeTypeCenterSetup("/home/hwaseop/ku_lhs2025/opencv/data/NanumPenScript-Regular.ttf");

    String text = "이것은 IOT 수업 입니다.";

    while (true)
    {
        img.setTo(white); // 배경 그리기
        rapperFreeTypeCenter(img, ft2, text, 50, -1, LINE_AA, black, Point(600, 300));
        rapperFreeTypeCenter(img, ft2, "두번째 텍스트입니다.", 50, -1, LINE_AA, black, Point(600, 400));
        rapperFreeTypeCenter(img, ft2, "세번째 텍스트입니다.", 50, -1, LINE_AA, black, Point(600, 200));

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}