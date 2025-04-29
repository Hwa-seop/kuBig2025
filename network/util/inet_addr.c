#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_addr(unsigned long conv_addr);

int main()
{
    const char *addr1="127.212.124.78";
    const char *addr2="127.212.124.256"; // 256 error
    struct sockaddr_in addr_inet,addr_inet2;

    unsigned long conv_addr=inet_addr(addr1);
    print_addr(conv_addr);

    conv_addr=inet_addr(addr2);
    print_addr(conv_addr);
    memset(&addr_inet, 0, sizeof(addr_inet));
    int ret=inet_pton(AF_INET,addr1,&addr_inet.sin_addr);
    if (ret)
    {
        printf("네트워크 인티저 addr: %#x \n", addr_inet.sin_addr.s_addr);
        printf("sockaddr 의 s_data : ");
        for (int i = 0; i < 14; ++i)
        {
            printf("%x\t", (unsigned char)((struct sockaddr *)&addr_inet)->sa_data[i]);
        }
        printf("\n");
        // printf("sockaddr 의 s_data : %#x \n", ((struct sockaddr *)&addr_inet)->sa_data);
    }
    char buffer[20];
    char *buffer_ptr;

    buffer_ptr = inet_ntoa(addr_inet.sin_addr);
    strcpy(buffer,buffer_ptr);
    printf("네트워크 형식(111.111.111.111)의 문자열 : %s \n",buffer);

    // //아래 버전으로 간략하게 가능!
    // buffer_ptr = inet_ntoa(addr_inet.sin_addr);
    // printf("네트워크 형식(111.111.111.111)의 문자열 : %s \n",inet_ntoa(addr_inet.sin_addr));

    addr_inet2.sin_addr.s_addr=htonl(0x10203040);
    buffer_ptr = inet_ntoa(addr_inet2.sin_addr);
    strcpy(buffer,buffer_ptr);
    printf("네트워크 형식(111.111.111.111)의 문자열 : %s \n",buffer);

    return 0;
}

void print_addr(unsigned long conv_addr)
{
    if(conv_addr==INADDR_NONE)
        printf("Error occured! \n");
    else
        printf("네트워크의 인트 addr: %#lx \n",conv_addr);
}
