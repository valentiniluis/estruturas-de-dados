#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    node *raiz = NULL;
    sentinela s;
    initList(&s);
    
    int inputValido = 1;
    while (inputValido) {
        printf("0 - sair\n");
        printf("1 - adicionar tarefa\n");
        printf("2 - visualizar todas as tarefas\n");
        printf("3 - visualizar tarefas ativas\n");
        printf("4 - visualizar tarefas concluidas\n");
        printf("5 - concluir tarefa\n");
        printf("6 - excluir tarefa\n");
        int opcao;
        printf("Opcao desejada: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                int id = receberIDValido(raiz); // função pede um id novo repetidamente se o usuário digitar um identificador repetido. Busca de id usando BST
                adicionarTarefa(&s, gerarTarefa(id));
                raiz = adicionaNo(raiz, criarNo(id));
                break;
            case 2:
                verTodasTarefas(s);
                break;
            case 3:
                verParteTarefas(s, 1);
                break;
            case 4:
                verParteTarefas(s, 0);
                break;
            case 5:
                int idConcluir;
                printf("id da tarefa a concluir: ");
                scanf(" %d", &idConcluir);
                printf("%s\n", (concluirTarefa(&s, idConcluir)) ? "Tarefa concluida com sucesso." : "Tarefa nao encontrada.");
                break;
            case 6:
                int idExcluir;
                printf("id da tarefa a excluir: ");
                scanf(" %d", &idExcluir);
                if (excluirTarefa(&s, idExcluir)) {
                    // ao excluir um node, por não saber corrigir os links da árvore, excluí a árvore antiga e gerei uma nova
                    printf("Tarefa excluida com sucesso.\n");
                    limparArvore(raiz);
                    raiz = NULL;
                    raiz = gerarArvore(s);
                }
                else printf("Tarefa nao encontrada\n");
                break;
            default:
                inputValido = 0;
        }
        if (inputValido) printf("\n==========================================\n\n");
    }

    // dealocação da memória dinâmica
    limparTarefas(&s);
    limparArvore(raiz);
    raiz = NULL;

    return 0;
}