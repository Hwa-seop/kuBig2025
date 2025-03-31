#include <avr/interrupt.h>
#include <avr/io.h>
#include<util/delay.h>

volatile uint8_t ledData=0x00;
volatile uint8_t timer1Cnt=0;

int main(void)
{
    DDRC = 0x0F; //1,2,3,4출력 설정

    //TCCR1B=0x01;
    TCCR1A=0x00;
    TCCR1B = _BV(CS10) | _BV(CS12); // 분주비 1024 16Mhz 16000000/1024 = 15625hz -> 65535-15625 = 49,910
    TIMSK=_BV(TOIE1);
    TCNT1=49910;

    // TIMSK=0x04;
    sei();
    while(1)
    _delay_ms(100);
    return 0;
}
ISR(TIMER1_OVF_vect)
{
    cli();
    TCNT1=49910;
    PORTC=ledData;
    ledData++;
    if (ledData > 0x0F)
        ledData = 0;
}