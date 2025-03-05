#include<stdio.h>
//볼드,이탈릭,쉐도우,언더라인을 표현하는 변수를 만들어라.
//비트연산
// 볼드 1자리 비트 0b00000001
// 이탈릭 2자리 비트 0b00000010
// 쉐도우 3자리 비트 0b00000100
// 언더라인 4자리 비트 0b00001000
// 볼드 이면서 언더라인 0b0001001


int main(void)
//
{\
    unsigned char attr;  //8bit 8개의 속성
    attr= attr^attr;  // 모두 0
    attr=attr| 0b0000001;
    printf("attr: 0x%02x\n",attr);
    attr=attr|(0b00000010+0b00000100);
    printf("attr: 0x%02x\n",attr);
    attr=attr&(~0b0000001);
    printf("sttr:0x%02x\n",attr);

    return 0;
}