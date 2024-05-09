#include <stdio.h>
#include <stdlib.h>

/*
a) Implemente a função Funcionario *insAfter(Funcionario *first, Funcionario *f, int id), que inclui um novo elemento na lista
após a posição do elemento com o valor do id passado como parâmetro.

b) Você deverá implementar a função Funcionario *insBefore(Funcionario *first, Funcionario *f, int id) que irá inserir o elemento
na posição anterior (antes) da posição do elemento com o valor do id.

extras:
c) crie uma função para imprimir todos os elementos da lista encadeada.
d) crie uma função para inserir um elemento num dado index (baseado em posição do elemento, não id) da lista.
e) crie uma função para inserir um elemento no final da lista.
f) crie uma função para excluir um elemento com certo id da lista.
g) crie uma função para excluir um elemento com base no seu index na lista.
h) crie uma função ou propriedade que guarde o tamanho da lista encadeada.
i) lembre-se de liberar a memória alocada ao final do programa.
*/

struct SFuncionario {
    int id;
    char nome[41];
    double salario;
    struct SFuncionario* next;
};
typedef struct SFuncionario Funcionario;

void insAfter(Funcionario** head, Funcionario *f, int id);
void insBefore(Funcionario** head, Funcionario *f, int id);
void printEmployees(Funcionario* head);
void insertAtIndex(Funcionario **head, Funcionario *f, int index);
void pushNode(Funcionario **head, Funcionario *f);
void removeNodeById(Funcionario **head, int id);
void popNode(Funcionario **head, int index);
int getListLength(Funcionario *head);
void freeLinkedList(Funcionario **head);

int main() {
    Funcionario *head = NULL;

    int qtd;
    printf("quantos elementos quer inserir? ");
    scanf("%d", &qtd);
    
    for (int i = 1; i <= qtd; i++) {
        Funcionario *new = (Funcionario *)malloc(sizeof(Funcionario));
        new->id = i;
        printf("Nome do funcionario #%d: ", i);
        scanf(" %s", new->nome);
        new->salario = i * 1500;
        pushNode(&head, new);
    }

    printEmployees(head);
    printf("Comprimento da lista: %d\n", getListLength(head));
    freeLinkedList(&head);

    return 0;
}


void insAfter(Funcionario** head, Funcionario *f, int id) {
    if (*head == NULL) {
        *head = f;
        return;
    }
    
    Funcionario* temp;
    for (temp = *head; temp->next != NULL; temp = temp->next) {
        if (temp->id == id) break;
    }
    f->next = temp->next;
    temp->next = f;
}


void insBefore(Funcionario **head, Funcionario *f, int id) {
    if (*head == NULL || (*head)->id == id) {
        f->next = *head;
        *head = f;
        return;
    }

    Funcionario *temp;
    for (temp = *head; temp->next != NULL; temp = temp->next) {
        if (temp->next != NULL && temp->next->id == id) break;
    }
    f->next = temp->next;
    temp->next = f;
}


void printEmployees(Funcionario* head) {
    for (Funcionario* aux = head; aux != NULL; aux = aux->next) {
        printf("ID: %d, nome: %s, salario: R$%.2f\n", aux->id, aux->nome, aux->salario);
    }
}


void insertAtIndex(Funcionario **head, Funcionario *f, int index) {
    if (*head == NULL || index == 0) {
        f->next = *head;
        *head = f;
        return;
    }

    int i;
    Funcionario *aux = *head;
    for (i = 0; i < index-1; i++) {
        if (aux->next == NULL) {
            f->next = aux->next;
            aux->next = f;
            return;
        }
        aux = aux->next;
    }
    f->next = aux->next;
    aux->next = f;
}


void pushNode(Funcionario **head, Funcionario *f) {
    if (*head == NULL) {
        *head = f;
        return;
    }
    
    Funcionario *aux = *head;
    while (aux->next != NULL) aux = aux->next;
    aux->next = f;
}


void removeNodeById(Funcionario **head, int id) {
    if (*head == NULL) return;

    Funcionario *aux, *previous;
    for (aux = *head; aux->next != NULL; aux = aux->next) {
        if (aux->id == id && aux == *head) {
            *head = aux->next;
            break;
        }
        else if (aux->id == id) {
            previous->next = aux->next;
            break;
        }
        previous = aux;
    }
    if (aux->next == NULL) {
        previous->next = NULL;
    }
    free(aux);
}


void popNode(Funcionario **head, int index) {
    Funcionario *aux = *head, *previous;
    
    if (*head == NULL) return;
    else if (index == 0) {
        *head = aux->next;
        free(aux);
        return;
    }

    int i = 0;
    for (aux = *head; aux->next != NULL; aux = aux->next) {
        if (index == i) {
            previous->next = aux->next;
            break;
        }
        previous = aux;
        i++;
    }
    if (aux->next == NULL) {
        previous->next = NULL;
    }
    free(aux);
}


int getListLength(Funcionario *head) {
    int i = 0;
    for (Funcionario *aux = head; aux != NULL; aux = aux->next) i++;
    return i;
}


void freeLinkedList(Funcionario **head) {
    Funcionario *aux = *head, *e = *head;
    for (; e != NULL; aux = e) {
        e = e->next;
        free(aux);    
    }
    *head = NULL;
}