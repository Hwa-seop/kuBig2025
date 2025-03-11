#include<stdio.h>
#include<string.h>

int main(void)
{
    const char *str1="hello, wolrd";
    char str2[]="stack char array";
    int str1len =strlen(str1);
    int str2len =strlen(str2);
    printf("strlen : %d, strlen : %d\n",str1len,str2len);
    
    char str3[30];
    strcpy(str3,str1); //a,b 일때 a에다가 b를 복사하여 붙임
    str3[0]='H';
    printf("%s\n",str3);

    if(strcmp(str1,str3)==0)
    {
        printf("두 문자열 str1,str3는 같다. \n");
    }else
    printf("두 문자열은 다르다. %d \n",strcmp(str1,str3));
    // 두문자열을 비교하고 다른 부분의 아스키 코드값 차를 반환한다.

    strcat(str3,str2);
    printf("%s \n",str3);
    




    return 0;
}


