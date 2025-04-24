#include <memory>
#include <iostream>
using namespace std;

// --------unique_ptr----------
// int main()
// {
//     // unique_ptr<int> ptr = make_unique<int>(10); // 동적 생성
//     auto ptr = make_unique<int>(10); // 동적 생성
//     cout << *ptr << endl;            // 출력: 10

//     auto p2 = move(ptr); // 소유권 이동
//     if (ptr == nullptr)
//         cout << "ptr은 이제 nullptr입니다." << endl;

//     cout << *p2 << endl; // 출력: 10
// }

// -------shared_ptr-------
// int main()
// {
//     // shared_ptr<int> a = make_shared<int>(20);
//     auto a = make_shared<int>(30);
//     shared_ptr<int> b = a;

//     cout << a.use_count() << endl; // 2 (a, b 공유 중), 갯수
//     cout << *a << endl;            // 30
//     cout << *b << endl;            // 30
// }

// ------------weak_ptr---------------

int main()
{
    shared_ptr<int> a = make_shared<int>(100);
    weak_ptr<int> w = a;

    if (auto sp = w.lock())
    {
        cout << *sp << endl; // 100
    }
}
