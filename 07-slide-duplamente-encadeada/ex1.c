#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1)
a) Crie uma lista e o primeiro funcionário da lista, considerando as estruturas indicadas;
b) Adicione um segundo funcionário no início da lista;
c) Crie uma função capaz de imprimir todos os funcionários.

2)
a) O programa deve ler (do teclado) um inteiro N que representará o número de registros
que o usuário irá inserir. Após a leitura seu programa deve ler os dados dos N registros
e os inserir no final na lista encadeada. 
b) Imprima a lista para ver se todos os elementos estão presentes
c) Faça uma função que deleta um funcionário. A função deve receber como parâmetro a lista,
e o id do funcionário a ser deletado, e deve retornar o first elemento da lista.

4)
Crie uma função de busca que apresenta (imprime na tela) as informações de um funcionário.
A busca deve ser feita utilizando o id.
*/

struct TData {
    int dia, mes, ano;
};
typedef struct TData Data;

struct TFuncionario {
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct TFuncionario *prev, *next;
};
typedef struct TFuncionario Funcionario;

struct TPonteiros {
    Funcionario *head, *tail;
};
typedef struct TPonteiros Ponteiro;

void procurarFuncionario(Ponteiro p, int id);
void imprimirFuncionarios(Ponteiro p);
void inserirInicio(Ponteiro *p, Funcionario *new);
void inserirFinal(Ponteiro *p, Funcionario *new);
void deletarPorId(Ponteiro *p, int id);
Funcionario* gerarFuncionario();

int main() {
    Ponteiro p = {NULL, NULL};
    
    int qtdFunc;
    printf("Quantidade de funcionarios: ");
    scanf("%d", &qtdFunc);

    for (int i = 0; i < qtdFunc; i++) {
        Funcionario *novo = gerarFuncionario();
        inserirFinal(&p, novo);
    }

    imprimirFuncionarios(p);

    int deleteId;
    printf("excluir id: ");
    scanf("%d", &deleteId);
    deletarPorId(&p, deleteId);
    printf("Apos exclusao:\n");
    imprimirFuncionarios(p);

    int idProcurar;
    printf("Id a procurar: ");
    scanf("%d", &idProcurar);
    procurarFuncionario(p, idProcurar);

    return 0;
}

void imprimirFuncionarios(Ponteiro p) {
    for (Funcionario *aux = p.head; aux != NULL; aux = aux->next) {
        printf("Id: %d, nome: %s, salario: R$%.2f, nascimento: %d/%d/%d\n", aux->id, aux->nome, aux->salario, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
    }
}

Funcionario* gerarFuncionario() {
    Funcionario *f = (Funcionario*)malloc(sizeof(Funcionario));
    printf("id: ");
    scanf("%d", &f->id);
    printf("Nome: ");
    scanf("%*[^\n]"); scanf("%*c");
    fgets(f->nome, 41, stdin);
    f->nome[strcspn(f->nome, "\n")] = 0;
    printf("Salario: ");
    scanf("%lf", &f->salario);
    printf("Nascimento (dia, mes, ano, separados por espaco): ");
    scanf("%d%d%d", &f->nascimento.dia, &f->nascimento.mes, &f->nascimento.ano);
    f->next = NULL;
    f->prev = NULL;
    return f;
}

void inserirInicio(Ponteiro *p, Funcionario *new) {
    if (p->head == NULL) {
        p->head = new;
        p->tail = new;
        return;
    }
    p->head->prev = new;
    new->next = p->head;
    p->head = new;
}

void inserirFinal(Ponteiro *p, Funcionario *new) {
    if (p->tail == NULL) {
        p->head = new;
        p->tail = new;
        return;
    }
    new->prev = p->tail;
    p->tail->next = new;
    p->tail = new;
}

void deletarPorId(Ponteiro *p, int id) {
    Funcionario *aux;
    for (aux = p->head; aux != NULL; aux = aux->next) {
        if (aux->id == id) {
            if (aux == p->head && aux == p->tail) {
                p->head = NULL;
                p->tail = NULL;
                break;
            }
            else if (aux == p->head) {
                aux->next->prev = NULL;
                p->head = aux->next;
                break;
            }
            else if (aux == p->tail) {
                aux->prev->next = NULL;
                p->tail = aux->prev;
                break;
            }
            else {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                break;
            }
        }
    }
    if (aux != NULL) free(aux);
}

void procurarFuncionario(Ponteiro p, int id) {
    Funcionario *aux;
    for (aux = p.head; aux != NULL; aux = aux->next) {
        if (aux->id == id) {
            printf("Funcionario encontrado:\n");
            printf("Id: %d, nome: %s, salario: R$%.2f, nascimento: %d/%d/%d\n", aux->id, aux->nome, aux->salario, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
            break;
        }
    }
    if (aux == NULL) {
        printf("Funcionario nao encontrado.\n");
    }
}
