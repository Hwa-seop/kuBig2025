#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
volatile uint8_t timeS = 0x01; 
volatile int8_t fndFlag=0, edgeFlag=0;

int main(void)
{
    DDRA = 0xFF;  // FND led 출력 설정
    DDRE=0x00;

    TCCR3A = 0x00; 
    TCCR3B = 0x45; // 4:상승 엣지 캡처 트리거 설정, 5:분주비 1024 설정

    ETIMSK |= _BV(TICIE3); 
    ETIFR |=_BV(ICF3);
    sei();  // 전역 인터럽트 허용
    PORTA =numbers[0];
    while (1)
    {
        if (fndFlag)
        {
            if (timeS > 10)
                timeS = 10;
            PORTA = numbers[timeS];
            fndFlag = 0;
        }
    }
    return 0;
}

// Timer3 오버플로우 인터럽트
ISR(TIMER3_CAPT_vect)
{
    cli();
    uint16_t count_check;

    if(edgeFlag==0)
    {
        TCCR3B=0x05; //분주비 1024
        TCNT3=0;
        ICR3 =0; // 캡쳐 카운트 데이터
        edgeFlag=1;
    }else{
        TCCR3B=0x45; //4:상승 엣지 캡처 트리거 설정, 5:분주비 1024 설정
        count_check=ICR3;
        timeS=count_check/1440; // 0.1초단위
        fndFlag =1;
        edgeFlag =0;
    }

    sei();
}
