#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/hwaseop/ku_lhs2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다." << endl;
        return -1;
        // cerr << "장치가 없습니다." << endl;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo(folderPath + "inverse_vtest.avi", fourcc, fps, Size(w, h));
    // 저장할 동영상의 인코딩 포맷 설정 (여기선 DIVX 코덱 사용)
    if (!outputVideo.isOpened())
    {
        cerr << "파일 생성 실패!." << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty()) // 동영상이 끝나고 마지막에 에러가 안나게 하기위해서
            break;
        frame = ~frame;
        outputVideo << frame;

        imshow("frame", frame);
        if (waitKey(1000 / fps) == 27) // fps 조절 숫자,27=은 esc를뜻함, 숫자가 커질수록 동영상이 느려짐
            break;
    }

    cap.release();
    outputVideo.release();
    destroyAllWindows();
    return 0;
}
