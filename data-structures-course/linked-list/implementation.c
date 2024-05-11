#include <stdio.h>
#include <stdlib.h>

struct SNode {
    int data;
    struct SNode *next;
};
typedef struct SNode Node;

Node* Insert(Node *head, int data, int position); //recebe apenas o int que irá preencher o valor node->data. Se a posição for igual ou menor a 1, o node é inserido no início.
                                                  // Se a posição for maior que o tamanho da lista, o node é inserido no final.

Node* Delete(Node *head, int position); //Só exclui algum node se a posição for válida. Posições de 1 a n.
void Print(Node *head);

int main() {
    Node *head = NULL;

    for (int i = 1; i <= 6; i++) {
        head = Insert(head, i*10, 1000);
    }

    Print(head);
    head = Delete(head, 6);
    Print(head);

    return 0;
}

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