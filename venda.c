/*
Projeto ICC 1 - Mercadinho
Alunos: Chrystian Eloy, Julia Nogueira, Maria Rita Vargas

Esse arquivo contém as funções relacionadas ao processo de
vendas do mercadinho, incluindo a busca de produtos no estoque,
a atualização das quantidades vendidas e do saldo do caixa.
*/

#include <stdio.h>
#include "venda.h"
#include "produtos.h"

/*
    Procura um produto no estoque a partir do seu código.
    Retorna:
    - Ponteiro para o produto encontrado.
    - NULL caso não encontre.
*/
static Produto *buscarProduto(Produto *estoque, int prodsEstoque, int codigo) {
    for (int i = 0; i < prodsEstoque; i++) {
        if (estoque[i].id == codigo) {
            return &estoque[i];
        }
    }

    return NULL;
}

/*
    Realiza uma venda.
    Lê os códigos dos produtos até encontrar -1,
    imprime os itens vendidos, atualiza o estoque
    e soma o valor total ao saldo do caixa.
*/
void realizarVenda(Produto *estoque, int prodsEstoque, double *saldoCaixa) {

    int codigo;
    double total = 0.0;

    scanf("%d", &codigo);

    while (codigo != -1) {

        Produto *prod =
            buscarProduto(estoque, prodsEstoque, codigo);

        
        if (prod != NULL) {

            if ((*prod).quantidade > 0) {

                printf("%s %.2lf\n", (*prod).nome, (*prod).preco);
                (*prod).quantidade--;
                total += (*prod).preco;

            }
        }
        
        scanf("%d", &codigo);
    }

    *saldoCaixa += total;

    printf("Total: %.2lf\n", total);

    for (int i = 0; i < 50; i++) {
        printf("-");
    }

    printf("\n");
}

