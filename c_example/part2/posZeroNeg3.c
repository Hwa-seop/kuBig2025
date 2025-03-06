// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
//  if else 구문으로
// printf 한번만 사용

#include<stdio.h>

int main(void)
{
    int num;
    scanf("%d",&num);
    printf("%d 숫자는 %s입니다.\n",num, num>0?"양수": num<0? "음수":"영");

    return 0;
}