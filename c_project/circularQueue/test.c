#include <stdio.h>
#include "circularQueue.h"

void test()
{
    Queue q;

    init(&q);
    printf("Queue Initialization\n");
    printf("Queue size : %d\n", q.size);
    int i = 0;
    while (!isFull(&q)) {
        enQueue(&q, i);
        i++;
    }

    printf("Till now, we did EnQueue %d element.\n", q.size);
    printf("Queue size : %d\n", q.size);
    printf("Full ?: %d\b", isFull(&q));

    printf("Now, we will DeQueue %d elements.\n", q.size);
    Element e;
    while(!isEmpty(&q)) {
        enQueue(&q, i);
        i++;
    }
}