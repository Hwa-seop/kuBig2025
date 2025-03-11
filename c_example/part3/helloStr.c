// 문자열을 쓰는 두가지 방법
#include <stdio.h>

int main(void)
{
    const char *str1="hellow";// 첫번째 방법, 변화를 줄수없는 문자열
    char str2[]="hellow"; //두번째, 변화 가능
    char str3[]={'h','e','l','l','o','w','\0'}; //세번째
    char str4='h';

    printf("%s  %p\n",str1,&str1);
    printf("%s  %p\n",str2,&str2);
    printf("%s  %p\n",str3,&str3);
    printf("%c  %p\n",str4,&str4);

    str2[0]='H';
    printf("%s \n",str2);

    return 0;
}

