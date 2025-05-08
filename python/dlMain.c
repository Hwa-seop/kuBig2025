// gcc -o main dlMain.c -ldl
#include <stdio.h>
#include <dlfcn.h> // 따로 정적 링크가 필요하다 -ldl

int main()
{
    void *handle;
    void (*hello_func)();
    printf("main 프로그램 시작!!!\n");
    // getchar();
    handle=dlopen("./libplugin.so", RTLD_LAZY);
    hello_func = dlsym(handle,"hello");
    hello_func(); // 플러그인 실행.
    dlclose(handle);
    

    return 0;
}
