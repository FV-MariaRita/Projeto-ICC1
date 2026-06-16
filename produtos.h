/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém a definição da struct produto cujos atributos são id, nome, quantidade e preço.
Além disso, também há o protótipo das funções relativas 
à manipulação dos produtos no estoque, a saber: 

    - void inserir_prod : responsável por inserir um novo produto no estoque
    - void modifica_preco_prod : responsável por modificar o preço de um produto no estoque
    - void aumenta_estoque_prod: responsável por aumentar a quantidade de um produto no estoque
*/


#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct produto {
    int id;
    char nome[150]; 
    int quantidade; 
    double preco;
} Produto;

void inserir_prod(Produto *prod, int id, char nome[150], int tamNome, int qtd, double preco); 
void modifica_preco_prod (Produto *prod, double novoPreco); 
void aumenta_estoque_prod (Produto *prod, int qtd); 

#endif