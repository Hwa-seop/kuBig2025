#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t ledData = 0x01;  // 초기: 0001
volatile int8_t direction = 1;    // 1이면 왼쪽으로, -1이면 오른쪽으로

int main(void)
{
    DDRC = 0x0F;  // PC0~PC3 출력

    TCCR3A = 0x00; // Timer3 설정 (16bit, 분주비 256)
    TCCR3B = _BV(CS32);     // 분주비 256 설정
    ETIMSK |= _BV(TOIE3);  // Timer3 오버플로우 인터럽트 허용
    TCNT3 = 46786;          // 
    sei();  // 전역 인터럽트 허용

    while (1)
    {
        // 메인 루프는 비워도 됨 (인터럽트가 LED 제어)
    }
    return 0;
}

// Timer3 오버플로우 인터럽트
ISR(TIMER3_OVF_vect)
{
    TCNT3 = 46786;  
    PORTC = ledData;  // 현재 LED 출력
    if (direction == 1)
    {
        ledData <<= 1;
        if (ledData == 0x08)  // 끝까지 갔으면 방향 반전
            direction = -1;
    }
    else
    {
        ledData >>= 1;
        if (ledData == 0x01)
            direction = 1;
    }
}
