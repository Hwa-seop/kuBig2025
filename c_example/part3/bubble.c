// 랜덤한 수 0~100까지 20개 프린트
// 정렬 후 프린트
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    int nums[20]={0};
    srand(time(NULL));
    printf("랜덤한 수:");

    for(int i=0;i<20;i++){
        nums[i]= rand()%101;
    }
    
    for(int i=0;i<20;i++){
        printf("%d ",nums[i] );
    }printf("\n");
    

//bubble sorting
    for(int i=20-1;i>=1;i--){
        for(int j=0;j<i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
}
printf("버블정렬 후: ");
for(int i=0;i<20;i++){
    printf("%d ",nums[i] );
}printf("\n");


}