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
        sleep(15);
        return 3;
    }
    else //부모
    {
        printf("자식 프로세스 ID: %d \n",pid);
        while(!waitpid(-1,&status,WNOHANG)); //자식 프로세스가 끝날때까지 블럭된다.
        {
            sleep(3);
            puts("sleep 3초.");
        }
        if(WIFEXITED(status))
            printf("자식이 보낸 메시지: %d \n",WEXITSTATUS(status));
        sleep(15);
        }
}
