//값으로 부른다(call by value),참조로 부른다(call by reference)
#include<stdio.h>
int f1(void);
void f2(int *pResult);

int main(void)
{
    int f1_result=f1();
    printf("f1의 반환결과는 : %d\n",f1_result);
    
    int f2_re;
    f2(&f2_re);
    printf("f2의 처리결과는 : %d\n",f2_re);
    return 0;
}
int f1(void)
{
    return 100;
}
void f2(int *pResult){
    *pResult =100;
}
