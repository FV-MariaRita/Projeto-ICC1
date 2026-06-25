/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as declarações das funções utilizadas para gerenciar a memória utilizada pelo sistema. As funções são responsáveis por realizar a alocação dinâmica de memória, de modo que aloca (alocaEstoque() ), realocam (realocaEstoque()) e liberam (liberaEstoque()) essa memória. 

O corpo dessas funções está definido no arquivo gerenciarMemoria.c
*/

#ifndef GERENCIARMEMORIA_H
#define GERENCIARMEMORIA_H

#include "produtos.h"

Produto *alocaEstoque(Produto *estoque, int tam);
Produto *realocaEstoque(Produto *estoque, int *tam);
void liberaEstoque(Produto **estoque);


#endif