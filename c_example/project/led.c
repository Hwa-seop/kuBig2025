#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
    // RGB LED (공통 애노드 → LOW면 ON)
    DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
    PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2); // 처음엔 모두 OFF
    
    DDRE &= ~(1 << PE1);  // 버튼 입력 설정
    PORTE |= (1 << PE1);  // 풀업
    
    while (1)
    {
            // 빨강 ON
            PORTC = (1 << PC1) | (1 << PC2);  // 파랑/초록 OFF
            PORTC &= ~(1 << PC0);             // 빨강 ON
            _delay_ms(1000);

            // 파랑 ON
            PORTC = (1 << PC0) | (1 << PC2);
            PORTC &= ~(1 << PC1);
            _delay_ms(1000);

            // 초록 ON
            PORTC = (1 << PC0) | (1 << PC1);
            PORTC &= ~(1 << PC2);
            _delay_ms(1000);

            // 모두 OFF
            PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
        _delay_ms(1000);
    }
}