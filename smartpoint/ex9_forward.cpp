#include <iostream>
#include <utility>
using namespace std;

void process(string &&s) // move 나 forward를 사용할때 메모리를 통해 받음
{
    // s = "hi"; // lvalue
    cout << "Rvalue: 참조: " << s << endl;
}
void wrapper(string &&s)
{
    process(forward<string>(s));
}

int main()
{
    wrapper(string("hello, world!!"));
    // wrapper(string("hello, world1"));
    // wrapper(string("hello, world2"));
    // wrapper(string("hello, world3"));
    // wrapper(string());

    return 0;
}