#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_SIZE 256

int main()
{
    int pipe1_fd[2]; // 부모 -> 자식
    int pipe2_fd[2]; // 자식-> 부모
    pid_t pid;
    char buffer[BUFFER_SIZE];

    pipe(pipe1_fd);
    pipe(pipe2_fd);

    pid=fork();
    if(pid==0) //자식
    {
        close(pipe1_fd[1]); //부모 -> 자식 파이프의 쓰기 끝 닫기
        close(pipe2_fd[0]); //자식 -> 부모 파이프의 쓰기 끝 닫기
        read(pipe1_fd[0],buffer,BUFFER_SIZE); //대기
        printf("Chile received: %s\n",buffer);

        char *response="Hello from Child!";
        write(pipe2_fd[1],response,strlen(response)+1);

        close(pipe1_fd[0]);
        close(pipe2_fd[1]);
        exit(EXIT_SUCCESS);
    }

    else{
        close(pipe1_fd[0]);
        close(pipe2_fd[1]);
        char*message="Hello from Parent! ";
        write(pipe1_fd[1],message,strlen(message)+1);
        getchar();
        read(pipe2_fd[0],buffer,BUFFER_SIZE);
        printf("parent received: %s\n",buffer);

        close(pipe1_fd[1]); //부모 -> 자식 파이프의 쓰기 끝 닫기
        close(pipe2_fd[0]); //자식 -> 부모 파이프의 쓰기 끝 닫기
        wait(NULL);
        printf("자식 프로세스 종료.\n");
    }
    
    return 0;
}