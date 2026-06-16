/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as funções relativas à manipulação dos produtos no estoque, a saber: 

    - void inserir_prod : responsável por inserir um novo produto no estoque
    - void modifica_preco_prod : responsável por modificar o preço de um produto no estoque
    - void aumenta_estoque_prod: responsável por aumentar a quantidade de um produto no estoque
*/

#include "produtos.h"

void inserir_prod(Produto *prod, int id, char nome[150], int tamNome, int qtd, double preco) {

    prod->id = id;
    
    for (int i = 0; i < tamNome; i++) {
        prod->nome[i] = nome[i];
    }
    prod->quantidade = qtd; 
    prod->preco = preco; 

}

void modifica_preco_prod (Produto *prod, double novoPreco) {

    prod->preco = novoPreco;

}

void aumenta_estoque_prod (Produto *prod, int qtd) {

    prod->quantidade += qtd;

}