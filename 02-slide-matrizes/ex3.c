#include <stdio.h>

/*
Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Imprima, ao final, a matriz obtida.
*/

void imprimirMatriz5x5(int [5][5]);

int main() {
    int matriz[5][5] = {
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };

    imprimirMatriz5x5(matriz);

    return 0;
}

void imprimirMatriz5x5(int m[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}