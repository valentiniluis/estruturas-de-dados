#ifndef STACK_UTILS_H
#define STACK_UTILS_H

struct node {
    int data;
    struct node *link;
};
typedef struct node Node;

struct charStack {
    char letter;
    struct charStack *link;
};
typedef struct charStack cStack;

struct tliststack {
    Node *data;
    struct tliststack *link;
};
typedef struct tliststack listStack;

void pushNode(listStack **top, Node *node);
void popNode(listStack **top);
void freeList(Node **head);
void printList(Node *head);
void pushInt(Node **head, int x);
void Pop(Node **head);
int Top(Node*);
int isEmpty(Node*);
void popChar(cStack **h);
void pushChar(cStack **h, char l);
void freeCharStack(cStack **h);

#endif