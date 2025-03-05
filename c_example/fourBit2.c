//볼드,이탈릭,쉐도우,언더라인을 표현하는 변수를 만들어라.
//비트연산
#include<stdio.h>
// 볼드 1자리 비트 0b00000001
// 이탈릭 2자리 비트 0b00000010
// 쉐도우 3자리 비트 0b00000100
// 언더라인 4자리 비트 0b00001000
// 볼드 이면서 언더라인 0b0001001
#define BOLD 0x01 //1
#define ITALIC 0x02  //#define ITALIC (0x01<<1),2
#define SHADOW (0x01<<2)// 4
#define UL     (0x01<<3) //8

void printAttribute(unsigned char attr);

int main(void)
//
{
    unsigned char attr;  //8bit 8개의 속성
    attr= attr^attr;  // 무조건 0으로 바꿔줌, 값을 초기화 하기 위해서 사용
    attr=attr | BOLD;
    printAttribute(attr);
    attr=attr|(ITALIC | SHADOW);
    printAttribute(attr);
    attr=attr&(~BOLD);
    printAttribute(attr);
    return 0;
}
/* 방법1.
void printAttribute(unsigned char attr)
{
    printf("BOLD: %d\n",!(~(attr|~BOLD)));
    printf("ITALIC: %d\n",!(~(attr|~ITALIC)>>1));
    printf("SHADOW: %d\n",!(~(attr|~SHADOW)>>2));
    printf("UL: %d\n",!(~(attr|~UL)>>3));
    printf("------------------------------\n");
}
*/

void printAttribute(unsigned char attr)
{
    printf("BOLD: %d\n",(attr&BOLD));
    printf("ITALIC: %d\n",(attr&ITALIC)>>1);
    printf("SHADOW: %d\n",(attr&SHADOW)>>2);
    printf("UL: %d\n",(attr&UL)>>3);
    printf("------------------------------\n");
}