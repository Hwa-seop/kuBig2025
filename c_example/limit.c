#include <stdio.h>
#include <limits.h>

void printHello();

int main(void)
{
    printHello();
    printf("char_bit: %d\n",CHAR_BIT);
    printf("char_max: %d\n",CHAR_MAX);
    return 0;
}

void printHello()
{
    printf("hello, world\n"); 

}

