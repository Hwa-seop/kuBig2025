#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        DDRC = 0x0F;
         
        PORTC=0x08; 
        _delay_ms(500);
        PORTC=0x04; 
        _delay_ms(500);
        PORTC=0x02; 
        _delay_ms(500);
        PORTC=0x01; 
        _delay_ms(500);
        PORTC=0x02; 
        _delay_ms(500);
        PORTC=0x04; 
        _delay_ms(500);

    }

}