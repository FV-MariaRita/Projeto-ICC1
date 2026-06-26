/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as funções utilizadas para gerenciar a memória utilizada pelo sistema.
São elas: 

    - Produto *alocaEstoque() : responsável por alocar dinamicamente o estoque, abortando o programa em caso de falha 
    - Produto *realocaEstoque() : responsável por realocar dinamicamente o estoque, aumentando seu tamamho em 10 espaços para novos produtos. 
    Aborta o programa e libera a memória já ocupada em caso de falha
    - void liberaEstoque() : responsável por liberar a memória alocada para o estoque 
*/


#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"
#include "gerenciarMemoria.h"


Produto *alocaEstoque(Produto *estoque, int tam) {
    Produto *temp; 
    temp = (Produto *) malloc(tam * sizeof(Produto)); 

    if (temp == NULL)
        exit(1); 
    
    return temp;
}


Produto *realocaEstoque(Produto *estoque, int *tam) {
    Produto *temp; 
    *tam = *tam + 10;
    temp = (Produto *) realloc(estoque, *tam * sizeof(Produto)); 

    if (temp == NULL) {
        liberaEstoque(&estoque); 
        exit(1);
    }

    return temp;
}

void liberaEstoque(Produto **estoque) {
    
    if (estoque != NULL && *estoque != NULL) {
        free(*estoque);
        *estoque = NULL; 
    }
    
}