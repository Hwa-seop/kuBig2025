#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
uint8_t piano = 0;

int main()
{
    DDRB = _BV(PB7);

    TCCR1A = _BV(COM1C1) | _BV(WGM11);
    TCCR1B = _BV(WGM13) |_BV(WGM12) | _BV(CS00) ;// ==_BV(0x19);, 분주비는 1, fast PWM
    //TCCR1C = 0x00;
    sei();
//5544553

    while (1)
    {
        ICR1=14745600/doReMi[piano]; // 주파수 만큼 dutycycle을 설정 하겠다.
        OCR1C = ICR1 / 2; //절반은 on
        piano++;
        if (piano > 7)
            piano = 0;
        _delay_ms(300);
    }
    return 0;
}
