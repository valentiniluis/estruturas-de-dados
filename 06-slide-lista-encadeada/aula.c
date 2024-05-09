#include <stdio.h>
#include <stdlib.h>

struct tt {
    int val;
    struct tt *next;
};
typedef struct tt t;

t* getIntersection(t* lista1, t* lista2);
t* getDifference(t*, t*);
t* getUnion(t*, t*);
void printList(t*);
void pushNode(t**, t*);
void freeMemory(t*);

int main() {
    t *head1 = NULL, *aux1;
    t *head2 = NULL, *aux2;

    int lenList1;
    printf("quantos elementos inserir na lista 1? ");
    scanf("%d", &lenList1);

    for (int i = 1; i <= lenList1; i++) {
        aux1 = (t*)malloc(sizeof(t));
        printf("Valor #%d: ", i);
        scanf("%d", &aux1->val);
        aux1->next = NULL;
        pushNode(&head1, aux1);
    }

    int lenList2;
    printf("quantos elementos inserir na lista 2? ");
    scanf("%d", &lenList2);
    for (int i = 1; i <= lenList2; i++) {
        aux2 = (t*)malloc(sizeof(t));
        printf("Valor #%d: ", i);
        scanf("%d", &aux2->val);
        aux2->next = NULL;
        pushNode(&head2, aux2);
    }

    printf("=================================\n");
    printf("Lista 1:\n");
    printList(head1);
    printf("=================================\n");
    printf("Lista 2:\n");
    printList(head2);
    printf("=================================\n");
    t *head3 = getUnion(head1, head2);
    printf("Uniao das listas (sem repeticao):\n");
    printList(head3);

    freeMemory(head1);
    freeMemory(head2);
    freeMemory(head3);
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    return 0;
}

t* getIntersection(t* lista1, t* lista2) {
    t* head = NULL, *aux, *novo;

    for (t *temp1 = lista1; temp1 != NULL; temp1 = temp1->next) {
        for (t *temp2 = lista2; temp2 != NULL; temp2 = temp2->next) {

            if (temp1->val == temp2->val) {
                novo = (t*)malloc(sizeof(t));
                novo->val = temp1->val;
                novo->next = NULL;
                if (head == NULL) {
                    head = novo;
                    aux = novo;
                }
                else {
                    aux->next = novo;
                    aux = aux->next;
                }
                break;
            }
        }
    }
    return head;
}

t* getDifference(t *h1, t *h2) {
    int adicionar;
    t *head = NULL, *aux, *new;
    for (t *temp1 = h1; temp1 != NULL; temp1 = temp1->next) {
        adicionar = 1;
        for (t *temp2 = h2; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->val == temp2->val) {
                adicionar = 0;
                break;
            }
        }
        if (adicionar) {
            new = (t*)malloc(sizeof(t));
            new->val = temp1->val;
            new->next = NULL;
            if (head == NULL) {
                head = new;
                aux = new;
            }
            else {
                aux->next = new;
                aux = aux->next;
            }
        }
    }
    return head;
}

t* getUnion(t* h1, t* h2) {
    t *h3 = NULL, *aux, *n;
    
    for (t* t1 = h1; t1 != NULL; t1 = t1->next) {
        n = (t*)malloc(sizeof(t));
        n->val = t1->val;
        n->next = t1->next;
        n->next = NULL;
        if (h3 == NULL) {
            h3 = n;
            aux = n;
        }
        else {
            aux->next = n;
            aux = aux->next;
        }
    }

    for (t* t2 = h2; t2 != NULL; t2 = t2->next) {
        int adicionar = 1;
        for (t* t3 = h3; t3 != NULL; t3 = t3->next) {
            if (t2->val == t3->val) {
                adicionar = 0;
                break;
            }
        }
        if (adicionar) {
            n = (t*)malloc(sizeof(t));
            n->val = t2->val;
            n->next = NULL;
            if (h3 == NULL) {
                h3 = n;
                aux = n;
            }
            else {
                aux->next = n;
                aux = aux->next;
            }
        }
    }
    return h3;
}

void printList(t* head) {
    for (t *aux = head; aux != NULL; aux = aux->next) {
        printf("%d", aux->val);
        if (aux->next != NULL) printf(" -> ");
    }
    printf("\n");
}

void pushNode(t** head, t* new) {
    if (*head == NULL) {
        *head = new;
        return;
    }

    t* aux = *head;
    while (aux->next != NULL) aux = aux->next;
    aux->next = new;
}

void freeMemory(t* p) {
    if (p == NULL) return;
    freeMemory(p->next);
    free(p);
}