#include "../include/radix.h"
#include "../include/queue.h"
#include <stdlib.h>

void filas_para_lista(no *filas[], int lista[]){
    int cursor = 0;
    for(int i = 0; i < 10; i++){
        if(filas[i] == NULL){
            continue;
        }
        while(filas[i] != NULL){
            no *aux = filas[i];
            lista[cursor] = filas[i]->dado;
            filas[i] = aux->prox;
            free(aux);
            cursor++;
        }
    }
}
