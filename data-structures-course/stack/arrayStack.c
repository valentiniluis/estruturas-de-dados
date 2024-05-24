#include <stdio.h>
#include <stdlib.h>

void Top(int *s, int top) {
    printf("top: %d\n", s[top]);
}

void Pop(int *top) {
    if (*top == -1) return;
    (*top)--;
}

int* Push(int *s, int *size, int *top) {
    if (*top == -1) {
        if (s == NULL) {
            s = (int*)malloc(sizeof(int)*(*size));
        }
        (*top)++;
        s[*top] = 1;
        return s;
    }
    else if (*top == (*size)-1) {
        *size = (*size) * 2;
        int *oldArray = s;
        s = (int*)malloc(sizeof(int)*(*size));
        for (int i = 0; i <= *top; i++) {
            s[i] = oldArray[i];
        }
        free(oldArray);
    }
    int k = s[*top];
    (*top)++;
    s[*top] = k+1;
    return s;
}

int isEmpty(int top) {
    return top == -1;
}

void Print(int *s, int top) { // somente para testar a implementação
    printf("all: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main() {
    int size = 5, top = -1, option = 1;
    int *s = NULL;

    while (option != 0) {
        printf("Stack operation:\n");
        printf("0 - exit\n1 - push\n2 - pop\n3 - view top\n4 - view all\n5 - check if stack is empty\n-> ");
        scanf("%d", &option);

        switch (option) {
            case 1: s = Push(s, &size, &top); break;
            case 2: Pop(&top); break;
            case 3: Top(s, top); break;
            case 4: Print(s, top); break;
            case 5: printf("Empty stack: %s\n", (isEmpty(top) == 1) ? "yes" : "no");
        }
        printf("\n");
    }
    free(s);

    return 0;
}
