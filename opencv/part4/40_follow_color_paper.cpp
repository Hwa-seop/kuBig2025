// 카메라 켜서 frame 확보
// 색공간->hsv로 변경 clone()해서 따로 처리
//  양방향 필터 처리
// inrange-> 색종이를 인식
// morph 함수 -> 이진화 Mat정리
// labeling
// 화면에 rectangle로 표시
// putText,ft2로 색종이 or color-paper
// 사각형과 폰트는 색종이를 따라다녀야함

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "❌ 카메라를 열 수 없습니다." << endl;
        return -1;
    }

    while (true)
    {
        Mat frame, hsv, filtered, mask, morphed;
        cap >> frame;
        if (frame.empty())
            break;

        cvtColor(frame, hsv, COLOR_BGR2HSV);
        Mat hsv_clone = hsv.clone();
        bilateralFilter(hsv_clone, filtered, 9, 75, 75);

        // ✅ HSV 범위 완화: 연한 분홍 ~ 붉은 계열까지 포함
        Scalar lower_pink(140, 30, 100);
        Scalar upper_pink(180, 150, 255);
        inRange(filtered, lower_pink, upper_pink, mask);

        // Morphology 연산
        Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(mask, morphed, MORPH_OPEN, kernel);
        morphologyEx(morphed, morphed, MORPH_CLOSE, kernel);

        // 컨투어 찾기
        vector<vector<Point>> contours;
        findContours(morphed, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for (const auto &contour : contours)
        {
            double area = contourArea(contour);
            if (area < 500 || area > 30000)
                continue; // 완화된 면적 조건

            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(contour, true) * 0.03, true); // 근사율도 살짝 느슨하게

            if (approx.size() >= 4 && isContourConvex(approx))
            {
                Rect box = boundingRect(approx);

                float aspect = (float)box.width / box.height;
                if (aspect > 0.5 && aspect < 2.0)
                { // 정사각형~직사각형 모두 허용
                    rectangle(frame, box, Scalar(0, 255, 0), 2);
                    putText(frame, "Color Paper", Point(box.x, box.y - 10), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);
                }
            }
        }

        imshow("Color Paper Tracker", frame);
        imshow("Mask View", mask);
        if (waitKey(10) == 27)
            break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
