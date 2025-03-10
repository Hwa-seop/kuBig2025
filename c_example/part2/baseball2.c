// 숫자 3개를 만드시오[랜덤]. (단 서로 다른 숫자) 0~9까지
// 숫자 3개를 입력 받으세요(scanf)

// 위치와 숫자가 같으면 strike+1
// 위치가 다르지만 숫자가 같으면 ball +1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[3];
    int num;
    int strike=0,ball=0;
    printf("숫자 3개 입력: ");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&num);
    }
    srand((unsigned int)time(NULL));
    printf("출력 숫자 : ");

    for(int i=0;i<3;i++)
    {
        randomNumber[i]=rand()%9;
        printf("%d ",randomNumber[i]);
    }

}