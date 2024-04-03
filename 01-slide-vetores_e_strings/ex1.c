#include <stdio.h>

/*
Crie um programa que lê 5 valores inteiros, armazena-os em um vetor e, em seguida, mostre na tela os valores lidos.
*/

void imprimirVetorInt(int *v, int tamanho) {
    printf("Elementos do vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", v[i]);
        if (i < tamanho-1) printf(", ");
    }
    printf("\n");
}

int main() {
    int vetor[5];

    for (int i = 0; i < sizeof(vetor) / sizeof(vetor[0]); i++) {
        printf("N%d: ", i+1);
        scanf(" %d", vetor+i);
    }

    imprimirVetorInt(vetor, sizeof(vetor)/sizeof(vetor[0]));

    return 0;
}