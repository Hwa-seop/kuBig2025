///두 난수(0~100)를 발생시켜서 비교하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int a,b;
    double num1,num2;
    srand((unsigned int)time(NULL));//
        num1=rand()/(double)RAND_MAX*100;
        num2=rand()/(double)RAND_MAX*100;
    printf("0~100 사이의 랜덤한 숫자: %f\n",num1);
    printf("0~100 사이의 랜덤한 숫자: %f\n",num2);
    a=num1;
    b=num2;/*각각을 형변환 해주는게 아니라 int 선언된 변수에 값을 
    넣음으로서 자동으로 int로 바뀌게된다. */

    printf("%d > %d : %s\n",a,b, a>b?"true":"false");
    printf("%d < %d : %s\n",a,b, a<b?"true":"false");
    printf("%d == %d : %s\n",a,b, a==b?"true":"false");
    printf("%d != %d : %s\n",a,b, a!=b?"true":"false");



    return 0;
    
}