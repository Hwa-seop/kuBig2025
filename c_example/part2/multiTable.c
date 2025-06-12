//구구단 출력
#include<stdio.h>

int main(void)
{
    for(int i=2;i<10;i++)
    {
        printf("----------%d단 입니다------------\n",i);
        for(int j=1;j<10;j++)
            printf("%d * %d = %d\n",i,j,i*j);
}
return 0;
}