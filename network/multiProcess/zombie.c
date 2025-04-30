#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid=fork();
    if(pid==0) //자식
    {
        puts("안녕, 나는 자식 프로세스야!!");
    }else //부모
    {
        printf("Chile Process ID: %d \n",pid);
        sleep(3);
        printf("test");

    }

    if(pid==0)
        puts("End chile process");
    else
        puts("End parenet process");
    
    return 0;
}