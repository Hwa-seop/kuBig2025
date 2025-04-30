#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void timeout_Callback(int sig);
void keycontrolCallback(int sig);
int main()
{  
    signal(SIGALRM,timeout_Callback);
    signal(SIGINT,keycontrolCallback);
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
void keycontrolCallback(int sig)
{
    if (sig == SIGINT)
        puts("CTRL+C pressed!!");
    alarm(2);
}
