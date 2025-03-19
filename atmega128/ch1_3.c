#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        unsigned char led_data = 0x00;
        led_data=0x01;
        int direction=0;
        DDRC = 0x0F;
        while(1)
        {
            while(1)
            {
                if(led_data>=0x0F)
                    direction=0;
                if(led_data==0)
                {
                    direction=1;
                    led_data=1;
                }
                if(direction)
                    led_data>>=1;
                else
                    led_data<<=1;
                    
                PORTC=led_data;
                _delay_ms(500);    
            }
        }
    }
}