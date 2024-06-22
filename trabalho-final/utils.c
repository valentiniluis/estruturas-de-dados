#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void initList(sentinela *s) {
    s->head = NULL;
    s->tail = NULL;
}

tarefa* gerarTarefa(int id) {
    tarefa *t = (tarefa*)malloc(sizeof(tarefa));
    t->id = id;
    printf("descricao: ");
    scanf("%*[^\n]"); scanf("%*c");
    fgets(t->descricao, 50, stdin);
    t->descricao[strcspn(t->descricao, "\n")] = 0;
    printf("tempo limite (em horas): ");
    scanf(" %f", &t->tempoLimite);
    t->ativa = 1;
    t->prev = NULL;
    t->next = NULL;
    return t;
}

void adicionarTarefa(sentinela *s, tarefa *t) {
    if (s->head == NULL) {
        s->head = t;
        s->tail = t;
    }
    else {
        tarefa *temp;
        for (temp = s->head; temp != NULL; temp = temp->next) if (t->tempoLimite < temp->tempoLimite) break;
        if (temp == s->head) {
            t->next = temp;
            temp->prev = t;
            s->head = t;
        }
        else if (temp == NULL) {
            t->prev = s->tail;
            s->tail->next = t;
            s->tail = t;
        }
        else {
            t->prev = temp->prev;
            t->next = temp;
            temp->prev->next = t;
            temp->prev = t;
        }
    }
}

void verTodasTarefas(sentinela s) {
    for (tarefa *aux = s.head; aux != NULL; aux = aux->next) {
        printf("id: %d, descricao: %s, tempo limite: %.1f hora(s), status: %s\n", aux->id, aux->descricao, aux->tempoLimite, (aux->ativa) ? "ativa" : "desativada");
    }
}

void verParteTarefas(sentinela s, int verAtivas) {
    for (tarefa *aux = s.head; aux != NULL; aux = aux->next) {
        if (aux->ativa == verAtivas) 
            printf("id: %d, descricao: %s, tempo limite: %.1f hora(s), status: %s\n", aux->id, aux->descricao, aux->tempoLimite, (aux->ativa) ? "ativa" : "desativada");
    }
}

int concluirTarefa(sentinela *s, int id) {
    if (s->head == NULL) return 0;

    tarefa *temp;
    for (temp = s->head; temp != NULL; temp = temp->next) if (temp->id == id) break;

    if (temp == NULL) return 0;

    temp->ativa = 0;
    if (temp != s->tail) {
        if (temp == s->head) {
            s->head = s->head->next;
            s->head->prev = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        s->tail->next = temp;
        temp->prev = s->tail;
        temp->next = NULL;
        s->tail = s->tail->next;
    }
    return 1;
}

int excluirTarefa(sentinela *s, int id) {
    if (s->head == NULL) return 0;

    tarefa *temp = s->head;
    for (; temp != NULL; temp = temp->next) {
        if (temp->id == id) break;
    }

    if (temp == NULL) return 0;
    else {
        if (temp == s->head && temp == s->tail) {
            initList(s);
        }
        else if (temp == s->head) {
            s->head = s->head->next;
            s->head->prev = NULL;
        }
        else if (temp == s->tail) {
            s->tail = s->tail->prev;
            s->tail->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
        return 1;
    }
}

void limparTarefas(sentinela *s) {
    while (s->head != NULL) {
        excluirTarefa(s, s->head->id);
    }
}

node* criarNo(int id) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* adicionaNo(node *root, node *newNode) {
    if (root == NULL) return newNode;
    else {
        if (root->id >= newNode->id) root->left = adicionaNo(root->left, newNode);
        else root->right = adicionaNo(root->right, newNode);
    }
    return root;
}

int pesquisarId(node *root, int key) {
    while (root != NULL) {
        if (root->id == key) return 1;
        else if (key < root->id) root = root->left;
        else root = root->right;
    }
    return 0;
}

node* gerarArvore(sentinela s) {
    node *root = NULL;
    for (tarefa *aux = s.head; aux != NULL; aux = aux->next) {
        node *newNode = criarNo(aux->id);
        root = adicionaNo(root, newNode);
    }
    return root;
}

void limparArvore(node *root) {
    if (root == NULL) return;
    limparArvore(root->left);
    limparArvore(root->right);
    free(root);
}

int receberIDValido(node *root) {
    int idInvalido = 1, id;
    while (idInvalido) {
        printf("id: ");
        scanf("%d", &id);
        idInvalido = pesquisarId(root, id);
        if (idInvalido) printf("Id ja esta sendo usado.\n");
    }
    return id;
}
