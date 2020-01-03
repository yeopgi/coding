#include "circularQueue.h"

void beforeExit()
{
    getchar();
}

void init(Queue *q) 
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isFull(Queue *q)
{
    return (q->size == MAX);
}

bool isEmpty(Queue *q)
{
    return (q->size = 0);
}

void enQueue(Queue *q, Element data)
{
    if(isFUll(q)) {
        printf("Error : Queue Full\n");
        exit(1);
    }

    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = data;
    q->size++;
}

Element deQueue(Queue *q)
{
    if(isEmpty(q)) {
        printf("Error : Queue Empty\n");
        exit(1);
    }

    Element e;
    e = q->queue[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return e;
}

Element peep(Queue *q)
{
    if(isEmpty(q)) {
        return NULL;
    }

    return q->queue[(q->front + 1) % MAX];
}



