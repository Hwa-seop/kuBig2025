// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
//  if else 구문으로
// printf 한번만 사용

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num;
    char * pos;
    printf("숫자를 넣으세요: ");
    scanf("%d",&num);

    if(num>0)
        pos="양수";sta
    else if(num<0)
    pos="음수";
    else
    pos="제로";

    printf("%d 숫자는 %s입니다.",num,pos);

    return 0;
}