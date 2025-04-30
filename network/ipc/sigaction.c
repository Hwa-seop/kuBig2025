#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout_Callback(int sig);

int main()
{  
    // signal(SIGALRM,timeout_Callback);
    struct sigaction act;
    act.sa_handler=timeout_Callback;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGALRM,&act,0);

    alarm(2);

    for(int i=0;i<10;i++)
    {
        puts("wait ...");
        sleep(100);
    }
    return 0;
}

void timeout_Callback(int sig)
{
    if(sig==SIGALRM)
        puts("TIME out!!");
    alarm(2);
}

