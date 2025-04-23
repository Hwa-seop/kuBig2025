#include <iostream>

void swapValue(int va, int vb);
void swapPointer(int *pa, int *pb);
void swapReference(int &ra, int &rb);

int main()
{
    int a = 100, b = 200;
    std::cout << "[origin]a = " << a << ", b = " << b << std::endl;

    swapValue(a, b);
    std::cout << "[value] a = " << a << ", b= " << b << std::endl;

    swapPointer(&a, &b);
    std::cout << "[reference] a= " << a << ", b= " << b << std::endl;

    int c = 300;
    // int &r = c;
    int &r = c;
    std::cout << "[origin] c = " << c << ", &r = " << r << std::endl;

    r = 400;
    std::cout << "[change R] c = " << c << ", &r = " << r << std::endl;

    c = 500;
    std::cout << "[change C] c = " << c << ", &r = " << r << std::endl;

    return 0;
}

void swapValue(int va, int vb)
{
    int tmp = va;
    va = vb;
    vb = tmp;
}
void swapPointer(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
void swapReference(int &ra, int &rb)
{
    int tmp = ra;
    ra = rb;
    rb = tmp;
}
