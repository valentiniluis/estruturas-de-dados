#include <stdio.h>

/*
Implemente uma função recursiva que calcule o máximo divisor comum (mdc) entre dois números.
*/

int calcMdc(int m, int n);

int main() {
    int mdc = calcMdc(12, 18);
    printf("%d\n", mdc);

    return 0;
}

int calcMdc(int m, int n) {
    if (n == 0) return m;
    return calcMdc(n, m%n);
}