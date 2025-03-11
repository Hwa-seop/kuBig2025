#include<stdio.h>
#include<string.h>

int main(void)
{
    const char *str1="hello, wolrd";
    char str2[]="stack char array";
    int str1len =strlen(str1);
    int str2len =strlen(str2);
    printf("strlen : %d, strlen : %d\n",str1len,str2len);
   return 0;

}


