#include<stdio.h>

int main(void)
{

    double length,height;
    double area;

    printf("Enter triangle's length : ");
    scanf("%lf",&length);
    printf("Enter triangle's height : ");
    scanf("%lf",&height);
    area=length*height/2.0;
    printf("triangle's area is : %.1f",area);

    return 0;
}
