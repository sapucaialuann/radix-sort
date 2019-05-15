#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/radix.h"

int p(int x, int y){
    int r = 1;

    while(y > 0){
        r *= x;
        y--;
    }

    return r;
}

int main(){
    time_t t;
    int size, digits;

    printf("Digite o numero de posicoes do array\n");
    scanf("%d", &size);

    printf("Digite o numero maximo de digitos do numero\n");
    scanf("%d", &digits);

    int array[size], max = p(10, digits);

    srand((unsigned) time(&t));

    for(int i = 0; i < size; i++){
        array[i] = rand() % max;
    }

    radix_sort(array, size);

    return 0;
    // /*criando a lista de filas e atribuindo NULL para os cabecalhos */
    // no *filas[10];
    // for(int i = 0; i < 10; filas[i] = NULL, i++);

    // /* criando a lista dos valuees a ordenar */
    // int num_elem, digitos;
    // printf("Digite a quantidade de elementos da lista: ");
    // scanf("%d", &num_elem);
    
    // printf("Digite a quantidade maxima de digitos a considerar: ");
    // scanf("%d", &digitos);
    
    // int lista[num_elem];
    // srand((unsigned) time(NULL));
    // for(int i = 0; i < num_elem; i++){
    //     lista[i] = rand() % (int) potencia(10, digitos);
    // }
    // printf("\n\n");

    // //inserindo valuees nas filas correspondentes
    // for(int a = 0; a < digitos; a++){
    //     for(int i = 0; i < num_elem; i++){
    //         int aux = lista[i];
    //         for(int j = 0; j < a; j++){
    //             aux /= 10;
    //         }
    //         aux %= 10;
    //         insere_final(&filas[aux], lista[i]);
    //     }
    //     printf("\nPasso %d: ", a+1);
    //     for(int cursor = 0; cursor < num_elem; cursor++){
    //         printf("%d ", lista[cursor]);
    //     }
    //     print_filas(filas);
    //     filas_para_lista(filas, lista);
    // }
    // printf("\n\nLista ordenada: ");
    // for(int i = 0; i < num_elem; i++){
    //     printf("%d,", lista[i]);

    // }
    // printf("\n\n");
}
