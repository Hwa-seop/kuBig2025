//gcc -fPIC -shared -o libplugin.so plugin.c
//file libplugin.so
//objdump -x libplugin.so
#include <stdio.h> //동적 로딩 관련 코드

void hello(){
    printf("안녕하세요! 저는 플러그인 입니다.\n");
}