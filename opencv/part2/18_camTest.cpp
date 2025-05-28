// ls /dev/vi*
// v4l2-ctl --list-devices
// v4l2-ctl -d /dev/video0 --list-formats-ext
// sudo usermod -aG video $USER
#include <iostream>
#include <opencv2/opencv.hpp>
// #include </home/hwaseop/ku_lhs2025/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다." << endl;
    }
    cout << "Frame width :" << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    auto fps = cap.get(CAP_PROP_FPS);
    cout << "fps : " << cvRound(fps) << endl;

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty()) // 동영상이 끝나고 마지막에 에러가 안나게 하기위해서
            break;
        imshow("frame", frame);
        if (waitKey(1000 / fps) == 27) // fps 조절 숫자,27=은 esc를뜻함, 숫자가 커질수록 동영상이 느려짐
            break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}