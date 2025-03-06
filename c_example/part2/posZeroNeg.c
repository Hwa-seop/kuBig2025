// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
//  if else 구문으로
// printf 한번만 사용

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int num;
    if(argc<2)
    {
        printf("숫자입력: \n");
        return 0;
    }
    num=atoi(argv[1]);
    
    if(num>0)
    printf(" 양수입니다.\n");
    else if(num<0)
    printf(" 음수입니다.\n");
    else
    printf(" 제로입니다.\n");


    return 0;


  
}