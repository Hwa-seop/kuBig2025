#include<stdio.h>

int main()
{
    int celsius;
    printf("Input cel temp: ");
    scanf("%d",&celsius);

    printf("celsius temp: %d \n",celsius);

    double fahr;
    fahr= 9.0/5.0*celsius+32;
    printf("fahr temp: %f \n",fahr);

    return 0;
}