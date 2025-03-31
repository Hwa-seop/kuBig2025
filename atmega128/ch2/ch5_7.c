//uart를 이용해서 시리얼 통신으로 센서 값을 0.1 초 간격으로 출력하세요
// CDS ADC_data : xxxx

#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

volatile uint16_t adcResult=0;
int main()
{
    uart0Init();
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;

    ADMUX=0x40; // ADC0 singel mode, 0번 채널3,3V 외부 기준 전압(AREF)
    ADCSRA =0xAF; // 10101111; ADC 허가,free running mode,Intterrupt en,
    // 128 분주비
    ADCSRA |= 0x40; // ADC 개시
    sei(); //전역 인터럽트 허용

    lcdGotoXY(0,0); //시작점
    char buf[16];

    while (1)
    {
        lcdGotoXY(0,1);
        lcdPrintData("\n \r Light Sensor: ",12);
        sprintf(buf,"L: %u", adcResult);
        lcdPrintData(buf,strlen(buf));
        printf("CDS ADC_data : %u\r\n",adcResult);
        _delay_ms(500);
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult= ADC; //0~1023
    sei();
}