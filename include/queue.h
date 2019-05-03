#ifndef QUEUE_H
#define QUEUE_H

typedef struct node node;
typedef struct queue queue;

queue* queue_create();
void enqueue(queue *q, unsigned int value);
int dequeue(queue *q);
void queue_dump(queue *q);

#endif