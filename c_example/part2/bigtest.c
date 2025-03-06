// 임이의 char를  scanf로 하나 받아서 대문자인지 소문자인지 출력하세요

#include<stdio.h>

int main(void)
{
    char ch;
    printf("문자를 하나 넣으시오: ");
    scanf("%c",&ch);
   // printf("%s",(65<=pos<97),"대문자","소문자");
    
    if('A'<=ch&&ch<'Z')
    printf("%c는 대문자 입니다.\n",ch);
    else if('a'<=ch&&ch<='z')  //else if(ch>=97&&ch<=122)
    printf("%c는 소문자 입니다.\n",ch);
    else
    printf("영문자가 아닙니다.\n");

    return 0;

}