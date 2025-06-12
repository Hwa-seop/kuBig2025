//0~127 아스키 코드를 출력하세요.
// 이중 for 문으로 만드세요.
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
#include<stdio.h>

int main(void)
{
    int num=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<=15;j++){
        printf("%2d : %c ",num,(char)num);
        num++;
        }
        printf("\n");
}
return 0;
}