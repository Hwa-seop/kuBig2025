#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
//phys pins
#define LED1 16
#define LED2 24
#define LED3 25
#define LED4 1

int main(void)
{
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    write(fd, "23", strlen("23"));
    close(fd);

    fd = open("/sys/class/gpio/gpio23/direction", O_WRONLY); // open device에 접근하는
    write(fd,"out",strlen("out"));
    //-> gpio direction 설정 외부라이브러리 쓰지않은것
    close(fd);
    fd = open("/sys/class/gpio/gpio23/value", O_WRONLY);
    for(int i=0;i<5;i++)
    {
        write(fd, "1", strlen("1"));
        sleep(1);
        write(fd, "0", strlen("0"));
        sleep(1);
    }
    close(fd);
    fd=open("/sys/class/gpio/unexport",O_WRONLY);
    write(fd,"23",strlen("23"));
    close(fd);
    return 0;
}