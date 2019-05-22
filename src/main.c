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

    printf("Digite o numero maximo de digitos\n");
    scanf("%d", &digits);

    int array[size], max = p(10, digits);

    srand((unsigned) time(&t));

    for(int i = 0; i < size; i++){
        array[i] = rand() % max;
    }

    radix_sort(array, size, digits);

    return 0;
}
