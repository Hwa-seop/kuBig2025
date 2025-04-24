#include <iostream>
#include <memory>
using namespace std;
class Myclass
{
public:
    int test_a;
    Myclass() // 생성자
    {
        cout << "Myclass 생성!!" << endl;
        test_a = 100;
    }
    ~Myclass() { cout << "Myclass 소멸!!" << endl; } // 소멸자
};

int main()
{
    auto ptr = make_unique<Myclass>(); // unique_ptr<Myclass> ptr=make_unique<Myclass>();
    // heap에 만들어진 메모리.
    ptr->test_a = 100;
    cout << ptr->test_a << endl;

    return 0;
}