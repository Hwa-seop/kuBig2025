#include <avr/io.h>
#include <util/delay.h>
#include "clcd.h"
#include "uart.h"

int main(void)
{
    uart0_init();
    i2c_lcd_init();
    DDRA &= ~(1 << PA0);  // PA1 입력

    PORTA |= (1 << PA0); // ← 내부 풀업 제거함

    while (1)
    {
        if ((PINA & (1 << PA0)))  // HIGH → 수분 부족
        {
            i2c_lcd_string(0, 0, "Water, please   ");
            printf("센서: HIGH → 물 필요\r\n");
        }
        else
        {
            i2c_lcd_string(0, 0, "Enough!!     ");
            printf("센서: LOW → 수분 충분\r\n");
        }
        _delay_ms(1000);
        //i2c_lcd_string(1, 0, "ATmega128        ");
    }
}
