/*
 * GUILHERME DE NEZ SILVANO 			  MAR/13/19
 * 
 * UNIVERSIDADE DO EXTREMO SUL CATARINENSE - UNESC
 * PROFESSOR GILBERTO VIEIRA SILVA - LING. FORMAIS
 *
 * INTERPRETADOR GRAMATICAL
 */


#ifndef __INTERP
#define __INTERP


/*
 * BIBLIOTECA PESSOAL PARA IMPLEMENTAÇÃO DE PILHAS
 */
#include "gs_stack.h"


/*
 * INTERPRETA O ELEMENTO NO TOPO DA PILHA.
 * 
 * CASO O ELEMENTO NÃO ESTEJA ATRIBUIDO A NENHUMA LETRA
 * DO ALFABETO, ELE É DADO COMO INVÁLIDO.
 */
void interpreta_elemento (stack_t * head);


/*
 * INTERPRETA TODA A PILHA ELEMENTO POR ELEMENTO UTILIZANDO
 * A FUNÇÃO interpreta_elemento(stack_t).
 */
void interpreta_gramatica (stack_t * head);


/*
 * SCANEIA ENTRADA SENDO ELA QUALQUER STRING.
 *
 * A FUNÇÃO TERMINA QUANDO O USUÁRIO INSERE UM CARACTER VAZIO.
 */
void scan_gramatica (stack_t * head);


#endif