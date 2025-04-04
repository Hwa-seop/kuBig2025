// 스위치 1,2,3 을 이용해서 
// 1->R 색 변화
// 1->G 색 변화
// 1->B 색 변화
// 스위치를 오래누르면(0~1초)->(0~4095)높은 값으로 변화 할 수 있게 만들기
// 스위치를 누르고 떼면 ->FND에 숫자 출력(0~1)초-> (00~99) ||| ms->10ms단위

#include <wiringPiI2C.h>
#include <wiringPi.h>
#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

void i2C_init(int fd, int freq);


int main(void)
{
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); //50hz
    // 프리스케일 값= (오실레이터 주파수 / (4096*원하는 주파수))-1
    // 2500000 / (4096 * 0x79+1)) =50.028817
    while (1)
    {
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, 0);     // 빨간색
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, 0); // 초
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, 0); // 파

        // 빨간색
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 4095);
        delay(300);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
        delay(300);

        // 초
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 4095);
        delay(300);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
        delay(300);

        // 파
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 4095);
        delay(300);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);
        delay(300);
    }
    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
    delay(10);                                                  // 리셋 후 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 60Hz 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);
}
