#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD=_BV(PD4)|_BV(PD5); //출력설정,포트
    DDRB= _BV(PB5);
    //DDRE = 0X02; //RX(입력),TX(출력)1, SW0-3 입력
    uint8_t switch_flag = 0;
    DDRE = 0x00;
    DDRA = 0xFF;

    while(switch_flag)
    {

        PORTD = _BV(PD5); // M1 정회전
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);
        PORTD &= ~_BV(PD5); //-> OOFF
        PORTD = _BV(PD4); // M1 정회전
        PORTB = _BV(PB5); // M1 회전-반시계였음
        _delay_ms(2000);

    }
    return 0;
}