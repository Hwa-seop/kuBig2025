#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int sumArray(int pArray[],int size);

int main(void)
{
    int nums[20]={0};   
    srand(time(NULL));
    for(int i=0;i<20;i++){
        nums[i]=rand()%101; //0~100까지 랜덤한 숫자 넣기
        printf("%d, ",nums[i]);
    }
    printf("\n");

    int sum=sumArray(nums,sizeof(nums)/sizeof(int));
    printf("sum: %d",sum);
    return 0;   
}

int sumArray(int pArray[],int size)//배열을 넘길떄 주소와 사이즈를 같이 넘겨야한다.
//int sumArray(int *Array,int size)// 이렇게 포인터 정의 해도 된다.

{   
    // int *arr=pArray;
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=pArray[i];
    return sum;
}
