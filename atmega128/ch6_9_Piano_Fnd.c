#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
volatile uint8_t playBuzzerOn = 0;
volatile uint8_t piano = 0;

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};

#define PWM_SETUP _BV(COM3A1) |_BV(WGM31);
//#define PWM_SETUP (_BV(COM3A1) | _BV(WGM31))
int main(void)
{
    DDRE=0x08; //PE3출력
    DDRA=0xFF; //FND 출력

    //타이머 세팅
    TCCR3A = PWM_SETUP;
    TCCR3B = 0x19;
    //_BV(WGM13) | _BV(WGM12) | _BV(CS00);
    
    //인터럽트 세팅
    EIMSK = 0xF0; 
    EICRB = 0xFF; 
    sei();

    while (1)
    {
        if (playBuzzerOn)
        {
            //스위치에 맞는 소리내기
            ICR3 = 14745600 / doReMi[piano];
            OCR3A = ICR3 / 2;
            TCCR3A = PWM_SETUP;
            PORTA=numbers[piano];

            _delay_ms(2000);
            TCCR3A = 0x00; // 버저 끄기
            PORTA=0x00;// FND 0ff
            playBuzzerOn = 0;
        }
    }
    return 0;
}
ISR(INT4_vect)
{
    cli(); 
    playBuzzerOn=1;
    piano=0;
    sei();
}
ISR(INT5_vect)
{
    cli(); //sei() 로 전역설정한걸 해제하는것, 인터럽트 중복 방지
    playBuzzerOn=2;
    piano=1;

    sei();
}
ISR(INT6_vect)
{
    cli(); //sei() 로 전역설정한걸 해제하는것, 인터럽트 중복 방지
    playBuzzerOn=3;
    piano=2;

    sei();
}
ISR(INT7_vect)
{
    cli(); //sei() 로 전역설정한걸 해제하는것, 인터럽트 중복 방지
    playBuzzerOn=4;
    piano=3;

    sei();
}
