#include <stdio.h>

/*
Leia uma matriz 4 x 4 e imprima a diagonal principal.
*/

void imprimirDiagonal4x4(int m[4][4]);

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    imprimirDiagonal4x4(matriz);

    return 0;
}

void imprimirDiagonal4x4(int m[4][4]) {
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        printf("%d\n", m[i][i]);
    }
}