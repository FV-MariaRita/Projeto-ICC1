/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as funções relativas à manipulação dos produtos no estoque, a saber: 

    - void inserir_prod : responsável por inserir um novo produto no estoque
    - void modifica_preco_prod : responsável por modificar o preço de um produto no estoque
    - void aumenta_estoque_prod: responsável por aumentar a quantidade de um produto no estoque
*/


#include "produtos.h"
#include <string.h>

void inserir_prod(Produto *prod, int id, const char *nome, int qtd, double preco) {

    (*prod).id = id;
    
    strncpy( (*prod).nome, nome, sizeof( (*prod).nome ) - 1);
    (*prod).nome[sizeof( (*prod).nome ) - 1] = '\0';

    (*prod).quantidade = qtd; 
    (*prod).preco = preco; 

}

void modifica_preco_prod (Produto *prod, double novoPreco) {

    (*prod).preco = novoPreco;

}

void aumenta_estoque_prod (Produto *prod, int qtd) {

    (*prod).quantidade += qtd;

}