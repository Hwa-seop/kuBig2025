#include<stdio.h>
#include<wiringPi.h>

//gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22
//SW (4,17,27,22)
void SW_ISR1(void); 
void SW_ISR2(void); 
void SW_ISR3(void); 
void SW_ISR4(void); 

int main(void)
{
    wiringPiSetupGpio();// BCM 기준 gpio 핀, gpio사용하기위한
    int led[4] = {LED1, LED2, LED3, LED4};
    int sw[4] = {SW1, SW2, SW3, SW4};
    wiringPiISR(SW1,INT_EDGE_RISING,SW_ISR1); 
    //&SW_ISR이라고 해도된다.함수명은 주소값이기떄문에
    wiringPiISR(SW2,INT_EDGE_RISING,SW_ISR2); 
    wiringPiISR(SW3,INT_EDGE_RISING,SW_ISR3); 
    wiringPiISR(SW4,INT_EDGE_RISING,SW_ISR4); 

    for(int i=0;i<4;i++)
    {
        pinMode(led[i], OUTPUT);
        pinMode(sw[i], INPUT);
    }
    while(1)
    {
    }
    return 0;
}   

void SW_ISR1(void)
{
    static int flag_led=0;
    if(flag_led==0){
        printf("SWITCH 1 ON\n");
        digitalWrite(LED1,HIGH);
        flag_led=1;
    }else{
        printf("SWITCH 1 OFF\n");
        digitalWrite(LED1,LOW);
        flag_led=0;
    }
}
void SW_ISR2(void)
{
    static int flag_led=0;
    if(flag_led==0){
        printf("SWITCH 2 ON\n");
        digitalWrite(LED2,HIGH);
        flag_led=1;
    }else{
        printf("SWITCH 2 OFF\n");
        digitalWrite(LED2,LOW);
        flag_led=0;
    }
}
void SW_ISR3(void)
{
    static int flag_led=0;
    if(flag_led==0){
        printf("SWITCH 3 ON\n");
        digitalWrite(LED3,HIGH);
        flag_led=1;
    }else{
        printf("SWITCH 3 OFF\n");
        digitalWrite(LED3,LOW);
        flag_led=0;
    }
}
void SW_ISR4(void)
{
    static int flag_led=0;
    if(flag_led==0){
        printf("SWITCH 4 ON\n");
        digitalWrite(LED4,HIGH);
        flag_led=1;
    }else{
        printf("SWITCH 4 OFF\n");
        digitalWrite(LED4,LOW);
        flag_led=0;
    }
}