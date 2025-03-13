#include<stdio.h>

enum season
{
    SPRING=1,
    SUMMER=2,
    FALL=4,
    WINTER=8
};

int main(void)
{
    enum season ss;
    char *pc=NULL;
    ss=SPRING;
   // ss=SPRING|SUMMER;
    switch (ss)
    {
    case SPRING:
        pc="inline";
        break;
    case SUMMER:
        pc="swimming";
        break;   
    case FALL:
        pc="trip";
        break;     
    case WINTER:
        pc="skiing";
        break;
    }
    printf("나의 레저 활동 => %s\n",pc);   
    
    return 0;
}