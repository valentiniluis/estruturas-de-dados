#include <stdio.h>

/*
Leia uma matriz 4 x 4 e imprima a triangular superior.
*/

void imprimirTriangular4x4(int m[4][4]);

int main() {
    int m[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            printf("Pos (%d, %d): ", i+1, j+1);
            scanf(" %d", m[i]+j);
        }
    }

    imprimirTriangular4x4(m);

    return 0;
}

void imprimirTriangular4x4(int m[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < i) printf("00 ");
            else {
                if (m[i][j] < 10) printf("0");
                printf("%d ", m[i][j]);
            }
        }
        printf("\n");
    }
}
