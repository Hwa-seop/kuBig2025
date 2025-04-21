#include <iostream>
#include <vector>
using namespace std;

// class A :
// public :    
//     class B :


int main()
{
    vector<int> test_vector = {1, 2, 3, 4, 5, 6};

    for ( vector<int>::iterator it = test_vector.begin(); it !=test_vector.end(); ++it)//for문 두번째 방식
    {
        cout << *it << endl;
    }

    // iterator가 정의. begin(),end()
    // *it 역참조가 가능해야 한다.
    for (auto v : test_vector) //세번째 방식 모던 c++
    {
        cout << v << endl;
    }

    for (auto &v : test_vector) // 컨테이너의 값을 변경
    {
        cout << v << endl;
    }

    for (const auto v : test_vector) //메모리 효율적, 값 참고할때
    {
        cout << v << endl;
    }
    return 0;
}