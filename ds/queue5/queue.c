#include <stdio.h>
#include <stdlib.h>
#include <string.h> //mem 사용하기위해 
#include "assert.h"
#include "queue.h"

void initQueue(Queue *pq,int size,int eleSize)
{
    pq->pArr = malloc(eleSize * size);
    assert(pq->pArr );

    pq->eleSize = eleSize;
    pq->size = size;
    pq->front = 0;
    pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, const void *pData)
{
    assert(pq->rear != pq->size);

    // pq->pArr[pq->rear] = data;
    // memcpy(&pq->pArr[pq->rear],pData,pq->eleSize);
    memcpy((unsigned char *)pq->pArr + pq->rear * pq->eleSize,pData,pq->eleSize);
    ++pq->rear;
}

void pop(Queue *pq, void *pData)
{
    assert(pq->rear != pq->front);

    int i = pq->front;
    ++pq->front;
    // return pq->pArr[i];
    memcpy(pData, (unsigned char *)pq->pArr + i * pq->eleSize, pq->eleSize);
}
