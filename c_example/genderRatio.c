#include<stdio.h>

int main(void)
{
    int man,woman;
    double sum=0, manRate,womanRate;
    printf("성별확인 프로그램입니다.\n");
    printf("남자 수: ");
    scanf("%d",&man);
    printf("여자 수: ");
    scanf("%d",&woman);

    sum=man+woman;
    //sum=(double)man+(double)woman;
    
    manRate=(man/sum)*100;
    womanRate=(woman/sum)*100;
    printf("남자의 수는 %d명이고 여자의 수는 %d명이다.\n",man,woman);
    printf("총 수는 %.f명\n남자의 비율은: %.2f 여자의 비율: %.2f",sum,manRate,womanRate);
    return 0;

}
