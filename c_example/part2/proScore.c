//n(MAX)개의 숫자를 배열로 만들어서[랜덤] 
//MAXC 까지 평균을 소숫점 2자리까지 출력

//VLA(variable length array): 가변 길이 배열
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
#define MAXC 100

int main(void)
{
    int max_input;
    printf("배열의 길이를 넣으세요 : ");
    scanf("%d",&max_input);
    srand((unsigned int)time(NULL));
    int scores[max_input];   
    int sum=0;
    double average=0;
    for(int i=0;i<max_input;i++)
    {
    scores[i]=rand()% (MAXC+1);
    printf("%d ,",scores[i]);
    sum+=scores[i];
    }
    printf("\n");
    average=(double)sum/max_input;
    printf("평균은 : %.2f입니다.\n",average);
    
    return 0;
}

