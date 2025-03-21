#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
volatile uint8_t timeS = 0x01;

int main(void)
{
    DDRA = 0xFF; // FND led 출력 설정
    DDRE = 0x00;

    TCCR1A = 0x00;
    TCCR1B = 0x05; // 5:분주비 1024 설정

    OCR1A = 14400;
    OCR1B = 28800;
    TIMSK = _BV(OCIE1A) | _BV(OCIE1B) | _BV(TOIE1);

    sei();
    PORTA = numbers[0];

    while (1)
    {
        PORTA = numbers[timeS];
        if (timeS > 10)
            timeS = 0;
    }
    return 0;
}

ISR(TIMER1_COMPA_vect) // ISR에서 cli(),sei()는 생략 가능하다
{
    timeS++;
}

ISR(TIMER1_COMPB_vect)
{
    timeS--;
}

ISR(TIMER1_OVF_vect)
{
    cli();
    timeS++;
    sei();
}