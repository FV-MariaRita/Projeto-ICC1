#include <stdio.h>
#include "produtos.h"


Produto *alocaEstoque(Produto *estoque, int tam) {
    Produto *temp; 
    temp = (Produto *) malloc(tam * sizeof(Produto)); 

    if (temp == NULL)
        exit(1); 
    
    return temp;
}


Produto *realocaEstoque(Produto *estoque, int *tam) {
    Produto *temp; 
    *tam = *tam + 10;
    temp = (Produto *) realloc(estoque, *tam * sizeof(Produto)); 

    if (temp == NULL) {
        liberaEstoque(estoque); 
        exit(1);
    }

    return temp;
}

void liberaEstoque(Produto *estoque) {
    free(estoque);
    estoque = NULL; 
}