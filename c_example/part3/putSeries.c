#include<stdio.h>

int main(void)
{
    FILE *fp;
    fp=fopen("output.txt","a");
    if(fp==NULL)
    {
        printf("파일 열기 실패!");
        return 1;
    }
    putc('A',fp);
    putc('A',stdout);
    fputc('B',fp);
    fputc('B',stdout);
    //gets depreciate 지원 종료
    fputs("puts로 문자가 간다.\n", fp);
    fputs("puts로 문자가 간다.\n", stdout);
    
    fprintf(fp, "printf로 문자가 간다.\n");
    fprintf(stdout, "printf로 문자가 간다.\n");
    // EOF == -1; End Of File

    fclose(fp);
    return 0;
}