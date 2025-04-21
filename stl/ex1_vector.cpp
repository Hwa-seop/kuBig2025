#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(11);
    v.push_back(111);
    v.push_back(1238);

    // cout << "v 의 첫번째 원소는 : " << v[0] << endl;
    // cout << "v 의 첫번째 원소는 : " << v[1] << endl;
    // cout << "v 의 첫번째 원소는 : " << v[2] << endl;

    auto it = v.begin() + 2;
    v.erase(it);
    v.at(0)=2; //원소레 접근해서 변경 

    // for문을 쓰는 첫 번째
    for (int i=0;i<v.size();i++)
    {
        cout << "v의 " << i + 1 << "번째 원소는 : " << v[i] << endl;
    }
    return 0;
}