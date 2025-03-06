#include<stdio.h>

int main(void)
{
    int num;
    printf("홀수짝수 구분하는 프로그램.\n");
    printf("숫자 입력 : ");
    scanf("%d",&num);
    int isOdd;
    isOdd=(num%2==1);
    printf("%d",isOdd);

    /*
    if(num%2==0)
    printf("짝수입니다.");
    else if(num%2==1)
    printf("홀수입니다."); 
    */
    return 0;
}