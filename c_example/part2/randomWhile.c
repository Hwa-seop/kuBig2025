///두 난수(0~100)를 발생시켜서 비교하기
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main(void)
{
    int a,b,i;
    double num1,num2;

    while(true)
    {
        i++;
        srand((unsigned int)time(NULL) + i); // random 셋
        num1 = rand() / (double)RAND_MAX * 10;
        num2 = rand() / (double)RAND_MAX * 10;

        printf("0~100 사이의 랜덤한 숫자: %f\n",num1);
        printf("0~100 사이의 랜덤한 숫자: %f\n",num2);
        a=num1;
        b=num2;
        printf("%d > %d : %s\n",a,b, a>b?"true":"false");
        printf("%d < %d : %s\n",a,b, a<b?"true":"false");
        printf("%d == %d : %s\n",a,b, a==b?"true":"false");
        printf("%d != %d : %s\n",a,b, a!=b?"true":"false");
    if(a==b)
    break;
    }

    return 0;
    
}