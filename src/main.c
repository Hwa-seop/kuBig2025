#include <stdio.h>
#include <stdlib.h>
#include <libserialport.h>

#define BAUDRATE 115200  // 반드시 ATmega128 보드와 동일해야 함

void check_serial_ports();

int main() {
    struct sp_port *port;
    char *port_name = "/dev/ttyUSB0";  // 사용 중인 포트명으로 수정 (예: COM3, /dev/ttyUSB0 등)

    // 포트 열기
    if (sp_get_port_by_name(port_name, &port) != SP_OK) {
        fprintf(stderr, "포트 %s 찾을 수 없음\n", port_name);
        return 1;
    }

    if (sp_open(port, SP_MODE_READ) != SP_OK) {
        fprintf(stderr, "포트 %s 열기 실패\n", port_name);
        return 1;
    }

    // 시리얼 설정
    sp_set_baudrate(port, BAUDRATE);
    sp_set_bits(port, 8);
    sp_set_parity(port, SP_PARITY_NONE);
    sp_set_stopbits(port, 1);
    sp_set_flowcontrol(port, SP_FLOWCONTROL_NONE);

    printf("포트 %s 에 연결됨. 센서 데이터를 수신 중...\n\n", port_name);

    char buffer[256];
    while (1) {
        int bytes_read = sp_blocking_read(port, buffer, sizeof(buffer) - 1, 1000);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // 문자열 종료
            printf("%s", buffer);      // 수신한 데이터 출력
            fflush(stdout);
        }
    }

    sp_close(port);
    sp_free_port(port);
    return 0;
}
