#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    printf("name : %s", getenv("name"));
    printf("age : %s", getenv("age"));
    return 0;
}