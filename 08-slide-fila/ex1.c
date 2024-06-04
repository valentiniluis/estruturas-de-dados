#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que receba uma string, caractere por caractere
Cada caractere é colocado em uma fila
No fim da entrada, esvazie a fila imprimindo os caracteres armazenados
*/

struct tnode {
    char letter;
    struct tnode *link;
};
typedef struct tnode Node;

struct tqueue {
    Node *head, *tail;
};
typedef struct tqueue Queue;

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, char l) {
    Node *newItem = (Node*)malloc(sizeof(Node));
    newItem->letter = l;
    newItem->link = NULL;
    
    if (q->head == NULL) {
        q->head = newItem;
        q->tail = newItem;
    }
    else {
        q->tail->link = newItem;
        q->tail = newItem;
    }
}

char dequeue(Queue *q) {
    char l = q->head->letter;
    Node *aux = q->head;
    q->head = q->head->link;
    free(aux);
    return l;
}

int isEmpty(Queue *q) {
    return q->head == NULL;
}

void emptyQueue(Queue *q) {
    Node *aux;
    for (aux = q->head; aux != NULL; aux = q->head) {
        aux = q->head;
        q->head = q->head->link;
        printf("%c", aux->letter);
        free(aux);
    }
    printf("\n");
    initQueue(q);
}

int main() {
    Queue q;
    initQueue(&q);

    int qtdLetras;
    printf("Quantas letras quer inserir? ");
    scanf("%d", &qtdLetras);

    for (int i = 0; i < qtdLetras; i++) {
        char l;
        printf("Letra #%d: ", i+1);
        //scanf("%*[^\n]"); scanf("%*c");
        scanf(" %c", &l);
        enqueue(&q, l);
    }

    emptyQueue(&q);

    return 0;
}