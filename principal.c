#include <stdio.h>
#include <string.h>
#include "produtos.h"
#include "gerenciarMemoria.h"
#include "venda.h"


int main() {

    //Variáveis do programa -> estoque e saldo
    Produto *estoque = NULL;
    int prodsEstoque;
    int tamEstoque; 
    double saldoCaixa;

    //Início do dia
    FILE *arquivo = fopen("estoque.bin", "rb"); 

    if (arquivo == NULL) {
        saldoCaixa = 100; 

        scanf("%d", &tamEstoque); 
        estoque = alocaEstoque(estoque, tamEstoque);
        prodsEstoque = 0; 
    }

    else {
        fread(&saldoCaixa, sizeof(double), 1, arquivo);
        fread(&prodsEstoque, sizeof(int), 1, arquivo);

        tamEstoque = prodsEstoque;

        estoque = alocaEstoque(estoque, tamEstoque);
        fread(estoque, sizeof(Produto), prodsEstoque, arquivo);

        fclose(arquivo);
    }
    

    //Operação do sistema
    char oper[3];
    scanf("%s", oper);    

    //Roda o programa até o dia finalizar
    while ( !(strcmp(oper, "FE") == 0) ) {
        
        //Inserir produto
        if (strcmp(oper, "IP") == 0) {

            char nome[30];
            int qtd; 
            double preco;

            scanf("%s", nome);
            scanf("%d", &qtd); 
            scanf("%lf", &preco);

            if (prodsEstoque >= tamEstoque) 
                estoque = realocaEstoque(estoque, &tamEstoque); 
            
                
            Produto *p, prod;
            p = &prod;

            inserirProd(p, prodsEstoque, nome, qtd, preco);

            estoque[prodsEstoque] = *p;
            prodsEstoque++;           

        }

        //Aumentar a quantidade de um produto no estoque
        else if (strcmp(oper, "AE") == 0) {
            
            int codigo, qtd;
            Produto *prod = NULL;

            scanf(" %d %d", &codigo, &qtd); 
            
            for (int i = 0; i < prodsEstoque; i++) {
                if (estoque[i].id == codigo) {
                    prod = &estoque[i];
                    break;
                }
            }

            if (prod != NULL)
                aumentaEstoqueProd(prod, qtd);
        }

        //Modifica o preço de um produto no estoque
        else if (strcmp(oper, "MP") == 0) {
            
            int codigo;
            double precoNovo; 
            Produto *prod = NULL;

            scanf(" %d %lf", &codigo, &precoNovo); 
            
            for (int i = 0; i < prodsEstoque; i++) {
                if (estoque[i].id == codigo) {
                    prod = &estoque[i];
                    break;
                }
            }

            if (prod != NULL)
                modificaPrecoProd(prod, precoNovo);
        } 


        //Realizar a venda dos produtos
        else if (strcmp(oper, "VE") == 0) {
            
            realizarVenda(estoque, prodsEstoque, &saldoCaixa);    
        }

        //Consultar o estoque
        else if (strcmp(oper, "CE") == 0) {

        }

        //Consultar o saldo
        else if (strcmp(oper, "CS") == 0) {

        }


        scanf("%s", oper);
    }
    
    //Finalizar o dia
    arquivo = fopen("estoque.bin", "wb");

    if (arquivo == NULL) {
        liberaEstoque(&estoque); 
        return 1;
    }

    fwrite (&saldoCaixa, sizeof(double), 1, arquivo); 
    fwrite (&prodsEstoque, sizeof(int), 1, arquivo); 
    fwrite (estoque, sizeof(Produto), prodsEstoque, arquivo); 

    fclose(arquivo);

    liberaEstoque(&estoque);

    return 0;
}
