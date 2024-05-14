#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Node* Insert(Node *head, int data, int position) {
    Node *new, *aux = head;
    new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    if (position <= 1 || head == NULL) {
        new->next = head;
        return new;
    }

    for (int i = 1; i < position-1; i++) {
        if (aux->next == NULL) break;
        aux = aux->next;
    }

    new->next = aux->next;
    aux->next = new;
    return head;
}

Node* Delete(Node *head, int position) {
    if (head == NULL || position < 1) return head;

    Node *aux = head;
    if (position == 1) {
        head = head->next;
        free(aux);
        return head;
    }

    for (int i = 1; i < position-1; i++) {
        aux = aux->next;
        if (aux->next == NULL) return head;
    }

    Node* delete = aux->next;
    aux->next = delete->next;
    free(delete);
    return head;

    /*
    Node *prev;
    for (int i = 1; i < position; i++) {
        prev = aux;
        aux = aux->next;
        if (aux == NULL) return head;
    }

    prev->next = aux->next;
    free(aux);
    return head;
    */
}

void Print(Node *head) {
    for (Node *aux = head; aux != NULL; aux = aux->next) {
        if (aux == head) printf("[");
        printf("%d", aux->data);
        if (aux->next != NULL) printf(", ");
        else printf("]");
    }
    printf("\n");
}

void freeList(Node* node) {
    if (node == NULL) return;
    freeList(node->next);
    free(node);
}