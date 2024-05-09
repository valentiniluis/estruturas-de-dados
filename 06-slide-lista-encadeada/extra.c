#include <stdio.h>
#include <stdlib.h>

struct TPoint {
    int x, y;
    struct TPoint* next;
};
typedef struct TPoint Point;

void printPoints(Point* head);
void freeLinkedList(Point* head);

int main() {
    Point *head = NULL, *current;

    printf("Insira os valores de 'x' e 'y' (separados por espaco) ou -1 (para tanto x ou y) para parar.\n");
    while (1) {
        int temp1, temp2;
        printf("x, y: ");
        scanf(" %d%d", &temp1, &temp2);

        if (temp1 == -1 || temp2 == -1) break;

        if (head == NULL) {
            head = (Point*)malloc(sizeof(Point));
            current = head;
        }
        else {
            current->next = (Point*)malloc(sizeof(Point));
            current = current->next;
        }
        current->x = temp1;
        current->y = temp2;
        current->next = NULL;
    }

    if (head == NULL) {
        printf("Nenhum ponto foi preenchido.\n");
    }
    else {
        printPoints(head);
        freeLinkedList(head);
        printf("Lista encadeada foi liberada da memoria.\n");
    }

    return 0;
}

void printPoints(Point* head) {
    int i = 1;
    for (Point* aux = head; aux != NULL; aux = aux->next) {
        printf("Par #%d: (%d, %d)\n", i++, aux->x, aux->y);
    }
}

void freeLinkedList(Point* head) {
    Point *current = head;
    for (Point *aux = head; current != NULL; aux = current) {
        current = current->next;
        free(aux);
    }
}