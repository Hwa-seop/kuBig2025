#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned long milliseconds = 0;
// void calcmilli(void);
//{
// 계산하는 코드
//    ++milliseconds;
//}
ISR(TIMER0_OVF_vect)
{
    ++milliseconds;
}
void timer0_init(void)
{
    TCCR0 = _BV(CS01) | _BV(CS00);
    TCNT0 = 6;
    TIMSK |= _BV(TOIE0);
    sei();
}

int main()
{
    timer0_init();
    DDRC = 0x01;  // 비트 출력 설정
    PORTE = 0xFF; // 풀업 설정

    unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 20;
    unsigned char lastButtonState = 1; // uint8_t lastButtonState=1; 같은 의미
    unsigned char buttonState = 1;

    while (1)
    {
        uint8_t reading = PINE & _BV(PE0);
        // 버튼 상태 변경확인
        if (reading != lastButtonState)
        {
            lastDebounceTime = milliseconds;
        }
        // 디바운스 시간 경과확인
        if ((milliseconds = lastDebounceTime) > debounceDelay)
        {
            // 실제 버튼 상태 업데이트
            if (reading != buttonState)
            {
                buttonState = reading;

                if (buttonState == 0)
                {
                    PORTC ^= _BV(PC0);
                }
            }
        }

        lastButtonState = reading;
    }
    return 0;
}