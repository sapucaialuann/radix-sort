#ifndef QUEUE_H
#define QUEUE_H

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct queue{
    node *beginning;
    node *end;
} queue;

queue* queue_create();
void enqueue(queue *q, int value);
int dequeue(queue *q);

#endif