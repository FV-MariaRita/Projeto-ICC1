/*
Projeto ICC 1 - Mercadinho 
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as funções de consultas ao sitema, as quais além de buscar informações do mercadinho, as exibe no terminal: 

    - void consultaEstoque : responsável por consultar o estoque do sistema
    - void consultaSaldo: responsável por consultar o saldo do caixa

As informações consultadas serão exibidas no formato 

Consulta estoque: 

<código>_<nome>_<quantidade no estoque>
...
<código>_<nome>_<quantidade no estoque>
--------------------------------------------------

Consulta saldo:

Saldo:_<saldo do caixa>
--------------------------------------------------
*/

#include <stdio.h>
#include "consultas.h"
#include "produtos.h"

// Imprime o estoque completo do mercado.

void consultaEstoque (Produto *estoque, int prodsEstoque) {

    for (int i = 0; i < prodsEstoque; i++) {

        printf("%d %s %d\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade);
    }

    for (int i = 0; i < 50; i++) {
        printf("-");
    }

    printf("\n");
}

// Imprime o saldo atual do caixa.

void consultaSaldoCaixa(double saldoCaixa) {

    printf("Saldo: %.2lf\n", saldoCaixa);

    for (int i = 0; i < 50; i++) {
        printf("-");
    }

    printf("\n");
}