#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

struct tqueueItem {
    Node *data;
    struct tqueueItem *next;
};
typedef struct tqueueItem qItem;

struct queue {
    qItem *head, *tail;
};
typedef struct queue Queue;

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, Node *value) {
    qItem *newItem = (qItem*)malloc(sizeof(qItem));
    newItem->data = value;
    newItem->next = NULL;

    if (q->head == NULL) {
        q->head = newItem;
        q->tail = newItem;
    }
    else {
        q->tail->next = newItem;
        q->tail = newItem;
    }
}

void dequeue(Queue *q) {
    if (q->head == NULL) return;

    qItem *aux = q->head;

    if (q->head == q->tail) {
        initQueue(q);
    }
    else {
        q->head = q->head->next;
    }
    free(aux);
}

void showPreOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    showPreOrder(root->left);
    showPreOrder(root->right);
}

void showInOrder(Node *root) {
    if (root == NULL) return;
    showInOrder(root->left);
    printf("%d ", root->data);
    showInOrder(root->right);
}

void showPostOrder(Node *root) {
    if (root == NULL) return;
    showPostOrder(root->left);
    showPostOrder(root->right);
    printf("%d ", root->data);
}

Node* getNewNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(Node **root, int value) {
    Node *newNode = getNewNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    
    Node *fatherNode, *aux = *root;
    while (aux != NULL) {
        fatherNode = aux;
        if (newNode->data >= aux->data) aux = aux->right;
        else aux = aux->left;
    }
    if (newNode->data >= fatherNode->data) fatherNode->right = newNode;
    else fatherNode->left = newNode;
}

Node* recursiveInsert(Node *root, int value) {
    if (root == NULL) root = getNewNode(value);
    else if (value <= root->data) root->left = recursiveInsert(root->left, value);
    else root->right = recursiveInsert(root->right, value);
    return root; 
}

int searchNode(Node *root, int key) {
    if (root == NULL) return 0;
    else if (root->data == key) return 1;
    else if (root->data > key) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

Node* findNode(Node *root, int key) {
    if (root == NULL) return root;
    else if (root->data == key) return root;
    else if (root->data > key) return findNode(root->left, key);
    else return findNode(root->right, key);
}

Node* findMin(Node *root) {
    if (root == NULL) return NULL;
    else if (root->left == NULL) return root;
    return findMin(root->left);
}

Node* findMax(Node *root) {
    if (root == NULL) return NULL;
    else if (root->right == NULL) return root;
    return findMax(root->right);
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int findHeight(Node *root) {
    if (root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;    
}

void levelOrderTraversal(Node *root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while(q.head != NULL) {
        Node *current = q.head->data;
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
        dequeue(&q);
    }
    printf("\n");
}

/*

Solução alternativa para checar se é BST:

int checkBST(Node *root, int fatherData, int isRightNode) {
    if (root == NULL) return 1;

    if (((isRightNode == 0 && fatherData > root->data) || (isRightNode == 1 && fatherData < root->data))
        && checkBST(root->left, root->data, 0)
        && checkBST(root->right, root->data, 1))
        return 1;
    else return 0;
}

int isBST(Node *root) {
    return checkBST(root->left, root->data, 0) && checkBST(root->right, root->data, 1);
}
*/

Node* getSuccessor(Node *root, int data) {
    Node *current = findNode(root, data);
    if (current == NULL) return current;
    if (current->right != NULL) return findMin(current->right);

    Node *sucessor = NULL, *ancestor = root;
    while (ancestor != current) {
        if (ancestor->data > data) {
            sucessor = ancestor;
            ancestor = ancestor->left;
        }
        else ancestor = ancestor->right;
    }
    return sucessor;
}

Node* getPredecessor(Node *root, int data) {
    Node *current = findNode(root, data);
    if (current == NULL) return current;
    if (current->left != NULL) return findMax(current->left);

    Node *predecessor = NULL, *ancestor = root;
    while (ancestor != current) {
        if (ancestor->data > data) ancestor = ancestor->left;
        else {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
    }
    return predecessor;
}

int isBSTutil(Node *root, int minValue, int maxValue) {
    if (root == NULL) return 1;

    if (root->data > minValue && root->data < maxValue
        && isBSTutil(root->left, minValue, root->data)
        && isBSTutil(root->right, root->data, maxValue))
        return 1;
    else return 0;
}

int isBST(Node *root) {
    return isBSTutil(root, INT_MIN, INT_MAX);
}

Node* deleteNode(Node *root, int target) {
    if (root == NULL) return root;

    if (root->data < target) root->right = deleteNode(root->right, target);
    else if (root->data > target) root->left = deleteNode(root->left, target);    
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->right == NULL){
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else if(root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}

int main() {
    Node *root = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int randomNumber = rand() % 100 + 1;
        root = recursiveInsert(root, randomNumber);
    }

    printf("Level order traversal of the tree: ");
    levelOrderTraversal(root);
    printf("Height of the tree: %d\n", findHeight(root));

    int value;
    printf("Now, insert a value to be deleted in the tree: ");
    scanf("%d", &value);
    root = deleteNode(root, value);
    printf("Tree after deletion: ");
    levelOrderTraversal(root);
    printf("Insert a value and we'll find its predecessor and sucessor: ");
    scanf("%d", &value);
    Node *pred = getPredecessor(root, value), *succ = getSuccessor(root, value);
    printf("Predecessor: %d, Successor: %d\n", pred->data, succ->data);


    return 0;
}