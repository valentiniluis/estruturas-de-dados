#include <stdio.h>

void printQueue(int *q, int size, int front, int rear) {
    printf("[");
    for (int i = front;; i = (i+1)%size) {
        printf("%d", q[i]);

        if (i != rear) printf(", ");
        else break;
    }
    printf("]\n");
}

void enqueue(int *q, int size, int x, int *front, int *rear);
int dequeue(int *q, int size, int *front, int *rear);
int front(int *q, int front);
int isEmpty(int front, int rear);
int isFull(int front, int rear, int size);

int main() {
    int queue[10];
    int f = -1, r = -1, size = sizeof(queue)/sizeof(queue[0]);

    for (int i = 0; i < 10; i++) {
        enqueue(queue, size, i * 100, &f, &r);
    }
    for (int i = 0; i < 3; i++) {
        dequeue(queue, size, &f, &r);
    }
    printQueue(queue, size, f, r);

    return 0;
}

void enqueue(int *q, int size, int x, int *front, int *rear) {
    if (isFull(*front, *rear, size)) return;
    
    if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
    }
    else {
        *rear = ((*rear) + 1) % size;
    }
    q[*rear] = x;
}

int dequeue(int *q, int size, int *front, int *rear) {
    if (isEmpty(*front, *rear)) return 0;

    int value = q[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    }
    else {
        *front = ((*front) + 1) % size;
    }
    return value;
}

int front(int *q, int front) {
    if (front == -1) return 0;
    return q[front];
}

int isEmpty(int front, int rear) {
    return front == -1 && rear == -1;
}

int isFull(int front, int rear, int size) {
    return (rear + 1) % size == front;
}