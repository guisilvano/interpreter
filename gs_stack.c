/*
 * GUILHERME DE NEZ SILVANO 			MAR/13/2019
 *
 * BIBLIOTECA PARA IMPLEMENTAÇÃO DE STACKS (PILHAS)
 * PARA MANIPULAÇÃO DE VALORES INTEIROS.
 *
 * PARA USO EM SISTEMAS UNIX.
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>


/*
 * DEFINE SAÍDA DE DIAGNÓSTICO (DEBUG).
 */
#define VERBOSE 0


/*
 *ESTRUTURA DOS NÓS DA PILHA.
 *"int num" É NECESSÁRIO PARA O FUNCIONAMENTO DE pop(stack_t).
 */
struct node {
	int num;
	SLIST_ENTRY(node) next;
} *np;


/*
 *DEFINE O TIPO DE VARIÁVEL stack_t.
 */
typedef SLIST_HEAD (head, node) stack_t;


/*
 * INSERE UM VALOR INTEIRO NO TOPO DA PILHA.
 */
void push(int n, stack_t * head){

	struct node *np;
	np = malloc(sizeof(struct node));
	np->num = n;

	if (VERBOSE == 1) 
		printf("\nPUSH \t%c\t%d\tONTO ADDR\t%p", n, n, np);
	
	SLIST_INSERT_HEAD(head, np, next);

}


/*
 * REMOVE E RETORNA O VALOR INTEIRO DO TOPO DA PILHA.
 */
int pop (stack_t * head){
	
	struct node *np;
	np = malloc(sizeof(struct node));
	np = SLIST_FIRST(head);

	int n = np->num;

	if (np == NULL){
		printf("\npop: PILHA VAZIA");
		return -1;

	} else {
		if (VERBOSE == 1) 
			printf("\nPOP\t%c\t%d\tFROM ADDR\t%p", np->num,  np->num, np);

		SLIST_REMOVE_HEAD(head, next);
	}
	
	return n;
}


/*
 * IMPRIME OS VALORES CONTIDOS NA PILHA E SUAS POSIÇÕES
 * SENDO QUE 0 -> TOPO.
 */
void print_stack (stack_t * head){
	
	struct node *np;
	np = malloc(sizeof(struct node));

	if (SLIST_EMPTY(head)){
		printf("\nprint_stack: PILHA VAZIA");
	
	} else {
		int cont = 0;
		
		SLIST_FOREACH(np, head, next){		
			printf("\nPOS %d\t%c\t%d\tON ADDR\t\t%p", cont, np->num, np->num, np);

			cont++;
		}		
	}
}


/*
 * INICIA PILHA COM UM NÓ NULO.
 */
void init_stack (stack_t * head){
	
	//caso não esteja iniciada, inicia pilha
	if (!SLIST_EMPTY(head)) SLIST_INIT(head);

}


/* 
 * RETORNA UM TIPO int COM O NUMERO DE ELEMENTOS DA PILHA.
 * RETORNA -1 CASO A PILHA ESTEJA VAZIA.
 */
int stack_size(stack_t * head){
	
	if (!SLIST_EMPTY(head)){
	
		int tam = 0;

		struct node *np;
		np = malloc(sizeof(struct node));

		SLIST_FOREACH(np, head, next){
			tam++;
		}

		return tam;	

	} else {
		if (VERBOSE == 1)
			printf("\ntamanho_pilha: PILHA VAZIA");

		return -1;
	}
}
