#include<stdio.h>

union student
{
    int num;
    double grade;

};

int main(void)
{
    union student s1={315};
    printf("학번: %d",s1.num);
    s1.grade=4.4;
    printf("학점: %.1lf",s1.grade);

}
