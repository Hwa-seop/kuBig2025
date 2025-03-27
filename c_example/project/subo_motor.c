#define F_CPU 16000000UL //CPU의 클럭 주파수 설정(16Mhz)
#include <avr/io.h>
#include <util/delay.h>

// 서보모터 초기화 (PE3 = OC3A)
void Servo_Init();
// 각도 → 펄스 폭 설정 (확장된 범위: 0도 ~ 180도 이상)
void Servo_Set_Angle(uint8_t angle);

int main(void)
{
    Servo_Init(); //타미어 세팅 및 PWM 초기화

    while (1)
    {
        Servo_Set_Angle(0);     // 0도 위치
        _delay_ms(1000);

        Servo_Set_Angle(180);   // 180도 위치
        _delay_ms(1000);
        // -------------------서보모터 수동 동작--------------
        // OCR3A=2000;
        // _delay_ms(1000);
        // OCR3A=3000;
        // _delay_ms(1000);
        // OCR3A=4000;
        // _delay_ms(1000);
        // OCR3A=3000;
        // _delay_ms(1000);
    //----------------------------------------------------------
    }
}
 
// 서보모터 초기화 (PE3 = OC3A)
void Servo_Init()
{
    DDRE |= (1 << PE3);  // PE3(OCA3) 출력 설정

    // Fast PWM, TOP = ICR3, 비반전 모드
    TCCR3A |= (1 << COM3A1) | (1 << WGM31);
    TCCR3B |= (1 << WGM33) | (1 << WGM32) | (1 << CS31);  // 분주비 8
    ICR3 = 40000;  // 20ms 주기 (0.5us * 40000 = 20ms)
}


// 각도 → 펄스 폭 설정 (확장된 범위: 0도 ~ 180도 이상)
void Servo_Set_Angle(uint8_t angle)
{
    if (angle > 180) angle = 180;
    uint16_t pulse = ((angle * 1000UL) / 180) + 2000;  // 대략 2.0ms~3.0ms (조금 확장)
    OCR3A = pulse;
}
