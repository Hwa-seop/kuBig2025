#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    // 첫 번째 문자 입력
    printf("첫 번째 문자를 입력하세요: ");
    ch = getc(stdin);
    while ((ch = getchar()) != '\n' && ch != EOF);
    //getchar();  // 버퍼에 남은 1 개행문자 제거
    printf("입력한 문자는 %c 입니다.\n", ch);

    // 두 번째 입력 (문자열)
    printf("두 번째 문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);  // gets() 대신 fgets() 사용
    printf("입력한 문자열은 %s입니다.\n", str);

    return 0;
}