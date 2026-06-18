#include <stdio.h>
#include "produtos.h"


int main() {

    //parte dos arquivos

    //estoque
    Produto estoque[10];
    int prodsEstoque = 0;

    //caracteres de operação
    char op1, op2;
    
    //leitura do primeiro comando do programa
    scanf(" %c %c", &op1, &op2);

    //roda o programa até o dia finalizar
    while (op1 != 'F' && op2 != 'E') {
        
        //inserir produto
        if (op1 == 'I' && op2 == 'P') {

            char nome[30];
            int qtd; 
            double preco;

            scanf("%s", nome);
            scanf("%d", &qtd); 
            scanf("%lf", &preco); 

            Produto *p, prod;
            p = &prod;

            inserir_prod(p, prodsEstoque, nome, qtd, preco);

            estoque[prodsEstoque] = *p;
            prodsEstoque++;           

        }

        //alterar a quantidade no estoque
        else if (op1 == 'A' && op2 == 'E') {
            
            int codigo, qtd;
            Produto *prod;

            scanf(" %d %d", &codigo, &qtd); 
            
            for (int i = 0; i <= prodsEstoque; i++) {
                if (estoque[i].id == codigo) {
                    prod = &estoque[i];
                    break;
                }
            }

            aumenta_estoque_prod(prod, qtd);
        }

        //modifica o preço do produto;
        else if (op1 == 'M' && op2 == 'P') {
            
            int codigo;
            double precoNovo; 
            Produto *prod;

            scanf(" %d %lf", &codigo, &precoNovo); 
            
            for (int i = 0; i <= prodsEstoque; i++) {
                if (estoque[i].id == codigo) {
                    prod = &estoque[i];
                    break;
                }
            }

            modifica_preco_prod(prod, precoNovo);

        }

        



        scanf(" %c %c", &op1, &op2);
    }
    

    
    return 0;
}





/*
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
*/