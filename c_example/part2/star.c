// 별표를 5줄 하나씩 늘어나는 모양을 출력하세요
// *
// **
// ***
// ****
// *****
// 별표를 5줄 피라미드 모양으로 출력하세요.
//     *
//    ***
//   *****
//  *******
// *********
#include<stdio.h>

int main(void)
{
    int num=1;
    for(int i=0;i<5;i++){
             for(int j=0;j<i+1;j++){
                printf("*");
            }
    printf("\n");
    }
    printf("------------------------------\n");

    for(int i=0;i<5;i++){ //줄의 개수
        for(int j=4;j>i;j--){
             printf(" ");
           }
        for(int k=0;k<num;k++)//별의 개수
        printf("*");
        num+=2;
    printf("\n");
    
}


     

return 0;
      
}