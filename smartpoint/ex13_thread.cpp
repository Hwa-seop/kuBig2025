#include <iostream>
#include <thread>
#include <mutex> //mutually exclusive 상호 배제
using namespace std;

int counter = 0;
mutex mtx;

void increment()
{
    for (int i = 0; i < 1000; i++)
    {
        lock_guard<mutex> lock(mtx);
        counter++;
    }
}
int main()
{
    thread t1(increment);
    cout << "최종 카운터 값1: " << counter << endl;

    thread t2(increment);
    cout << "최종 카운터 값2: " << counter << endl;

    t1.join(); // t1에서 실행되는 상황이 끝나면 대기하라라는 명령
    // main,t1 thread 모두끝나야 다음 문장 실행
    cout << "최종 카운터 값3: " << counter << endl;

    t2.join();
    // main ,t1,t2 thread 모두 끝나야 다음 문장이 실행

    cout << "최종 카운터 값4: " << counter << endl;
}
