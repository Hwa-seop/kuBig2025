#ifndef BOWLING_H
#define BOWLING_H


typedef struct
{
    int score[12][3];
    int frameScore[11];
    char name[10];
}Score;

void initScore(Score*player, const char iname[]);
void calScore(int *frameScore, const int(*score)[3]);
int getValidScore(int frame,int bow,int prevScore);
void playGame(Score *player,int i);
void playGame10Frame(Score *player);

#endif

