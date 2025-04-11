#ifndef STACK_H
#define STACK_H
class Stack{ //typedef삭제:c++에서는 stuct 굳이 사용 x

private: //implementation
    int *pArr;
    int size;
    int tos;

public:     //interface
    // void initStack(int size);
    // void cleanupStack();
    Stack(int size);   //contructor
    ~Stack();          //destructor

    void push(int data);
    int pop();
};

 #endif 

 