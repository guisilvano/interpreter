/*
 * INTERPRETADOR DE GRAMÁTICA - GUILHERME DE NEZ SILVANO
 * UNIVERSIDADE DO EXTREMO SUL CATARINENSE - UNESC 
 *
 * PARA COMPILAR: gcc -Wall main.c interpretador.c gs_stack.c -o interpreter
 *
 * DESENVOLVIDO PARA USO EM SISTEMAS UNIX
 */


#include <stdio.h>
#include <stdlib.h>

#include "interpretador.h"

#define newline printf("\n");

int main (void){

	stack_t pilha;
	init_stack (&pilha);

	scan_gramatica(&pilha);
	
	interpreta_gramatica(&pilha);

	return 0;
}
