#include <stdio.h>
#include <stdlib.h>

/*
3) Implemente uma função que receba um vetor de valores inteiros com N elementos e construa uma lista duplamente encadeada armazenando os elementos do vetor
(elemento a elemento). Assim, se for recebido por parâmetro o vetor v[4] = {1,21,4,6} a função deve retornar uma lista encadeada em que o primeiro elemento
é ‘1’, o segundo o ‘21’, o terceiro o ‘4’ e assim por diante. A função deve ter a seguinte assinatura: ListaInt *constroiLista (int n, int *v);
*/

struct TListaInt {
    int val;
    struct TListaInt *next, *prev;
};
typedef struct TListaInt ListaInt;

void imprimirArray(int n, int *v);
void imprimirInversa(ListaInt *head);
void imprimirLista(ListaInt *head);
ListaInt* constroiLista(int n, int *v);

int main() {
    int v[] = {1, 21, 4, 6, 30, 12, 9};
    ListaInt *head = constroiLista(sizeof(v)/sizeof(v[0]), v);

    printf("Array: ");
    imprimirArray(sizeof(v)/sizeof(v[0]), v);
    printf("Lista: ");
    imprimirLista(head);
    printf("Inverso: ");
    imprimirInversa(head);

    return 0;
}

ListaInt* constroiLista(int n, int *v) {
    ListaInt *head = NULL, *aux, *newItem;

    for (int i = 0; i < n; i++) {
        newItem = (ListaInt*)malloc(sizeof(ListaInt));
        newItem->val = v[i];
        newItem->prev = NULL;
        newItem->next = NULL;
        if (head == NULL) {
            head = newItem;
            aux = head;
        }
        else {
            aux->next = newItem;
            newItem->prev = aux;
            aux = newItem;
        }
    }
    return head;
}

void imprimirLista(ListaInt *head) {
    for (ListaInt* aux = head; aux != NULL; aux = aux->next) {
        printf("%d", aux->val);
        if (aux->next != NULL) printf(" -> ");
    }
    printf("\n");
}

void imprimirArray(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n-1) printf(", ");
    }
    printf("\n");
}

void imprimirInversa(ListaInt *head) {
    ListaInt *aux;
    for (aux = head; aux->next != NULL; aux = aux->next);
    for (; aux != NULL; aux = aux->prev) {
        printf("%d", aux->val);
        if (aux->prev != NULL) printf(" -> ");
    }
    printf("\n");
}
