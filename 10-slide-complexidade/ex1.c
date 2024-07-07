#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *next;
};
typedef struct tnode node;

node* dominanteADireita(int*, int);

void printList(node *head) {
    printf("[");
    for (; head != NULL; head = head->next) {
        printf("%d", head->data);
        if (head->next != NULL) printf(", ");
    }
    printf("]\n");
}

void freeList(node **head) {
    node *aux;
    while (*head != NULL) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

int main() {
    int v[] = {50, 40, 20, 10, 5, 12, 11, 6};
    int size = sizeof(v)/sizeof(v[0]);
    node *head = dominanteADireita(v, size);
    printList(head);
    
    return 0;
}

node* dominanteADireita(int *v, int size) {
    node *head = NULL;
    for (int i = size - 1; i >= 0; i--) {
        if (head == NULL || v[i] > head->data) {
            node *newNode = (node*)malloc(sizeof(node));
            newNode->data = v[i];
            newNode->next = NULL;

            if (head == NULL) head = newNode;
            else {
                newNode->next = head;
                head = newNode;
            }
        }
    }
    return head;
}
