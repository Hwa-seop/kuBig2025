#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int i;
    struct hostent *host;
    struct sockaddr_in addr;

    if (argc != 2)
    {
        printf("사용법: %s <IP>\n", argv[0]);
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // 핵심 수정: .s_addr 주소를 명시적으로 넘김
    host = gethostbyaddr((const void *)&addr.sin_addr.s_addr, sizeof(addr.sin_addr.s_addr), AF_INET);
    if (!host)
        error_handling("gethostbyaddr() 에러");

    printf("공식 이름: %s\n", host->h_name);

    for (i = 0; host->h_aliases[i]; ++i)
        printf("별칭 %d: %s\n", i + 1, host->h_aliases[i]);

    printf("주소 타입: %d\n", host->h_addrtype);

    for (i = 0; host->h_addr_list[i]; ++i)
    {
        struct in_addr *addr_ptr = (struct in_addr *)host->h_addr_list[i];
        printf("주소 %d: %s\n", i + 1, inet_ntoa(*addr_ptr));
    }

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
