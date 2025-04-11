#include <cstdio>
#include <iostream>
#include "stack.h"

int main() //c언어에서는 빈칸일경우 입력값 unknown,c++에서는 입력값이 없을때 void 를 써도되고 안써도된다.
{
    Stack s1(10), s2(100);
    // s1.initStack(10);
    // s2.initStack(100);

    s1.push(100);
    s1.push(200);
    s1.push(300);
    
    // s1.tos=0;

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2nd pop() : " << s1.pop() << std::endl; 
    std::cout << "s1 3rd pop() : " << s1.pop() << std::endl; 
    // 결과값이cout 사이드 이펙트로 화면상에 문자열로 출력된다.

    s2.push(900);
    s2.push(800);
    s2.push(700);
    std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
    std::cout << "s2 2nd pop() : " << s2.pop() << std::endl; 
    std::cout << "s2 3rd pop() : " << s2.pop() << std::endl; 

    // s1.cleanupStack();
    // s2.cleanupStack();
    return 0;
}
