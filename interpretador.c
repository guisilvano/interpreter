/*
 * GUILHERME DE NEZ SILVANO 			  MAR/13/19
 * 
 * UNIVERSIDADE DO EXTREMO SUL CATARINENSE - UNESC
 * PROFESSOR GILBERTO VIEIRA SILVA - LING. FORMAIS
 *
 * INTERPRETADOR GRAMATICAL
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gs_stack.h"


/*
 * DEFINE SAÍDA DE DIAGNÓSTICO (DEBUG).
 *
 * CASO 1, DEFINIR VERBOSE 1 EM gs_stack.c
 */
#define VERBOSE 0


/*
 * INTERPRETA O ELEMENTO NO TOPO DA PILHA.
 * 
 * CASO O ELEMENTO NÃO ESTEJA ATRIBUIDO A NENHUMA LETRA
 * DO ALFABETO, ELE É DADO COMO INVÁLIDO.
 */
int interpreta_elemento (int n){
	
	// caso "n" seja terminal (letra minúscula)
	if (n <= 122 && n >= 97) {
		if (VERBOSE == 1)
			printf("\t%c T", n);
		
		return n;

	// caso "n" seja não-terminal (letra maiúscula)	
	} else if (n <= 90 && n >= 65) {
		if (VERBOSE == 1)
			printf("\t%c NT", n);

		return 666;

	// caso "n" seja um algarismo entre 0 e 9
	} else if (n <= 57 && n >= 48){
		if (VERBOSE == 1)
			printf("\t%c T", n);

		return n;

	} else {
		if (VERBOSE == 1)
			printf("\tCARACTER INVÁLIDO!");

		return -1;
	}
}


/*
 * INTERPRETA TODA A PILHA ELEMENTO POR ELEMENTO UTILIZANDO
 * A FUNÇÃO interpreta_elemento(stack_t).
 */
void interpreta_gramatica (stack_t * head){
	
	char elemento;
	char sentenca[255];

	if (SLIST_EMPTY(head)){
		if (VERBOSE == 1)
			printf("\ninterpreta_gramatica: PILHA VAZIA");
		return;
	}
		
	if (VERBOSE == 1)
		printf("\nPILHA: %d ELEMENTOS", stack_size(head));
	
	int cont = 0;
	
	while (!SLIST_EMPTY(head)){
		elemento = (char) interpreta_elemento(pop(head));
		sentenca[cont] = elemento;
		
		cont++;
	}
	
	// termina string com caracter nulo
	sentenca[cont] = '\0';
	printf("%s", sentenca);
}



/*
 * SCANEIA ENTRADA SENDO ELA QUALQUER STRING.
 *
 * A FUNÇÃO TERMINA QUANDO O USUÁRIO INSERE UM CARACTER VAZIO.
 */
void scan_gramatica(stack_t * head){

	char elemento_s[255];
	int elemento_i = 0;

	while (elemento_i != 10){
	
		printf("\nNOVO(S) ELEMENTO(S): ");
		
		if (fgets(elemento_s, sizeof elemento_s, stdin) == NULL){
			fprintf(stderr, "ERRO LENDO ELEMENTO");
			exit(1);
		
		} else if (elemento_s[0] == 10){	
			printf("\033[AENTRADA FINALIZADA  ");
			break;
		}

		for (int i=0; i<(strlen(elemento_s))-1; i++){
			elemento_i = (int) elemento_s[i];
			push(elemento_i, head);
		}

		fflush(stdin);
	}
}
