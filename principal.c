#include <stdio.h>
#include "produtos.h"

/* ESSE ARQUIVO FOI UTILIZADO SOMENTE PARA O TESTE DAS FUNÇÕES DE PRODUTO
NÃO É A MAIN OFICIAL*/

int main() {

    Produto estoque[10]; 
 
    int q;
    scanf("%d", &q);

    char nome[100];
    int qtd; 
    double preco; 

    for (int i = 0; i < q; i++) {
        scanf("%s", nome);
        scanf("%d", &qtd); 
        scanf("%lf", &preco); 

        Produto *p, prod;
        p = &prod;

        inserir_prod(p, i, nome, 10, qtd, preco);

        estoque[i] = *p;
    }

    for (int i = 0; i < q; i++) {
        printf("%d\t", estoque[i].id); 
        printf("%s\t", estoque[i].nome);
        printf("%d\t", estoque[i].quantidade); 
        printf("%lf\n", estoque[i].preco);
    }
    
    Produto *pont = &estoque[2]; 
    
    double novo; 
    scanf("%lf", &novo); 
    modifica_preco_prod(pont, novo); 

    for (int i = 0; i < q; i++) {
        printf("%d\t", estoque[i].id); 
        printf("%s\t", estoque[i].nome);
        printf("%d\t", estoque[i].quantidade); 
        printf("%lf\n", estoque[i].preco);
    }

    int num; 
    scanf("%d", &num); 
    aumenta_estoque_prod(pont, num);

    for (int i = 0; i < q; i++) {
        printf("%d\t", estoque[i].id); 
        printf("%s\t", estoque[i].nome);
        printf("%d\t", estoque[i].quantidade); 
        printf("%lf\n", estoque[i].preco);
    }

    
    return 0;
}