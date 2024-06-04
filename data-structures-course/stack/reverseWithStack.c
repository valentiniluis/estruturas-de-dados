#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_utils.h"

void reverseString(char *s, int len);
void reverseLinkedList(Node **head);

int main() {
    /*
    char string[101];
    printf("String to be reversed: ");
    fgets(string, 101, stdin);
    string[strcspn(string, "\n")] = 0;
    int len = strlen(string);
    reverseString(string, len);
    printf("Reversed string: %s\n", string);
    */

    Node *head =  NULL;
    for (int i = 0; i < 10; i++) {
        pushInt(&head, i);
    }
    printf("Original linked list: ");
    printList(head);

    reverseLinkedList(&head);
    printf("Reversed linked list: ");
    printList(head);

    return 0;
}

void reverseLinkedList(Node **head) {
    if (*head == NULL) return;
    listStack *top = NULL;

    for (Node *aux = *head; aux != NULL; aux = aux->link) {
        pushNode(&top, aux);
    }

    Node *temp = top->data;
    *head = temp;
    popNode(&top);

    for (; top != NULL;) {
        temp->link = top->data;
        temp = temp->link;
        popNode(&top);
    }
    temp->link = NULL;
}

void reverseString(char *s, int len) {
    cStack *top = NULL;

    for (int i = 0; i < len; i++) {
        pushChar(&top, s[i]);
    }
    for (int i = 0; i < len; i++) {
        s[i] = top->letter;
        popChar(&top);
    }
}
