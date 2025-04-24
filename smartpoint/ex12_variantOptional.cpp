#include <variant>
#include <string>
#include <iostream>
#include <optional>
#include <any>
using namespace std;
int main()
{
    variant<int, string> data;
    // 데이터가 하나의 메모리에 저장될때
    // 타입이 여러가지일 경우
    data = 42;
    cout << get<int>(data) << endl;
    data = string("hello");
    cout << get<string>(data) << endl;

    optional<int> maybeInt; // 값이 있을 수도 있고 없을 수도 있는 상황
    maybeInt = 10;
    if (maybeInt)
        cout << *maybeInt << endl;

    any anything = 123;
    cout << any_cast<int>(anything) << endl;
    anything = string("hi");
    cout << any_cast<string>(anything) << endl;
    anything = 1;
    cout << any_cast<int>(anything) << endl;

    return 0;
}