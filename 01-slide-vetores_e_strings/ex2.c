#include <stdio.h>

/*
Faça uma função que receba um vetor e o seu tamanho como parâmetro e imprima o maior e o menor elemento do vetor. 
*/

void imprimirMinMax(int*, int);

int main() {
    int vetor[] = {12, -32, 4, 55, -75, 2, 43, -100, 213, -2, -3, -100};
    imprimirMinMax(vetor, sizeof(vetor)/sizeof(vetor[0]));

    return 0;
}

void imprimirMinMax(int *v, int tamanho) {
    int min = v[0], max = v[0];

    for (int i = 1; i < tamanho; i++) {
        if (v[i] > max) max = v[i];
        else if (v[i] < min) min = v[i];
    }

    printf("Minimo: %d\n", min);
    printf("Maximo: %d\n", max);
}