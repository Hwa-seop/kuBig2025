// 숫자 3개를 만드시오[랜덤]. (단 서로 다른 숫자) 0~9까지
// 숫자 3개를 입력 받으세요(scanf)

// 위치와 숫자가 같으면 strike+1
// 위치가 다르지만 숫자가 같으면 ball +1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int randomNumber[3];
    int num[3];
    int strike, ball;
    int attempts = 0;

    srand((unsigned int)time(NULL));

    // 사용자 입력 받기
    printf("숫자 3개 입력 (0~9, 중복X): ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }

    // 정답이 나올 때까지 반복
    do {
        strike = 0;
        ball = 0;
        attempts++;

        // 중복되지 않는 랜덤 숫자 3개 생성
        for (int i = 0; i < 3; i++) {
            randomNumber[i] = rand() % 10;
            for (int j = 0; j < i; j++) { // 중복 체크
                if (randomNumber[i] == randomNumber[j]) {
                    i--; // 중복이면 다시 생성
                    break;
                }
            }
        }

        // 스트라이크 & 볼 판정
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (num[i] == randomNumber[j]) {
                    if (i == j)
                        strike++; // 위치도 같으면 Strike
                    else
                        ball++;   // 숫자만 같으면 Ball
                }
            }
        }

        // 현재 랜덤 숫자와 결과 출력
        printf("[%d회차] 랜덤 숫자: %d %d %d -> %d Strike, %d Ball\n",
            attempts, randomNumber[0], randomNumber[1], randomNumber[2], strike, ball);

    } while (strike < 3); // 모든 숫자와 위치가 같아질 때까지 반복

    printf("모든 숫자가 일치했습니다! 총 시도 횟수: %d\n", attempts);

    return 0;
}

