///난수를 이용해서 1~6까지 숫자를 만들기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int dice[30];
    srand(time(NULL));
    //배열에 값을 넣기
    for(int i=0;i<30;i++)
    {
        printf("%ld\n",time(NULL));
        dice[i] =rand() % 6 + 1;
    }
    //각 배열을 변경->10을 곱하기
    for(int i=0;i<30;i++)
    {
        dice[i]*=10;
        printf("%d, ",dice[i]);
        printf("%p \n",&dice[i]);//주소값출력 %p

    }
    printf("\n");
    
    return 0;
}