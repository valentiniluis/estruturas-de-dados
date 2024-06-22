#ifndef UTILS_H
#define UTILS_H

struct ttarefa {
    int id, ativa;
    char descricao[50];
    float tempoLimite;
    struct ttarefa *prev, *next;
};
typedef struct ttarefa tarefa;

struct tnode {
    int id;
    struct tnode *left, *right;
};
typedef struct tnode node;

struct tsentinela {
    tarefa *head, *tail;
};
typedef struct tsentinela sentinela;

void initList(sentinela *s);
tarefa* gerarTarefa(int id);
void adicionarTarefa(sentinela *s, tarefa *t);
void verTodasTarefas(sentinela s);
void verParteTarefas(sentinela s, int verAtivas);
int concluirTarefa(sentinela *s, int id);
int excluirTarefa(sentinela *s, int id);
void limparTarefas(sentinela *s);
node* criarNo(int id);
node* adicionaNo(node *root, node *newNode);
int pesquisarId(node *root, int key);
node* gerarArvore(sentinela s);
void limparArvore(node *root);
int receberIDValido(node *root);

#endif