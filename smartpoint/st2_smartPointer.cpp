#include <memory>
#include <iostream>
using namespace std;

int main()
{
    // unique_ptr<int> ptr = make_unique<int>(10); // 동적 생성
    auto ptr = make_unique<int>(10); // 동적 생성
    cout << *ptr << endl;            // 출력: 10

    auto p2 = move(ptr); // 소유권 이동
    if (ptr == nullptr)
        cout << "ptr은 이제 nullptr입니다." << endl;

    cout << *p2 << endl; // 출력: 10
}