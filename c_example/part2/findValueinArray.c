// 10개 짜리 배열을 랜덤으로 0~100 만들어서 int를 하나 scanf로 받는다.
// 같은 원소가 있는지 index가 몇 번째 인지 프린트 하시오.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[10];
    int value;

    srand((unsigned int)time(NULL));
    for(int i=0;i<10;i++)
    {
        randomNumber[i]= rand()%101;
        printf("%d ",randomNumber[i]);
    }
    printf("찾을 숫자를 입력하세여. : ");
    scanf("%d", &value);

    int i;
    for(i=0;i<10;i++){
        if(value ==randomNumber[i])
            break;
    }
    if(i<10)
        printf("%d 숫자를 찾았다. 인덱스는 %d이다.\n",value,i);
    else
        printf("%d 숫자를 못 찾았다.\n",value);
    return 0;
}


    
/*
int main(void)
{
    int num;
    int arr[10];
    srand((unsigned int)time(NULL));

    for(int i=0;i<10;i++){
        arr[i]=rand()%100;
        printf("%d\n",arr[i]);
    }
    printf("정수값 입력: ");
    scanf("%d",&num);
    int j=0;
    while(j>10){
        if (num==arr[j]){
            printf("%d",j);
        }
        else if(num!=arr[j])
            printf("값이 없다\n");
    j++;
}
   
    return 0;
}

*/