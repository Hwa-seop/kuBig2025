// pmw 설정 fast pwm,timer3,COM3A
// FND 설정
// 버저를 이용한 프로그램
// 버튼 인터럽트로 활성화 PE4,5,6,7
// 버튼에 맞는 소리를 2초동안 출력합니다. 2초후에는 무음이 되어야합니다.
// FND에 버튼이 눌린 번호를 출력합니다.

#include <avr/io.h>
#include <util/delay.h>

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
uint8_t piano = 0;

int main()
{
    // 부저 핀 출력
    DDRB = _BV(PB7);

    // 버튼 입력 (PD2), 내부 풀업 저항 사용
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // 타이머 설정 (Fast PWM, 분주비 1)
    TCCR1A = _BV(COM1C1) | _BV(WGM11);
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);

    while (1)
    {
        // 버튼이 눌렸는지 확인 (LOW일 때 눌림)
        if (!(PIND & (1 << PD2)))
        {
            // 소리 설정
            ICR1 = 14745600 / doReMi[piano];
            OCR1C = ICR1 / 2;

            _delay_ms(300); // 음 재생 시간
            OCR1C = 0;       // 소리 끔

            piano++;
            if (piano > 7)
                piano = 0;

            // 디바운싱 + 버튼 뗄 때까지 대기
            while (!(PIND & (1 << PD2)))
                _delay_ms(10);
        }
    }

    return 0;
}
