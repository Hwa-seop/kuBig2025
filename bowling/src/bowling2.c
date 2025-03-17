#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define FRAMES 10

// 볼링 점수를 저장하는 구조체
typedef struct {
    int rolls[21];  // 각 투구 점수 저장 (최대 21번)
    int currentRoll;
} BowlingGame;

// 함수 선언
void initGame(BowlingGame *game);
void roll(BowlingGame *game, int pins);
int scoreGame(BowlingGame *game);
void playGame(BowlingGame *game);
void displayScore(BowlingGame *game);

// 볼링 게임 초기화
void initGame(BowlingGame *game) {
    memset(game->rolls, 0, sizeof(game->rolls));
    game->currentRoll = 0;
}

// 볼링 핀 점수 입력
void roll(BowlingGame *game, int pins) {
    game->rolls[game->currentRoll++] = pins;
}

// 볼링 점수 계산
int scoreGame(BowlingGame *game) {
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < FRAMES; frame++) {
        if (game->rolls[rollIndex] == 10) { // 스트라이크
            score += 10 + game->rolls[rollIndex + 1] + game->rolls[rollIndex + 2];
            rollIndex += 1;
        } else if (game->rolls[rollIndex] + game->rolls[rollIndex + 1] == 10) { // 스페어
            score += 10 + game->rolls[rollIndex + 2];
            rollIndex += 2;
        } else { // 일반 점수
            score += game->rolls[rollIndex] + game->rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }
    return score;
}

// 볼링 게임 실행
void playGame(BowlingGame *game) {
    system(CLEAR_SCREEN);
    printf("🎳 볼링 게임을 시작합니다! 🎳\n");
    for (int frame = 0; frame < FRAMES; frame++) {
        int firstRoll, secondRoll = 0;

        printf("\n🔹 %d 프레임 - 첫 번째 투구: ", frame + 1);
        scanf("%d", &firstRoll);
        roll(game, firstRoll);

        if (firstRoll < 10 || frame == 9) { // 마지막 프레임은 3번까지 가능
            printf("🔹 %d 프레임 - 두 번째 투구: ", frame + 1);
            scanf("%d", &secondRoll);
            roll(game, secondRoll);
        }

        if (frame == 9 && (firstRoll + secondRoll >= 10)) { // 10 프레임 보너스 투구
            int bonusRoll;
            printf("🔹 보너스 투구: ");
            scanf("%d", &bonusRoll);
            roll(game, bonusRoll);
        }

        system(CLEAR_SCREEN);
        displayScore(game);
    }
}

// 점수판 출력
void displayScore(BowlingGame *game) {
    printf("\n🎳 현재 스코어 보드 🎳\n");
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    for (int i = 0, rollIndex = 0; i < FRAMES; i++) {
        printf("| %2d ", game->rolls[rollIndex]); // 첫 번째 투구
        if (game->rolls[rollIndex] == 10) { // 스트라이크
            printf("| X  ");
            rollIndex += 1;
        } else {
            printf("| %2d ", game->rolls[rollIndex + 1]); // 두 번째 투구
            rollIndex += 2;
        }
    }
    printf("|\n+----+----+----+----+----+----+----+----+----+----+\n");

    printf("\n총 점수: %d\n", scoreGame(game));
}

// 메인 함수
int main() {
    BowlingGame game;
    initGame(&game);
    playGame(&game);

    printf("\n🎉 게임 종료! 최종 점수: %d 🎉\n", scoreGame(&game));
    return 0;
}