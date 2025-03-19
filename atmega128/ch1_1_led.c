#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        PORTC = 0x00;  // 0b00000000 LED 제어, 비트로 되어있음 
        _delay_ms(1000); //1초 대기
        PORTC = 0x0F; // 0b00001111, b=바이너리라는 뜻, 
        _delay_ms(1000); 
    
    }
}