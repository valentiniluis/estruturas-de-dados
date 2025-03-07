#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Crie as estruturas indicadas, e crie o primeiro funcionário da lista encadeada;
Adicione um segundo funcionário mantendo o encadeamento;
Crie uma função que receba o ponteiro inicial da lista e imprima todos os elementos (funcionários)
O programa deve ler (do teclado) vários registros de funcionários (quando id for igual a 0 a entrada é finalizada).
Use a mesma função implementada anteriormente e imprima a lista para ver se todos os elementos estão presentes
Crie uma função para desalocar a memória de todas as instâncias de funcionário (nós da lista). 
Super desafio: crie uma nova função que imprime a lista na ordem inversa
*/

struct date {
    int day, month, year;
};
typedef struct date Date;

struct employee {
    int id;
    char name[41];
    double income;
    Date dbirth;
    struct employee *next;
};
typedef struct employee Employee;

void printEmployees(Employee*);
void freeEmployeeList(Employee**);
void printEmployeesReversed(Employee*);

int main() {
    Employee *head = NULL, *aux, *e;
    int inputValido = 1;

    while (inputValido) {
        e = (Employee*)malloc(sizeof(Employee));
        printf("ID: ");
        scanf("%d", &e->id);

        if (e->id == -1) {
            inputValido = 0;
            continue;
        }

        //printf("Nome: ");
        //scanf(" %s", e->name);
        //printf("Renda: ");
        //scanf("%lf", &e->income);
        //printf("Aniversario (dia, mes e ano separados por espaco): ");
        //scanf("%d%d%d", &e->dbirth.day, &e->dbirth.month, &e->dbirth.year);
        strcpy(e->name, "nome");
        e->income = 1000.50;
        e->dbirth.day = 1;
        e->dbirth.month = 1;
        e->dbirth.year = 2000;        
        e->next = NULL;
        if (head == NULL) {
            head = e;
            aux = e;
        }
        else {
            aux->next = e;
            aux = aux->next;
        }
    }
    freeEmployeeList(&e);


    if (head != NULL) {
        printf("Empregrados registrados:\n");
        printEmployees(head);
        //printf("Empregados registrados em ordem reversa:\n");
        //printEmployeesReversed(head);
        freeEmployeeList(&head);
        printf("Lista encadeada foi limpada da memória.\n");    
    }
    else {
        printf("Nenhum empregado foi registrado.\n");
    }

    return 0;
}

void printEmployees(Employee *emp1) {
    for (Employee *aux = emp1; aux != NULL; aux = aux->next) {
        printf("ID: %d, Nome: %s, Renda: $%.2f, Aniversario: %d/%d/%d\n", aux->id, aux->name, aux->income, aux->dbirth.day, aux->dbirth.month, aux->dbirth.year);
    }
}

void printEmployeesReversed(Employee *emp1) {
    if (emp1 == NULL) return;

    if (emp1->next != NULL) printEmployeesReversed(emp1->next);
    printf("ID: %d, Nome: %s, Renda: $%.2f, Aniversario: %d/%d/%d\n", emp1->id, emp1->name, emp1->income, emp1->dbirth.day, emp1->dbirth.month, emp1->dbirth.year);
}

void freeEmployeeList(Employee **emp1) {
    Employee *aux = NULL;
    for (aux = *emp1; aux != NULL;) {
        Employee *temporario = aux;
        aux = aux->next;
        free(temporario);
    }
    *emp1 = NULL;
}