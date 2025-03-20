#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        DDRC = 0x03;  //0011 0,1번을 출력모드로한다.
    //pinMode(0,OUTPUT);0을 1로 바꾸어 출력?
        PORTC = 0x0F; //1111 -> 0,1,2,3 번을 1(ON)->5V 출력시킴
        _delay_ms(500);

        PORTC=0x00; // 0000-> 0,1,2,3 번을 0(off)->0v출력시킴

    }

            //(violatile unit8_t *)(0x14)=0x03; 메모리 설정.플래쉬 메모리
            DDRC = 0x0F; 
            PORTC|= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3); 
            _delay_ms(500);
            PORTC|= (PC0>>1) | (PC1>>1) | (PC2>>1) | (PC3>>1); 
            _delay_ms(500);
            // 복합대입연산 : 상위 값은 그대로 두고 대입하는것만 바꾸고싶을때  
            /*
            PORTC |= _BV(PC0) |_BV(PC1)|_BV(PC2)|_BV(PC3) ;//비트변경
            _delay_ms(10);
            PORTC = 0b00000001;
            _delay_ms(10);
            */
}