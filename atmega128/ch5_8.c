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

    DDRC=0x0F; //1,2,3,4 출력 설정
    
    ADMUX=0x40; // ADC0 singel mode, 0번 채널3,3V 외부 기준 전압(AREF)
    ADCSRA =0xAF; // 10101111; ADC 허가,free running mode,Intterrupt en,
    // 128 분주비
    ADCSRA |= 0x40; // ADC 개시
    sei(); //전역 인터럽트 허용

    lcdGotoXY(0,0); //시작점
    char buf[16];
    uint8_t onTime,offTime;
    DDRC=0xFF;

    while (1)
    {
        lcdGotoXY(0,1);
        // lcdPrintData("\n \r LS:",12);
        sprintf(buf,"L: %u", adcResult);
        lcdPrintData(buf,strlen(buf));
        printf("CDS ADC_data : %u\r\n",adcResult);
        // 시간 연산
        onTime=(adcResult-100)/35;
        if(onTime<0)
            onTime=0;
        if(onTime>20)
            onTime=20;

        offTime=20-onTime+500;
        PORTA=0x0F; //켜지는 시간
        for(int i=0;i<onTime;i++)
        {
            _delay_ms(1);
            PORTC=0x00;
        }
        PORTA=0x00; 
        // 꺼지는 시간 딜레이
        for(int i=0;i<offTime;i++)
        {
            _delay_ms(1);
            PORTC=0xFF;
        }
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult= ADC; //0~1023
    sei();
}