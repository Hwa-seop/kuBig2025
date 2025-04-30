#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid=fork();
    int status;

    if(pid==0) //자식1
    {
        return 3;
    }
    else //부모
    {
        if(pid==0) //자식2
        {
            exit(7);
        }
        else //부모
        {
            printf("자식 프로세스 ID: %d \n",pid);
            wait(&status); //자식 프로세스가 끝날때까지 블럭된다.
            if(WIFEXITED(status))
                printf("자식1 보낸 메시지: %d \n",WEXITSTATUS(status));
            wait(&status);
            if(WIFEXITED(status))
                printf("자식2 보낸 메시지: %d \n",WEXITSTATUS(status));
            sleep(15);
        }
    }
}