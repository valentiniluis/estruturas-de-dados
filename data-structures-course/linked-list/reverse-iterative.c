#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Node* reverseListIterative(Node *head);

int main() {
    Node *head = NULL;

    for (int i = 1; i <= 5; i++) {
        head = Insert(head, i*10, 1000);
    }

    printf("Normal list: ");
    Print(head);
    printf("Reversed list: ");
    head = reverseListIterative(head);
    Print(head);
    head = NULL;

    freeList(head);
    head = NULL;

    return 0;
}

Node* reverseListIterative(Node *head) {
    Node *previous = NULL, *current = head, *next;
    
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;

}