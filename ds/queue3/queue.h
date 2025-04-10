#ifndef QUEUE_H //헤더파일 중복 방지용 코드
#define QUEUE_H
#define QUEUESIZE 100

typedef struct queue{
    int array[100];
    int front;
    int rear;
}Queue;

void initQueue(Queue *pq);

void push(Queue *pq,int data);
int pop(Queue *pq);

#endif 