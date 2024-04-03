#include <stdio.h>

/*
Escreva as seguintes funções considerando o tipo Data definido nesta apresentação:
a) int extraiDia(Data data) -> retorna o dia que compõe a data passada como parâmetro (data).
b) int comparaDatas(Data data1, Data data2) -> retorna -1 se a data data1 é anterior à data data2,
1 se a data data1 é posterior à data data2 e 0 se as datas data1 e data2 são iguais.
*/

struct SData {
    int dia;
    int mes;
    int ano;
};
typedef struct SData Data;

int extraiDia(Data);
int comparaDatas(Data d1, Data d2);

int main() {
    Data data1 = {18, 9, 2004}, data2 = {12, 8, 1971};
    
    int diaData1 = extraiDia(data1);
    printf("Dia data 1: %d\n", diaData1);
    
    int comp = comparaDatas(data1, data2);
    if (comp == 1) printf("A data 1 é posterior\n");
    else if (comp == -1) printf("A data 2 é posterior\n");
    else printf("As datas são iguais.\n");

    return 0;
}

int extraiDia(Data d) {
    return d.dia;
}

int comparaDatas(Data d1, Data d2) {
    int diasD1 = d1.ano * 365 + (d1.mes - 1) * 30 + d1.dia;
    int diasD2 = d2.ano * 365 + (d2.mes - 1) * 30 + d2.dia;
    int diferenca = diasD1 - diasD2;

    if (diferenca > 0) return 1;
    else if (diferenca < 0) return -1;
    else return 0;
}
