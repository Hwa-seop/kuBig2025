#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t shiftFlag = 1; // 인터럽트에서 쓸 변수
// volatile 인터럽트 쓰려면 꼭 써야함

int main(void)
{
    uint8_t ledData = 0x01;

    DDRC = 0x0F; // 하위비트 4개 출력

    EIMSK = 0xA0; //->2진수로 0b10100000 ->INT5,INT7
    EICRB = 0xC8; // 0b110021000인터럽트 5는 하강 인터럽트 7은 상승
    // ->윗줄과 같은 의미 EICRB= _BV(ISC71)|_BV(ISC70) |_BV(ISC51);
    EIFR = 0xA0; // 플래그 클리어
    sei();

    while (1)
    {
        PORTC = ledData;
        if (shiftFlag == 1)
        {
            if (ledData == 0x08)
                ledData = 0x01;
            else
                ledData <<= 1;
        }
        else if (shiftFlag == 2)
        {
            if (ledData == 0x01)
                ledData = 0x08;
            else
                ledData >>= 1;
        }
        _delay_ms(100);
    }
}
ISR(INT5_vect)
{
    cli(); //sei() 반대 설정 SREG-->1 I unset ->0
    shiftFlag=1;
    sei();
}

ISR(INT7_vect)  //ISR==SIGNAL
{
    cli(); 
    shiftFlag=2;
    sei();
}
