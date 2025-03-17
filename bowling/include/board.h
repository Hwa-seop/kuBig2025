#ifndef BOARD_H
#define BOARD_H

#include "bowling.h"

void printBoard(Score *player);
void setScore(int frame, int bow, Score *player);
void setFrameScore(int frame, Score *player);

#endif