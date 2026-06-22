/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as declarações das funções utilizadas para realizar vendas e manipular os dados
necessários para o processamento das operações de venda do sistema.
 
*/

#ifndef VENDAS_H
#define VENDAS_H

#include "produtos.h"

void realizarVenda(Produto *estoque, int prodsEstoque, double *saldoCaixa);

#endif