#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    scanf("%d", &size);

    // int array[size]; // ->이런 방식 C99(99년에 나온 C표준)
    int *pArr = (int *)malloc(sizeof(int) * size); // 할당된 공간의 시작 주소값이 넘어옴,malloc포인터는 반환값이 void*
    // pArr == NULL??
    
    for(int i=0;i<size;i++)
    {
        *(pArr + i) = i + 1; //pArr[i]=i+1;
        printf("%d ",*(pArr + i));
    }
    printf("\n");
    free(pArr);
    return 0;
}