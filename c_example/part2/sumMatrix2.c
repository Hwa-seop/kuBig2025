//[3][4] 배열을 만들어서 모두 더하고 출력해라
#include <stdio.h>
int main(void)
{
    int mad[3][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1000}};
    int total=0;
    for(int i=0;i<3;i++){
         for(int j=0;i<4;i++){
            total+=mad[i][j];
         }
    }
printf("total: %d\n",total);
return 0;
}