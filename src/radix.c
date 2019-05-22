#include "../include/radix.h"
#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void radix_sort(int array[], int size, int max_digits){
    // 10 filas
    queue q[10];
    /* i e j servirão para iteração. cont será a variável que indicará ao usuario em que passo o algoritmo está trabalhando. 
    largest será o maior número do array (no algoritmo generico, deve se saber o maior número do array para que saibamos 
    quantos digitos iremos trabalhar no maximo). digit vai ser a variável que indicará qual digito deverá ser trabalhado, funcionando
    como uma "máscara".
    */
    int i, j, cont = 1, largest = 0, digit = 1;

    // Aloca as filas no array de filas
    for(i = 0; i < 10; i++){
        q[i] = queue_create();
    }

    // busca o maior número 
    for(i = 0; i < size; i++){
        if(array[i] > largest){
            largest = array[i];
        }
    }

    // largest/digit > 0 ocorre quando digit se torna maior que largest (maior numero). Ou seja, ocorre quando digit possui mais digitos que largest
    while(largest/digit > 0){
        printf("\nTabela:\t");

        // itera a lista para dividir os elementos nas filas
        for(i = 0; i < size; i++){
            printf("%0*d\t", max_digits, array[i]);
            /* Aqui se enfileira o elemento atual da iteração. Deve-se pegar esse elemento e dividir pela "máscara de digito" 
            para que peguemos o digito necessário. O resto por 10 vai indicar em que fila ficará o elemento (fila dos numeros com
            digito 0 em x casa, ..., fila dos numeros com digito 9 em x casa)
            */
            enqueue(q[(array[i]/digit) % 10], array[i]);
        }

        printf("\n\nIteracao %d: %dª distribuicao\n\n", cont, cont);
        cont++;

        // Mostra a fila
        for(i = 0; i < 10; i++){
            printf("Fila %d:\t", i);
            queue_dump(q[i], max_digits);
        }

        // nessa iteração, i será responsável por ser o index do array, e j por ser o index do array de filas
        i = j = 0;
       
        // enquanto todas as filas não tiverem sido esvaziadas, ocorrerá o laço
        while(j < 10){
            /* até que a fila atual esteja vazia, um elemento será desenfileirado dele e enviado para o i de array, incrementando
            1 ao i para que outras posições do array sejam alocadas
            */
            if(!queue_empty(q[j])){
                array[i++] = dequeue(q[j]);
            }
            
            // Quando a fila estiver vazia, simplesmente passe para outra (até que a condição do while seja anulada)
            else{
                j++;
            }
        }

        /* Aumenta o digito que queremos trabalhar. Funciona como "máscara". ex: 1 representa o primeiro digito, 10 representa
        o segundo, 100 representa o terceiro, etc.
        */
        digit *= 10;

        printf("\nTabela:\t");

        for(i = 0; i < size; i++){
            printf("%0*d\t", max_digits, array[i]);
        }

        printf("\n");
    }
}
