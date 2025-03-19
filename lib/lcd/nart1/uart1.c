#ifndef UART1_H
#define UART1_H

void uart1Init(void)
{
    UCSR0A |=_BV(U2X1);
    UCSR0B = 0x18; // Ob0001 1000 RX,TX enable
    UCSR0C = 0x06; // ob0001 0110 비동기, no Parity, 1stop bit

    UBRR0H = 0x00;
    UBRR0L = 0x07; // bps 설정: 115200bps
}

void uart1Transmit(char data)
{
    //;내일
}
unsigned char uart1Receive(void)
{
    uint8_t data;
    while((UCSR0A & 0x80) ==0 ) // 문자 버퍼에 있으면 내려가라
        ;

    return UDR0;
}
void uart1PrintString(char *str);
void uart1Print1ByteNumber(unsigned char n);
#endif //UART1_h