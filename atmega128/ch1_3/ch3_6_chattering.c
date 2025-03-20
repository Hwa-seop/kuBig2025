#include <avr/io.h>
#include<util/delay.h>

int main()
{
    DDRC=0x01;   
    PORTE =0xFF; // 풀업 설정
    
    while(1)
    {
        _delay_ms(20); //디바운스 대기
        if(!(PINE &_BV(PE0)))
        {
            PORTC ^=_BV(PC0); // 버튼 반전   
            PORTC ^=_BV(PC1); // 버튼 반전   
            PORTC ^=_BV(PC2); // 버튼 반전   
            PORTC ^=_BV(PC3); // 버튼 반전   
            
            //버튼이 놓일 때 까지 대기
            while (!(PINE&_BV(PE0)))
            {
                _delay_ms(10);
            }
        }
    }
    return 0;
}