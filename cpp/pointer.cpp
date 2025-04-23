#include <iostream>

int main()
{
    int a = 0x12345678;
    char *p = reinterpret_cast<char *>(&a);

    printf("0x%x\n", *p);
    return 0;
}
