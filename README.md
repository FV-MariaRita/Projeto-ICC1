# Mercadinho de ICC 

O projeto do mercadinho, programado em C99, foi construído como um dos trabalhos para a disciplina de Introdução à Ciência da Computação do primeiro semestre do Bacharelado em Ciências da Computação na USP São Carlos.

## Alunos 
- Chrystian Eloy de Assunção - [Github Chrystian Eloy](https://github.com/chrystianeloy)
- Júlia Barbosa Nogueira - [Github Julia Nogueira](https://github.com/juliab2nogueira)
- Maria Rita Fagundes Vargas - [Github Maria Rita Vargas](https://github.com/FV-MariaRita)

## Descrição do projeto 

  O projeto é um sistema construído para o gerenciamento de um mercadinho, permitindo a aquisição de produtos, vendas, consultas e demais funcionalidades. Nesse sentido, o sistema, ao ser iniciado, permite que o usuário realize 7 operações: inserir um produto no estoque, aumentar a quantidade de um produto no estoque, modificar o preço de um produto, realizar uma venda, consultar o saldo do caixa, consultar o estoque e finalizar o dia. Cada funcionalidade é acessada por meio do seu respectivo comando, o qual é seguido pelos dados correspondentes àquela operação. Ao final do dia, todos os dados do mercadinho são salvos em um arquivo para que possam ser resgatados no dia seguinte, continuando o funcionamento do estabelecimento. 
  
## Execução localmente 
Para executar o projeto, basta utilizar os comandos make definidos no Makefile presente na raiz do projeto, ou colocar em seu terminal: 

```
gcc -std=c99 -Wall *.c -o exec_mercadinho
```
Para compilar, e o comando a seguir para executar
```
./exec_mercadinho
```
## Organização do código 

Inicialmente, destaca-se que todas as funções e variáveis do código utilizam o seguinte camelCase. Além disso, o arquivo que salva as informações do mercadinho é um arquivo binário de nome "estoque.bin". 

Cada produto do mercadinho é definido por um conjunto de 4 dados: id, nome, preço e quantidade no estoque. Por isso, criamos uma struct com esses 4 dados para definir os produtos do mercadinho. 	

As funções utilizadas dividem-se em 5 arquivos:

- consultas.c -> Esse arquivo contém as funções relativas a consulta do saldo do caixa e do estoque do mercadinho;
- gerenciarMemoria.c -> Esse arquivo contém as funções responsáveis por realizar a alocação dinâmica do estoque, incluindo a alocação, realocação e liberação de memória;
- produtos.c -> Esse arquivo contém as funções responsáveis pela manipulação de produtos no estoque, ou seja, as funcionalidades de incluir, aumentar a quantidade e modificar o preço de produtos;
- venda.c -> Esse arquivo contém as funções que realizam a venda de produtos do mercadinho;
- principal.c -> Esse arquivo contém a main. 

Além disso, buscando evitar a múltipla definição da struct Produto e de funções, criamos arquivos de cabeçalho que previnem o código desse tipo de erro.

- consultas.h -> Contém os protótipos das funções de consultas, definindo-as caso ainda não estejam definidas;
- gerenciarMemoria.h -> Contém os protótipos das funções de gerenciamento de memória;
- produtos.h -> Contém a definição da struct Produto e os protótipos das funções de manipulação de produtos; 
- venda.h -> Contém o protótipo da função de realizar venda.

## As funções de produto 
As funções de produto são referenciadas na main de acordo com seus respectivos códigos inseridos pelo usuário, onde IP representa inserir produto, MP modificar preço no estoque e AE aumentar o estoque. No arquivo produtos.h, temos a definição da struct produto, a qual é composta pelo id, nome, preço e quantidade no estoque desse produto. A seguir, há uma breve explicação das funções utilizadas. 

- void inserirProd() -> Essa função é responsável por inserir o produto digitado pelo usuário no estoque. Ela recebe os dados do produto, que são lidos na main, e os insere no estoque do mercadinho. 

- void modificaPrecoProd() -> Essa função é responsável por modificar o preço de um produto no estoque. Ela recebe o produto, cujo código foi lido na main, e o novo preço que deve ser atribuído a ele, trocando o preço antigo pelo novo. 

- void aumentaEstoqueProd() -> Essa função é responsável por aumentar a quantidade de um produto no estoque. Ela recebe o produto, cujo código foi lido na main, e de quantas unidades a sua quantidade em estoque deve ser acrescida, realizando essa operação. Além disso, essa funcionalidade gera um custo para o mercadinho que gasta dinheiro que tem em caixa para realizar essa operação. Para tal, o desconto do valor no saldo do caixa é realizado na main, logo após a chamada dessa função. 

## As funções de consulta

## A função de venda

## As funções de gerenciamento de memória 

## A main

