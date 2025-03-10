// 10짜리 배열을 int로 만들어서 랜덤(0~100) 합을 구해서 프린트하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int arr[10],sum=0;
    srand(time(NULL));
    //배열에 값을 넣기
    for(int i=0;i<10;i++)
    {
        arr[i] =rand() % 101;
        sum+=arr[i];
    printf("%d 배열을 %d입니다.\n",i,arr[i]);
    }
    printf("배열의 합은 %d입니다.\n",sum);
    return 0;
}