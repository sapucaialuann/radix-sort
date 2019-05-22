#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    node *next;
};

struct queue{
    // Primeiro elemento da fila
    node *beginning;
    // Ultimo elemento
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
    
    // Se o final da fila não for nulo (ou seja, já tem um elemento na fila), então o elemento deve ser adicionado depois de end atual
    if(q->end != NULL){
        q->end->next = n;
    }

    // Caso end seja nulo, então não há elemento na fila. Então o inicio deve se tornar n
    else{
        q->beginning = n;
    }

    // atualiza end (que deve apontar pro novo elemento inserido)
    q->end = n;
}

int dequeue(queue q){
    // beginning nulo = sem elementos na fila
    if(q->beginning == NULL){
        return -1;
    }

    node *old = q->beginning;
    // inicio aponta pro proximo elemento a ele (independente do proximo ser nulo ou nao)
    q->beginning = q->beginning->next;

    // beginning nulo após mudar pro proximo elemento = fila vazia
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
