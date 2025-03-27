#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC |= (1 << PC0);  // PC0를 출력으로 설정

    while (1)
    {
        // 부저 ON
        PORTC |= (1 << PC0);
        _delay_ms(1);  // 1ms ON

        // 부저 OFF
        PORTC &= ~(1 << PC0);
        _delay_ms(1);  // 1ms OFF

        // 이 ON/OFF 반복으로 약 500Hz의 사각파 생성 → 부저 울림
    }
}
