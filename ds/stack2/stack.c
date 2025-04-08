#include <stdio.h>

int stack[100];
int tos;  //top of stack

void push(int data) //fuction. definition
{
    stack[tos]=data;
    tos++;
}

int pop(void)
{
    tos--;
    return stack[tos];
}
