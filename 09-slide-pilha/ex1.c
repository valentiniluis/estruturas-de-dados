#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que receba uma string, caractere por caractere
Cada caractere é colocado em uma pilha
No fim da entrada, esvazie a pilha imprimindo os caracteres armazenados
*/

struct tstack {
    char letter;
    struct tstack *next;
};
typedef struct tstack stack;

void viewStack(stack *top) {
    printf("[");
    for (; top != NULL; top = top->next) {
        printf("%c", top->letter);
        if (top->next != NULL) printf(", ");
    }
    printf("]\n");
}

void push(stack **top, char c);
char pop(stack **top);
void printFreeStack(stack **top);
char top(stack *top);
int isEmpty(stack *top);
void freeStack(stack **top);

int main() {
    stack *top = NULL;

    int valido = 1;
    while (valido) {
        printf("0 - sair\n");
        printf("1 - adicionar letra\n");
        printf("2 - retirar letra\n");
        printf("3 - esvaziar e imprimir stack\n");
        printf("4 - esvaziar stack\n");
        char letra;
        int opcao;
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
            case 1:
                printf("letra: ");
                scanf(" %c", &letra);
                push(&top, letra);
                break;
            case 2:
                printf("letra retirada: %c\n", pop(&top));
                break;
            case 3:
                printFreeStack(&top);
                break;
            case 4:
                freeStack(&top);
                break;
            default:
                valido = 0;
        }
        printf("\n===============================================\n\n");
    }

    return 0;
}

void push(stack **top, char c) {
    stack *newItem = (stack*)malloc(sizeof(stack));
    newItem->letter = c;
    newItem->next = *top;
    *top = newItem;
}

char pop(stack **top) {
    if (*top == NULL) return 0;
    stack *temp = *top;
    *top = (*top)->next;
    char letra = temp->letter;
    free(temp);
    return letra;
}

void printFreeStack(stack **top) {
    while (!isEmpty(*top)) {
        printf("%c", pop(top));
    }
    printf("\n");
}

char top(stack *top) {
    return top->letter;
}

int isEmpty(stack *top) {
    return top == NULL;
}

void freeStack(stack **top) {
    while(!isEmpty(*top)) {
        pop(top);
    }
}
