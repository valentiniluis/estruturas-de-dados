#include <stdio.h>

/*
Implemente uma função recursiva que calcule o somatório se um vetor passado por parâmetro.
*/

int somaVetor(int *v, int t);

int main() {
    int v[] = {10, 320, 32, 1, 37};
    int tamanho = sizeof(v)/ sizeof(v[0]);
    int soma = somaVetor(v, tamanho);

    printf("%d\n", soma);

    return 0;
}

int somaVetor(int *v, int t) {
    if (t == 1) return v[0];
    return v[t-1] + somaVetor(v, t-1);
}