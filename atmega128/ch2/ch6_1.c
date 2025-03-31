#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t ledData=0x00;
volatile uint8_t timer1Cnt=0;

int main(void)
{
    DDRC = 0x0F; //1,2,3,4출력 설정

    TCCR1A=0x00;
    TCCR1B=0x01;
    TIMSK=0x04;
    
    sei();

    while(1)
    {
        if(timer1Cnt==255)
        {
            ledData++;
            if(ledData>0x0F)
            ledData=0;
            timer1Cnt++;
        }
        PORTC=ledData;

    }
    return 0;
}
ISR(TIMER1_OVF_vect)
{
    cli();
    timer1Cnt++;
}