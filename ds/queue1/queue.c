#include <stdio.h>
int queue[100];
int rear;
int front;

void push(int data)
{
    queue[rear]=data;
    ++rear;
    // queue[rear++]=data;
}
int pop(void)
{
    int i=front;
    ++front;
    return queue[i];
    
}

int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("1st pop() : %d\n",pop());
    printf("2nd pop() : %d\n",pop());
    printf("3nd pop() : %d\n",pop());
    return 0;
}