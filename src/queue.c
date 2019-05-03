#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

queue* queue_create(){
    queue *q = malloc(sizeof(queue*));

    if(q == NULL){
        return NULL;
    }

    q->beginning = NULL;
    q->end = NULL;
}

void enqueue(queue *q, unsigned int value){
    node *n = malloc(sizeof(node*));

    if(n == NULL){
        printf("Value wasnt inserted");
        return;
    }

    n->value = value;
    n->next = NULL;

    if(q->end != NULL){
        q->end->next = n;
    }

    else{
        q->beginning = n;
    }

    q->end = n;
}

int dequeue(queue *q){
    if(q->beginning == NULL){
        return -1;
    }

    node *old = q->beginning;
    q->beginning = q->beginning->next;

    if(q->beginning == NULL){
        q->end = NULL;
    }

    int temp = old->value;
    free(old);
    
    return temp;
}

void queue_dump(queue *q){
    for(node *i = q->beginning; i != NULL; i = i->next){
        printf("%d -> ", i->value);
    }

    printf("NULL\n");
}