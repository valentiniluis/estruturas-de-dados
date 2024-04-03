#include <stdio.h>

/*
Faça um programa que preenche uma matriz 5 x 5 com o produto da posição da linha e da coluna de cada elemento. Em seguida, imprima.
*/

void imprimirMatriz5x5(int m[5][5]);
void preencherMatriz5x5(int m[5][5]);

int main() {
    int matriz[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    preencherMatriz5x5(matriz);
    imprimirMatriz5x5(matriz);

    return 0;
}

void imprimirMatriz5x5(int m[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] < 10) printf("0");

            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void preencherMatriz5x5(int m[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            m[i][j] = (i+1)*(j+1);
        }
    }
}