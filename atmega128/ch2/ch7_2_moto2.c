#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5); // 출력설정,포트
    DDRB = _BV(PB5);  //M1_enable 핀

    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    ICR1 = 800;
    OCR1A = 560; //800번 카운트 하는데 560번까지 5V를 준다.

    while(1)
    {
        PORTD = _BV(PD5); // M1 정회전- 속도영향?
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);
        PORTD &= ~_BV(PD5); //-> OOFF
        PORTD = _BV(PD4); // M1 역회전
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);

    }
    return 0;
}