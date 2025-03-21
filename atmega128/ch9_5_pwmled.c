#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0x00;
    DDRB |=_BV(PB4);  // OC0 -PB4번 출력 설정

    TCCR0 = _BV(WGM00) | _BV(WGM01) | _BV(COM01)| _BV(CS01); //clock  select 8 prescalse
    //fast PWM이다. compare -> clear
    //16MHz / 8 ->>>2Mhz /255: 7845hz duty cycle
    uint8_t brightness=0;
    int8_t delta=1;

    while (1)
    {
        OCR0 = brightness; // 0~255 -> 이 숫자로 Compar가 일어남.
        _delay_ms(10);
        brightness += delta;
        if (brightness == 0 || brightness == 255)
        {
            delta = -delta;
        }
    }
}
