#include<stdio.h>

int main(void)
{

    int length,height,area;

    printf("Enter triangle's length : ");
    scanf("%d",&length);
    printf("Enter triangle's height : ");
    scanf("%d",&height);
    area=length*height/2;
    printf("triangle's area is : %d",area);

    return 0;
}
