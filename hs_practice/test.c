#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp = fopen("test.txt", "w");
    fputs("Hello, world!\n", fp); // 문자열을 파일에 씀
    fclose(fp);
    
    fp = fopen("test.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp); // 파일에서 한 줄 읽음
    printf("읽은 문자열: %s", buffer);
    fclose(fp);
    
}