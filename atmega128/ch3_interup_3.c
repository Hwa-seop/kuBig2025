// 인터럽트로 FND를 점멸
// INT5 적용, phase 1>phase 2 or phase 2>>1
// phase 1: FND가 빠르게 상승하는 코드, 딜레이 ms 100
// phase 2: FND를 스위치 누르면 멈추게함. sw1번으로 제어한다.

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t timeStop = 0; // 인터럽트에서 쓸 변수

int main(void)
{
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
    int count = 0; //unit8_t count =0;

    DDRA = 0xFF; //FND
    EIMSK = 0x20; // 0b00100000
    EICRB = _BV(ISC50) |_BV(ISC51); 
    sei();

    while (1)
    {
        if(timeStop==0)
        {
        PORTA = numbers[count];
        count=(count+1)%10;
        }
        _delay_ms(100);
    }
    return 0;
}

ISR(INT5_vect)
{
    cli(); //sei() 반대 설정 SREG-->1 I unset ->0
    timeStop^=1;
    sei();
}