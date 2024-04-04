#include <stdio.h>
#include <string.h>

/*
Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno,
nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
a) Permita ao usuário entrar com os dados de 5 alunos.
b) Encontre o aluno com maior nota da primeira prova.
c) Encontre o aluno com maior média geral.
d) Encontre o aluno com menor média geral.
e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
*/

struct SAluno {
    char matricula[20];
    char nome[100];
    int notas[3];
};
typedef struct SAluno Aluno;


void alunoMaiorNotaProva(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, int *nota, int numeroProva);
void alunoMaiorMedia(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, double *media, int qtdProvas);
void alunoMenorMedia(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, double *media, int qtdProvas);
void aprovacaoAluno(Aluno alunos[], int qtdAlunos, int qtdProvas);

int main() {
    Aluno alunos[3];

    for (int i = 0; i < sizeof(alunos) / sizeof(alunos[0]); i++) {
        printf("Matricula do aluno: ");
        scanf(" %s", alunos[i].matricula);
        
        printf("Nome do aluno: ");
        scanf(" %s", alunos[i].nome);
        
        for (int j = 0; j < 3; j++) {
            printf("Nota #%d: ", j+1);
            scanf(" %d", &alunos[i].notas[j]);
        }
    }


    int maiorNotaP1, numeroProva = 1, nAlunos = sizeof(alunos) / sizeof(alunos[0]);
    char matriculaMaiorNotaP1[20], nomeMaiorNotaP1[100];

    int numeroProvas = sizeof(alunos[0].notas) / sizeof(alunos[0].notas[0]);
    char matriculaMaiorMedia[20], nomeMaiorMedia[100];
    double maiorMedia;

    char matriculaMenorMedia[20], nomeMenorMedia[100];
    double menorMedia;

    alunoMaiorNotaProva(alunos, nAlunos, nomeMaiorNotaP1, matriculaMaiorNotaP1, &maiorNotaP1, numeroProva);
    alunoMaiorMedia(alunos, nAlunos, nomeMaiorMedia, matriculaMaiorMedia, &maiorMedia, numeroProvas);
    alunoMenorMedia(alunos, nAlunos, nomeMenorMedia, matriculaMenorMedia, &menorMedia, numeroProvas);

    printf("A maior nota da prova %d foi do aluno %s (matricula %s), que tirou %d\n", numeroProva, nomeMaiorNotaP1, matriculaMaiorNotaP1, maiorNotaP1);
    printf("A maior media foi do aluno %s (matricula %s), com %.2f\n", nomeMaiorMedia, matriculaMaiorMedia, maiorMedia);
    printf("A menor media foi do aluno %s (matricula %s), com %.2f\n", nomeMenorMedia, matriculaMenorMedia, menorMedia);
    aprovacaoAluno(alunos, nAlunos, numeroProvas);

    return 0;
}


void alunoMaiorNotaProva(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, int *nota, int numeroProva) {
    *nota = alunos[0].notas[numeroProva-1];
    strcpy(nome, alunos[0].nome);
    strcpy(matricula, alunos[0].matricula);

    for (int i = 1; i < qtdAlunos; i++) {

        if (alunos[i].notas[numeroProva-1] > *nota) {
            *nota = alunos[i].notas[numeroProva-1];
            strcpy(nome, alunos[i].nome);
            strcpy(matricula, alunos[i].matricula);
        }
    }
}

void alunoMaiorMedia(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, double *media, int qtdProvas) {
    *media = 0;

    for (int i = 0; i < qtdAlunos; i++) {
        double mediaTemp = 0;

        for (int j = 0; j < qtdProvas; j++) {
            mediaTemp += alunos[i].notas[j];
        }
        mediaTemp /= qtdProvas;

        if (mediaTemp >= *media) {
            *media = mediaTemp;
            strcpy(nome, alunos[i].nome);
            strcpy(matricula, alunos[i].matricula);
        }
    }
}

void alunoMenorMedia(Aluno alunos[], int qtdAlunos, char *nome, char *matricula, double *media, int qtdProvas) {
    *media = 10;

    for (int i = 0; i < qtdAlunos; i++) {
        double mediaTemp = 0;

        for (int j = 0; j < qtdProvas; j++) {
            mediaTemp += alunos[i].notas[j];
        }
        mediaTemp /= qtdProvas;

        if (mediaTemp <= *media) {
            *media = mediaTemp;
            strcpy(nome, alunos[i].nome);
            strcpy(matricula, alunos[i].matricula);
        }
    }
}

void aprovacaoAluno(Aluno alunos[], int qtdAlunos, int qtdProvas) {

    for (int i = 0; i < qtdAlunos; i++) {
        double media = 0;
        for (int j = 0; j < qtdProvas; j++) {
            media += alunos[i].notas[j];
        }
        media /= qtdProvas;

        if (media >= 6) {
            printf("Aluno(a) %s (matricula %s) aprovado(a) com media %.2f\n", alunos[i].nome, alunos[i].matricula, media);
        }
        else {
            printf("Aluno(a) %s (matricula %s) reprovado(a) com media %.2f\n", alunos[i].nome, alunos[i].matricula, media);
        }
    }
}