/*
 * GUILHERME DE NEZ SILVANO 			MAR/13/2019
 *
 * BIBLIOTECA PARA IMPLEMENTAÇÃO DE STACKS (PILHAS)
 * PARA MANIPULAÇÃO DE VALORES INTEIROS.
 *
 * PARA USO EM SISTEMAS UNIX.
 */


#ifndef __GS_STACK
#define __GS_STACK

/*
 * DISPONÍVEL EM https://github.com/freebsd/freebsd/blob/master/sys/sys/queue.h
 */
#include <sys/queue.h>


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
void push (int n, stack_t * head);


/*
 * REMOVE E RETORNA O VALOR INTEIRO DO TOPO DA PILHA.
 */
int pop (stack_t * head);


/*
 * IMPRIME OS VALORES CONTIDOS NA PILHA E SUAS POSIÇÕES
 * SENDO QUE 0 -> TOPO.
 */
void print_stack (stack_t * head);


/*
 * INICIA PILHA COM UM NÓ NULO.
 */
void init_stack (stack_t * head);


/* 
 * RETORNA UM TIPO int COM O NUMERO DE ELEMENTOS DA PILHA.
 * RETORNA -1 CASO A PILHA ESTEJA VAZIA.
 */
int stack_size(stack_t * head);


#endif
