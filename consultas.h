/*
Projeto ICC 1 - Mercadinho
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Arquivo de cabeçalho do módulo de consultas.
Contém as declarações das funções utilizadas
para consulta do estoque e do saldo do caixa.
*/

#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "produtos.h"

void consultaEstoque (Produto *estoque,int prodsEstoque);

void consultaSaldoCaixa (double saldoCaixa);

#endif