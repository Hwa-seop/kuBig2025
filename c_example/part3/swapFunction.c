#include<stdio.h>
void swap(int *pA,int *pB);

int main(void)
{
    int a,b;
    a=100;
    b=300;
    printf("a : %d \tb: %d\n",a,b);
    swap(&a,&b);
    printf("a : %d \tb: %d",a,b);
    return 0;
}
    void swap(int *pA,int *pB)
{
    int temp=*pA;
    *pA=*pB;
    *pB=temp;
      
}

