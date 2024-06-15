#include <stdio.h>
#include <stdlib.h>

struct tqueue {
    int value;
    struct tqueue *next;
};
typedef struct tqueue queue;

struct tqueueEnds {
    queue *head;
    queue *tail;
};
typedef struct tqueueEnds qEnds;

void printQueue(qEnds q) {
    printf("[");
    for (queue *aux = q.head; aux != NULL; aux = aux->next) {
        printf("%d", aux->value);
        if (aux->next != NULL) printf(", ");
    }
    printf("]\n");
}

void initQueue(qEnds *q);
void enqueue(qEnds *q, int x);
int dequeue(qEnds *q);
int front(qEnds *q);
int isEmpty(qEnds *q);
void freeQueue(qEnds *q);

int main() {
    qEnds q;
    initQueue(&q);

    int valid = 1;
    while (valid) {
        printf("0 - exit\n");
        printf("1 - enqueue\n");
        printf("2 - dequeue\n");
        printf("3 - front\n");
        printf("4 - is empty\n");
        printf("5 - view queue\n");
        printf("6 - free queue\n");
        printf("option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("value: ");
                scanf("%d", &option);
                enqueue(&q, option);
                break;
            case 2:
                option = dequeue(&q);
                printf("dequeue'd value: %d\n", option);
                break;
            case 3:
                printf("front: %d\n", front(&q));
                break;
            case 4:
                printf("is empty: %d\n", isEmpty(&q));
                break;
            case 5:
                printQueue(q);
                break;
            case 6:
                freeQueue(&q);
                break;
            default:
                valid = 0;
        }
        printf("\n=========================================================\n\n");
    }
    freeQueue(&q);

    return 0;
}

void initQueue(qEnds *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(qEnds *q, int x) {
    queue *newItem = (queue*)malloc(sizeof(queue));
    newItem->value = x;
    newItem->next = NULL;

    if (isEmpty(q)) {
        q->head = newItem;
        q->tail = newItem;
    }
    else {
        q->tail->next = newItem;
        q->tail = newItem;
    }
}

int dequeue(qEnds *q) {
    if (isEmpty(q)) return 0;

    queue *temp = q->head;
    if (q->head == q->tail) {
        initQueue(q);
    }
    else {
        q->head = q->head->next;
    }
    int value = temp->value;
    free(temp);
    return value;
}

int front(qEnds *q) {
    return q->head->value;
}

int isEmpty(qEnds *q) {
    return q->head == NULL && q->tail == NULL;
}

void freeQueue(qEnds *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}
