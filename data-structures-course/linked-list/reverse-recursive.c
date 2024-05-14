#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

Node* reverseListRecursive(Node* node);

int main() {
    Node *head = NULL;
    for (int i = 1; i <= 15; i++) {
        head = Insert(head, i*10, 1000);
    }

    printf("Normal list: ");
    Print(head);
    head = reverseListRecursive(head);
    printf("Reversed list: ");
    Print(head);

    return 0;
}

Node* reverseListRecursive(Node* node) {
    if (node == NULL) return NULL;
    if (node->next == NULL) return node;
    Node *head = reverseListRecursive(node->next);
    Node *next = node->next;
    next->next = node;
    // node->next->next = node; <--> faz a mesma coisa que as 2 linhas acima
    node->next = NULL;
    return head;
}
