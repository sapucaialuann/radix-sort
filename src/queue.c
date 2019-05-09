#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

/* struct node{
    unsigned int value;
    node *next;
};

struct queue{
    node *beginning;
    node *end;
};

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
}*/

void insere_final(no **header, int valor){
    no *aux = (no *) malloc(sizeof(no)),
       *fim = *header;
    
    aux->dado = valor;
    aux->prox = NULL;

    if(fim == NULL){
        *header = aux;
    }
    else{
        while(fim->prox != NULL)
            fim = fim->prox;
        fim->prox = aux;
    }
}

void remove_inicio(no **header){
    no *aux;
    aux = *header;
    aux = aux->prox;
    free(*header);
    *header = aux;
}

