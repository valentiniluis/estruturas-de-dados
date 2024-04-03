#include <stdio.h>

/*
Declare um tipo Fraction que consista em uma struct contendo dois membros, numerador e denominador, do tipo int, e faça o seguinte:
a) Escreva uma função setFraction que recebe dois argumentos do tipo int (o numerador e o denominador), e retorna os valores em um tipo Fraction.
b) Escreva uma função multFraction que recebe dois argumentos do tipo Fraction, multiplica, armazena o resultado em uma outra variável do tipo
Fraction e retorna esta variável.  Lembrando: 4/5 x 3/2 = (4 x 3)/(5 x 2)
Faça funções para:
1 - Atribuição
2 - Multiplicação 
3 - Divisão
4 - Adição
5 - Subtração
*/

struct SFracao {
    int num;
    int den;
};
typedef struct SFracao Fracao;

Fracao setFraction(int num, int den);
Fracao multFraction(Fracao, Fracao);
Fracao divideFraction(Fracao, Fracao);
Fracao sumFraction(Fracao, Fracao);
Fracao subtractFraction(Fracao, Fracao);
void printFrac(Fracao);
int calcMMC(int, int);

int main() {
    Fracao frac1 = setFraction(7, 9);
    Fracao frac2 = setFraction(3, 4);

    printf("fracao 1: ");
    printFrac(frac1);
    printf("\n");
    printf("fracao 2: ");
    printFrac(frac2);
    printf("\n");

    printf("multiplicacao: ");
    printFrac(multFraction(frac1, frac2));
    printf("\n");

    printf("divisao: ");
    printFrac(divideFraction(frac1, frac2));
    printf("\n");

    printf("soma: ");
    printFrac(sumFraction(frac1, frac2));
    printf("\n");
    
    printf("subtracao: ");
    printFrac(subtractFraction(frac1, frac2));
    printf("\n");

    return 0;
}



Fracao setFraction(int num, int den){
    Fracao f = {num, den};
    return f;
}

Fracao multFraction(Fracao f1, Fracao f2) {
    Fracao f3 = {f1.num * f2.num, f1.den * f2.den};
    return f3;
}

Fracao divideFraction(Fracao f1, Fracao f2) {
    Fracao temp = {f2.den, f2.num};
    Fracao f3 = multFraction(f1, temp);
    return f3;
}

Fracao sumFraction(Fracao f1, Fracao f2) {
    int mmc = calcMMC(f1.den, f2.den);
    int denf3 = mmc / f1.den * f1.num + mmc / f2.den * f2.num;
    Fracao f3 = {denf3, mmc};
    return f3;
}

Fracao subtractFraction(Fracao f1, Fracao f2) {
    int mmc = calcMMC(f1.den, f2.den);
    int denf3 = mmc / f1.den * f1.num - mmc / f2.den * f2.num;
    Fracao f3 = {denf3, mmc};
    return f3;
}

int calcMMC(int n1, int n2) {
    int maior = (n1 > n2) ? n1 : n2;
    int menor = (n1 > n2) ? n2 : n1;
    int mmc = 0;

    int i = 1;
    while (mmc == 0) {
        int temp = maior * i;
        if (temp % menor == 0) mmc = temp;
        else i++;
    }

    return mmc;
}

void printFrac(Fracao f) {
    printf("%d/%d", f.num, f.den);
}
