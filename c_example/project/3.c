#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "clcd.h"
#include "uart.h"

void ADC_Init(void)
{
    ADMUX = (1 << REFS0);  // AVCC 기준 전압
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // 분주비 64
}

uint16_t ADC_Read(uint8_t channel)
{
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

uint16_t read_avg_adc(uint8_t channel)
{
    uint32_t sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += ADC_Read(channel);
        _delay_ms(5);
    }
    return sum / 10;
}

int main(void)
{
    uart0_init();
    i2c_lcd_init();
    ADC_Init();

    DDRF &= ~(1 << PF2);  // PF2 (ADC2) 입력 설정

    while (1)
    {
        uint16_t adc_value = read_avg_adc(2); // PF2 (ADC2)
        double voltage = (double)adc_value * (5.0 / 1023.0);
        double moisture = (1.0 - (voltage / 5.0)) * 100.0;

        // 수분값 정규화 (20~90% → 0~100%)
        if (moisture < 20.0) moisture = 0;
        else if (moisture > 90.0) moisture = 100;
        else moisture = (moisture - 20.0) * (100.0 / 70.0);

        char line0[16];
        char line1[16];

        // 1행: 수분 상태 메시지
        if (moisture <= 60.0)
            snprintf(line0, sizeof(line0), "Water, please");
        else
            snprintf(line0, sizeof(line0), "Enough");

        // 2행: 수분 수치 (%)
        snprintf(line1, sizeof(line1), "Moist: %.1f%%", moisture);

        // LCD 출력
        i2c_lcd_string(0, 0, line0);  // 0행
        i2c_lcd_string(1, 0, line1);  // 1행

        // 시리얼 로그 출력 (디버깅용)
        printf("ADC: %d | V: %.2fV | Moisture: %.1f%%\r\n", adc_value, voltage, moisture);

        _delay_ms(1000);
    }
}
