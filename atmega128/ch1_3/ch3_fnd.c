#include <avr/io.h>
#include <util/delay.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
    int count = 0;
    srand(time(NULL));
    DDRA = 0xFF;

    while (1)
    {
        PORTA = numbers[rand() % 10];
        // count=(count+1)%10;

        _delay_ms(300);
    }
    return 0;
}