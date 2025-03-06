//100부터 10000까지 출력
#include<stdio.h>

int main(void)
{
    int sum=0;
    for(int i=100;i<10001;i++){
        sum+=i;
    }
    printf("100부터 10000까지의 합: %d \n",sum);

    return 0;
}