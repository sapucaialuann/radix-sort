#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    node *next;
};

struct queue{
    node *beginning;
    node *end;
};

queue queue_create(){
    queue q = malloc(sizeof(queue));

    if(q == NULL){
        return NULL;
    }

    q->beginning = NULL;
    q->end = NULL;
}

void enqueue(queue q, int value){
    node *n = malloc(sizeof(node*));

    if(n == NULL){
        printf("Elemento não inserido");
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

int dequeue(queue q){
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

int queue_empty(queue q){
    return q->beginning == NULL ? 1 : 0;
}

void queue_dump(queue q){
    for(node *i = q->beginning; i != NULL; i = i->next){
        printf("%d", i->value);

        if(i->next != NULL){
            printf(", ");
        }
    }

    printf("\n");
}
