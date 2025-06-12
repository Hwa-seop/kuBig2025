//1~50까지 while로 출력하기
#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    int i=0;
    while(i!=10)
    {
        printf("%d 번 출력입니다.\n",i+1);
        i++;
    }
    return 0;
}