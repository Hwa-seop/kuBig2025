#include <iostream>
#include <memory>
#include <string>
using namespace std;

class MyData
{
private:
    string data_;

public:
    MyData(const string &d) : data_(d)
    {
        cout << "복사 생성자 호출" << endl;
    }
    MyData(const MyData &data) : data_("100") {}
    MyData(const string &&d) : data_(move(d))
    {
        cout << "이동 생성자 호출" << endl;
    }
    const string &get_data() const
    {
        return data_;
    }
};

void useMyData(MyData &&data)
{
    cout << "복사 이동한 MyData" << endl;
    cout << data.get_data() << endl;
}

void referenceMyData(MyData &data)
{
    cout << "레퍼런스 data" << endl;
    cout << data.get_data() << endl;
}

int main()
{
    string str = "Hello";
    MyData d1(str);
    MyData d2(move(str)); // move의 의미가 rvalue를 넘긴다. 소유권을 넘기는 것은 아니다.
    MyData d3(move(str)); // 만들어진 소유권을 추가 코드가 있어야 안,만들어짐
    // useMyData(d1);
    useMyData(move(d2));
    // useMyData(move(d2));
    referenceMyData(d1);
    return 0;
}