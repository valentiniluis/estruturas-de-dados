#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

struct SNode {
    int data;
    struct SNode *next;
};
typedef struct SNode Node;

void freeList(Node* node);
Node* Delete(Node *head, int position); //Só exclui algum node se a posição for válida. Posições de 1 a n.
void Print(Node *head);
Node* Insert(Node *head, int data, int position); //recebe apenas o int que irá preencher o valor node->data. Se a posição for igual ou menor a 1, o node é inserido no início.
                                                  // Se a posição for maior que o tamanho da lista, o node é inserido no final.

#endif