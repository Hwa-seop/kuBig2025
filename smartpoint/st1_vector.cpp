#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "size: " << v.size() << endl;
    cout << "first: " << v.front() << endl;
    cout << "last: " << v.back() << endl;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    v.pop_back();
    v.erase(v.begin());

    for (auto x : v)
        cout << x << endl;
}
