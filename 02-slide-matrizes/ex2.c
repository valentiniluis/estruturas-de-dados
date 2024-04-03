#include <stdio.h>

/*
Leia uma matriz 4 x 4 e escreva a localização (linha e coluna) do maior valor.
*/

void imprimirPosicaoMax4x4(int m[4][4]);

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 17, 11, 12},
        {13, 14, 15, 16}
    };

    imprimirPosicaoMax4x4(matriz);
    
    return 0;
}

void imprimirPosicaoMax4x4(int m[4][4]) {
    int pos[] = {0,0};
    int max = m[pos[0]][pos[1]];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
                pos[0] = i;
                pos[1] = j;
            }
        }
    }

    printf("Posicao do maior valor (linha, coluna): (%d, %d)\n", pos[0]+1, pos[1]+1);
    printf("Maior valor: %d\n", max);
}

