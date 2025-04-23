#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Task
{
    public:
        string name;
        int priority;

        //other 대신 rhs(right hand side),lhs(left) -> 변수 나타낼때 방향에 따라 나타냄
        bool operator<(const Task& rhs) const{
            return priority >rhs.priority;//오름차순
        }
};
int main()
{
    priority_queue<Task> scheduler;

    scheduler.push({"Email team", 1});
    scheduler.push({"Fix bug", 3});
    scheduler.push({"Write report", 2});

    cout<<"작업 처리 순서"<<endl;

    while(!scheduler.empty()){
        Task t = scheduler.top();
        scheduler.pop();
        cout<<t.name<<" 우선순위"<<t.priority<<endl;

    }

    return 0;
}
