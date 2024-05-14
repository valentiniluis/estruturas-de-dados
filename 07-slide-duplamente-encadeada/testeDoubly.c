#include <stdio.h>
#include <stdlib.h>

struct sxy {
   int x;
   int y;
   struct sxy *next, *prev;
};
typedef struct sxy txy;

struct stag {
   txy *head;
   txy *tail;
};
typedef struct stag ttag;

void init_lista(ttag *t)
{
	t->head=NULL;
	t->tail=NULL;
}

void incluir (ttag *t,int x, int y) {
   txy *new = NULL;
   new = (txy*)malloc(sizeof(txy));
   new->x = x;
   new->y = y;
   new->next = NULL;
   new->prev = NULL;

   if (t->head == NULL) {
      t->head = new;
      t->tail = new;
   }
   else {
      t->tail->next = new;
      new->prev = t->tail;
      t->tail = new;
   }
}

void consultar (ttag t,int x, int y) {
	if (t.head==NULL) {
      printf("Elemento (%d, %d) nao esta na lista.\n", x, y);
		return;
   }

   for (txy *aux = t.head; aux != NULL; aux = aux->next) {
      if (aux->x == x && aux->y == y) {
         printf("Elemento (%d, %d) encontrado!\n", aux->x, aux->y);
         return;
      }
   }
   printf("Elemento (%d, %d) nao esta na lista.\n", x, y);
}

void excluir (ttag *t,int x, int y)
{
	if (t->head==NULL) {
      return;
   }

   txy *aux;
   for (aux = t->head; aux != NULL; aux = aux->next) {
      if (aux->x == x && aux->y == y) {
         if (aux == t->head && aux == t->tail) {
            t->head = NULL;
            t->tail = NULL;
         }
         else if (aux == t->head) {
            aux->next->prev = NULL;
            t->head = aux->next;
         }
         else if (aux == t->tail) {
            aux->prev->next = NULL;
            t->tail = aux->prev;
         }
         else {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
         }
         break;
      }
   }
   free(aux);
}

void lista_todos(ttag t)
{
	if (t.head == NULL) {
      printf("Nenhum elemento na lista.\n");
      return;
   }

   for (txy *aux = t.head; aux != NULL; aux = aux->next) {
      if (aux == t.head) printf("[");
      printf("(%d, %d)", aux->x, aux->y);
      if (aux->next == NULL) printf("]\n");
      else printf(", ");
   }
}

int menu()
{
   int op;
   printf("1 - Incluir\n2 - Consultar\n3 - Excluir\n4 - Listar \n0 - Finalizar\n: ");
   scanf("%d",&op);
   return op;
}
//
int main()
{
   ttag tag;
   int op, x,y;
   init_lista(&tag);
   op=menu();
   while (op!=0) {
      switch(op) {
         case 1: 
            scanf("%d %d",&x,&y);
            incluir(&tag,x,y);
            break;
         case 2:
            scanf("%d %d",&x,&y);
            consultar(tag,x,y);
            break;
         case 3:
            scanf("%d %d",&x,&y);
            excluir(&tag,x,y);
            break;
         case 4:
            lista_todos(tag);
            break;
      }
      op=menu();
   }
   return 0;
}
