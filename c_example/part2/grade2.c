//성적 출력 프로그램
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int score;
    if(argc<2)
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0;
    }
    score=atoi(argv[1]);
    switch(score/10)
    {
        case 10:
            printf("축하합니다. 100점입니다");
            break;
        case 9:
            printf("score: %d===B\n",score);
            break;
        case 8:
            printf("score: %d===C\n",score);
            break;    
        case 7:
            printf("score: %d===D\n",score);
            break;
        case 6:
            printf("score: %d===E\n",score);
            break;
        default:
            printf("슬퍼요ㅠㅠ.\n");
            break;
    }
    
    return 0;
}