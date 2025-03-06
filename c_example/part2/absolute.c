#include<stdio.h>
#include<stdbool.h> //true,false 사용
int main(void)
{
//숫자입력
int num;
int state;
printf("숫자를 넣으세요: ");
scanf("%d",&num);

//절대값처리
if(num<0)
    state=false;
else
    state=true;
num=state?num:-num;
//숫자출력
printf("주어진 숫자의 절대값은 %d\n",num);
return 0;
}