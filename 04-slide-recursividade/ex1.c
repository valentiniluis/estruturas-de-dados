#include <stdio.h>

/*
Implemente uma função recursiva que, dados dois números inteiros base (b) e expoente (e), calcula o valor de be (e≥0).
*/

int elevar(int b, int e);

int main() {
    int n = elevar(13, 0);
    printf("%d\n", n);

    return 0;
}

int elevar(int b, int e) {
    if (e == 0) return 1;
    return b * elevar(b, e-1);
}