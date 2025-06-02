#include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    // 캠 연결
    VideoCapture cap(0); // 0번 캠 (내장 캠)
    if (!cap.isOpened())
    {
        cerr << "카메라를 열 수 없습니다." << endl;
        return -1;
    }

    // 얼굴 인식용 분류기 로드
    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");
    if (classifier.empty())
    {
        cerr << "분류기 로딩 실패" << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        // 얼굴 검출
        vector<Rect> faces;
        classifier.detectMultiScale(frame, faces);

        for (auto &rect : faces)
        {
            rectangle(frame, rect, red, 2); // red는 color.hpp에서 정의된 Scalar로 가정
        }

        imshow("Webcam - Face Detection", frame);

        if (waitKey(10) == 27) // ESC 키 누르면 종료
            break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}