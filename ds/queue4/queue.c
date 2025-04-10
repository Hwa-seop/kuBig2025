#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "queue.h"

void initQueue(Queue *pq,int size)
{
    pq->pArr = malloc(sizeof(int) * size);
    //pq->pArr!=NULL 체크
    assert(pq->pArr );//0이 아니다 생략 한것
    
    pq->size = size;
    pq->front = 0;
    pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, int data)
{
    // if (pq->rear == pq->size){
    //     fprintf(stderr, "queue is full.\n");
    //     exit(1);
    // }
    assert(pq->rear != pq->size);

    pq->pArr[pq->rear] = data;
    ++pq->rear;
}

int pop(Queue *pq)
{
    // if (pq->rear == pq->front){
    //     fprintf(stderr, "queue is empty.\n");
    //     exit(2);
    // }
    assert(pq->rear != pq->front);

    int i = pq->front;
    ++pq->front;
    return pq->pArr[i];
}
