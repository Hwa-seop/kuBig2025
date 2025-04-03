#include<stdio.h>
#include<wiringPi.h>

//gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

int main(void)
{
    wiringPiSetupGpio();// BCM 기준 gpio 핀, gpio사용하기위한
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(LED4,OUTPUT);
    while(1)
    {
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        digitalWrite(LED4,HIGH);
    }
    // pinMode(LED2,OUTPUT);
    // pinMode(LED3,OUTPUT);
    // pinMode(LED4,OUTPUT);
    printf("안녕하세요!");
    return 0;
}   

