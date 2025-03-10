#include<stdio.h>

int main(void)
{
    int i=100;
    double d=3.14;

    void *p;

    p=&i; //p로 i 가리키기
    printf("p의 주솟값은 : %p \n",p);
    //printf("p의 값은: %d", *p); //void 포인터로는 바로 출력안됨.
    printf("p의 값은: %d\n", *(int*)p);

    p=&d;
    //*p=6.713;  void pointer의 역참조는 안된다.
    *(double*)p=6.173;// 참조하려면 이렇게 해야함.
    printf("p의 주솟값은 : %p \n",p);
    //printf("p의 값은: %d", *p); //void 포인터로는 바로 출력안됨.
    printf("p의 값은: %.3f\n", *(double*)p);


    return 0;
}