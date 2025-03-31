// SHT 5초 마다 한번씩 온습도 측정 timer0를 써서 5초주기를 계산.
//EEPROM 에 주소는 0100번 온도, 0200번 습도
// SHT에서 측정 실패는 error 성공 시에만 EEPROM 에 저장
// INT4번 써서(스위치를 누르면) EEPROM에 데이터를 읽어서 UART로 출력

#include "SHT2x.h"
#include "TWI_driver.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void printf_2dot1(uint8_t sense, uint16_t sense_temp);

uint16_t temperatureC, humidityRH;

int main(void)
{
    uint8_t switch_flag = 0;

    DDRA = 0xFF;    // LCD
    DDRE &= ~(1 << PE4); // PE0 입력
    PORTE |= (1 << PE4); // 풀업

    Init_TWI();
    lcdInit();
    SHT2x_Init();
    nt16 sRH;
    nt16 sT;
    uint8_t error;
    
while(1){
    if (!(PINE & (1 << PE4)))
    {
        switch_flag = 1;
    }

    while(switch_flag)
    {
        error |= SHT2x_MeasureHM(HUMIDITY, &sRH);
        error |= SHT2x_MeasureHM(TEMP, &sT);
        temperatureC = SHT2x_CalcTemperatureC(sT.u16) * 10;
        humidityRH = SHT2x_CalcRH(sRH.u16)*10;

        if(error==SUCCESS)
        {
            lcdGotoXY(0,0);
            printf_2dot1(TEMP,temperatureC);
            lcdGotoXY(0,1);
            printf_2dot1(HUMIDITY,humidityRH);
        }
        else
        {
            lcdGotoXY(0,0);
            lcdPrintData("Temp: --.-C",12);
            lcdGotoXY(0,1);
            lcdPrintData("Humi: --.-%",12);

        }
        _delay_ms(5000);
        lcdClear();

    }
}
    return 0;
}

void printf_2dot1(uint8_t sense, uint16_t sense_temp)
{
    uint8_t s100,s10;
    if (sense == TEMP)
    {
        lcdPrintData(" Temp : ", 7);
        s100 = sense_temp / 100;         // 100의자리
        if(s100>0) 
            lcdDataWrite(s100+'0');
        s10 = sense_temp / 10 - s100 * 10; // 10의 자리
        if(s10>0)
          lcdDataWrite(s10+'0');
        lcdDataWrite('.');              // .프린트
        lcdDataWrite(sense_temp % 10 + '0'); // 1의 자리
        lcdDataWrite('C');               // C프린트

    
    }
    else if (sense == HUMIDITY)
    {
        lcdPrintData(" Humi : ", 7);
        s100 = sense_temp / 100;         // 100의자리
        if(s100>0) 
            lcdDataWrite(s100+'0');
        s10 = sense_temp / 10 - s100 * 10; // 10의 자리
        if(s10>0)
          lcdDataWrite(s10+'0');
        lcdDataWrite('.');              // .프린트
        lcdDataWrite(sense_temp % 10 + '0'); // 1의 자리
        lcdDataWrite('C');               // C프린트

    }
}