#include"lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>

int main()
{
    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    unsigned char switch_flag=0;
    DDRE=0x00; // 8개의 핀을 모두 인풋
    PORTE = 0X00; // 출력, -풀업을 설정한다.
    DDRC =0x0F; //output
    //PINE
    while(1)
    {
        if(PINE >> 4)
        {
            switch_flag= PINE>>4; //0b1000 0b0100 
        }
        PORTC=switch_flag;
        snprintf(lcdBuffer,sizeof(lcdBuffer),"SW: 0x%02X, %c",switch_flag,'0'+switch_flag);
        lcdGotoXY(0,0); //lcd 시작위치 설정
        lcdPrint(lcdBuffer);
    }
    return 0;
}