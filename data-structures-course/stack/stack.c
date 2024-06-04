#include <stdio.h>
#include <stdlib.h>
#include "stack_utils.h"

void pushInt(Node **head, int x) {
    Node *newItem = (Node*)malloc(sizeof(Node));
    newItem->data = x;
    newItem->link = NULL;

    if (*head == NULL) *head = newItem;
    else {
        Node *aux;
        for (aux = *head; aux->link != NULL; aux = aux->link);
        aux->link = newItem;
    }
}

void Pop(Node **head) {
    if (*head == NULL) return;
    Node* temp = *head;
    (*head) = (*head)->link;
    free(temp);
}

int Top(Node *top) {
    return top->data;
}

int isEmpty(Node *top) {
    return top == NULL;
}

void pushChar(cStack **h, char l) {
    cStack *newItem = (cStack*)malloc(sizeof(cStack));
    newItem->letter = l;
    newItem->link = NULL;
    if (*h == NULL) {
        *h = newItem;
    }
    else {
        newItem->link = *h;
        *h = newItem;
    }
}
void popChar(cStack **h) {
    if (*h == NULL) return;

    cStack *aux = *h;
    *h = (*h)->link;
    free(aux);
}

void freeList(Node **head) {
    Node *aux;
    while (*head != NULL) {
        aux = *head;
        *head = (*head)->link;
        free(aux);
    }
}

void printList(Node *head) {
    printf("[");
    for (; head != NULL; head = head->link) {
        printf("%d", head->data);
        if (head->link != NULL) printf(", ");
    }
    printf("]\n");
}

void pushNode(listStack **top, Node *node) {
    listStack *newItem = (listStack*)malloc(sizeof(listStack));
    newItem->data = node;
    newItem->link = NULL;

    if (*top == NULL) {
        *top = newItem;
    }
    else {
        newItem->link = *top;
        *top = newItem;
    }
}

void popNode(listStack **top) {
    if (*top != NULL) {
        listStack *aux = *top;
        *top = (*top)->link;
        free(aux);
    }
}

void freeCharStack(cStack **h) {
    cStack *aux;
    while(*h != NULL) {
        aux = *h;
        *h = (*h)->link;
        free(aux);
    }
}
