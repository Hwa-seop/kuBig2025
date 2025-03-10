// 랜덤한 수 0~100까지 20개 프린트
// 정렬 후 프린트
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}

/*
int compare(const int* a, const int* b) {
	return(*a - *b);
}
    

    int compare(const int* a, const int* b) {
        if (*a > *b) {
            return 1; //꼭 1이 아니라 양수이기만 하면 된다.
        }
        else {
            return -1; //음수는 자리를 바꾸지 않는다. 꼭 -1이 아니라 음수이기만 하면 된다.
        }
    }
*/

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
    qsort(nums,20,sizeof(nums[0]),compare);

printf("버블정렬 후: ");
for(int i=0;i<20;i++){
    printf("%d ",nums[i] );
}printf("\n");


}