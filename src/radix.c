#include "../include/radix.h"
#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void radix_sort(int array[], int size){
    queue q[10];
    int i, j, cont;

    for(i = 0; i < 10; i++){
        q[i] = queue_create();
    }

    int largest = 0;
    int digit = 1;

    for(i = 0; i < size; i++){
        if(array[i] > largest){
            largest = array[i];
        }
    }

    cont = 1;
    while(largest/digit > 0){
        printf("\n\nTabela: ");

        for(i = 0; i < size; i++){
            printf("%d ", array[i]);
            enqueue(q[(array[i]/digit) % 10], array[i]);
        }

        printf("\n\nIteracao %d: %dª distribuicao\n\n", cont, cont++);

        for(i = 0; i < 10; i++){
            printf("Fila %d:\t", i);
            queue_dump(q[i]);
        }

        i = j = 0;
        
        while(j < 10){
            if(!queue_empty(q[j])){
                array[i++] = dequeue(q[j]);
            }

            else{
                j++;
            }
        }

        digit *= 10;

        printf("\n\nTabela: ");

        for(i = 0; i < size; i++){
            printf("%d ", array[i]);
        }
    }

    printf("\n");
}