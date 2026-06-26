                                        -------------------------------------MERCADINHO de ICC 1--------------------------------------------------------------

O projeto do mercadinho, programado em C99, foi construído como um dos trabalhos para a disciplina de Introdução à Ciência da Computação do primeiro semestre do Bacharelado em Ciências da Computação na USP São Carlos. 

---ALUNOS---

- Chrystian Eloy de Assunção - 18115512
- Júlia Barbosa Nogueira - 17901347
- Maria Rita Fagundes Vargas - 17912857


---DESCRIÇÃO DO PROJETO ---

	O projeto é um sistema construído para o gerenciamento de um mercadinho, permitindo a aquisição de produtos, vendas, consultas e demais funcionalidades. Nesse sentido, o sistema, ao ser iniciado, permite que o usuário realize 7 operações: inserir um produto no estoque, aumentar a quantidade de um produto no estoque, modificar o preço de um produto, realizar uma venda, consultar o saldo do caixa, consultar o estoque e finalizar o dia. Cada funcionalidade é acessada por meio do seu respectivo comando, o qual é seguido pelos dados correspondentes àquela operação. Ao final do dia, todos os dados do mercadinho são salvos em um arquivo para que possam ser resgatados no dia seguinte, continuando o funcionamento do estabelecimento. 

	Para executar o projeto, basta utilizar os comandos make definidos no Makefile presente na raiz do projeto, ou colocar em seu terminal: 

gcc -std=c99 -Wall *.c -o exec_mercadinho

Para compilar, e o comando a seguir para executar

./exec_mercadinho


---ORGANIZAÇÃO DO CÓDIGO---

	Inicialmente, destaca-se que todas as funções e variáveis do código utilizam o seguinte camelCase. Além disso, o arquivo que salva as informações do mercadinho é um arquivo binário de nome "estoque.bin". 

	Cada produto do mercadinho é definido por um conjunto de 4 dados: id, nome, preço e quantidade no estoque. Por isso, criamos uma struct com esses 4 dados — int id, char nome[50], double preco, int quantidade — para definir os produtos do mercadinho. 	

	A fim de modularizar o código do programa, as funções utilizadas dividem-se em 5 arquivos:

1. consultas.c -> Esse arquivo contém as funções relativas a consulta do saldo do caixa e do estoque do mercadinho;
2. gerenciarMemoria.c -> Esse arquivo contém as funções responsáveis por realizar a alocação dinâmica do estoque, incluindo a alocação, realocação e liberação de memória;
3. produtos.c -> Esse arquivo contém as funções responsáveis pela manipulação de produtos no estoque, ou seja, as funcionalidades de incluir, aumentar a quantidade e modificar o preço de produtos;
4. venda.c -> Esse arquivo contém as funções que realizam a venda de produtos do mercadinho;
5. principal.c -> Esse arquivo contém a main. 


	Além disso, buscando evitar a múltipla definição da struct Produto e de funções, criamos arquivos de cabeçalho que previnem o código desse tipo de erro. Esses arquivos são: 

1. consultas.h -> Contém os protótipos das funções de consultas, definindo-as caso ainda não estejam definidas;
2. gerenciarMemoria.h -> Contém os protótipos das funções de gerenciamento de memória;
3. produtos.h -> Contém a definição da struct Produto e os protótipos das funções de manipulação de produtos; 
4. venda.h -> Contém o protótipo da função de realizar venda.


---AS FUNÇÕES DE PRODUTO---

	As funções de produto são referenciadas na main de acordo com seus respectivos códigos inseridos pelo usuário, onde IP representa inserir produto, MP modificar preço no estoque e AE aumentar o estoque. No arquivo produtos.h, temos a definição da struct produto, a qual é composta pelo id, nome, preço e quantidade no estoque desse produto. A seguir, há uma breve explicação das funções utilizadas. 

	1. void inserirProd() -> Essa função é responsável por inserir o produto digitado pelo usuário no estoque. Ela recebe os dados do produto, que são lidos na main, e os insere no estoque do mercadinho. 

	2. void modificaPrecoProd() -> Essa função é responsável por modificar o preço de um produto no estoque. Ela recebe o produto, cujo código foi lido na main, e o novo preço que deve ser atribuído a ele, trocando o preço antigo pelo novo. 

	3. void aumentaEstoqueProd() -> Essa função é responsável por aumentar a quantidade de um produto no estoque. Ela recebe o produto, cujo código foi lido na main, e de quantas unidades a sua quantidade em estoque deve ser acrescida, realizando essa operação. Além disso, essa funcionalidade gera um custo para o mercadinho que gasta dinheiro que tem em caixa para realizar essa operação. Para tal, o desconto do valor no saldo do caixa é realizado na main, logo após a chamada dessa função. 



---AS FUNÇÕES DE CONSULTA---

	Há duas funções de consulta, uma para consulta de estoque, que é chamada na main caso o usuário digite "CE", e uma para consulta de saldo, que é chamada quando o usuário digita "CS". No arquivo consultas.h, tem-se os protótipos dessas funções. As funções são:

	1. void consultaEstoque() -> Essa função é responsável por imprimir o estoque do mercadinho, mostrando ID, nome e quantidade de cada produto.

	2. void consultaSaldoCaixa() - Essa função é responsável por imprimir o saldo atual do caixa do mercadinho. O saldo é atualizado a partir da função realizarVenda().


---A FUNÇÃO DE VENDA---

	A função de venda é chamada na main caso o usuário digite o código "VE". No arquivo venda.h, temos o protótipo das funções responsáveis pela venda, sendo elas:

	1. static Produto *buscarProduto() -> Essa função é responsável por buscar um produto no estoque. Ela é chamada pela função de realizarVenda, e recebe como parâmetros o estoque, a quantidade de produtos no estoque e o código do produto que deve buscar. Retorna NULL se não for possível encontrar um produto com aquele código, ou um ponteiro para o produto, caso contrário. 

	2. void realizarVenda() -> Essa função é responsável por realizar a venda dos produtos. Ela lê os códigos dos produtos inseridos pelo usuário até encontrar o -1, que indica o término da leitura. Essa função chama a função buscarProduto() e verifica se a quantidade em estoque daquele produto é maior que zero, para que seja possível realizar a venda. Por fim, ela atualiza o saldo do caixa e exibe os produtos e o valor total daquela venda. 


---AS FUNÇÕES DE GERENCIAMENTO DE MEMÓRIA---

	As funções de gerenciamento de memória são chamadas na main toda vez que é necessário realizar a alocação dinâmica do estoque. No arquivo gerenciarMemoria.h, temos os protótipos das funções utilizadas nessa parte crucial do programa. A seguir, há uma breve explicação das funções utilizadas. 

	1. Produto *alocaEstoque() -> Essa função é responsável por alocar dinamicamente o estoque. Ela é chamada pela main logo no início do programa, após a busca pelo arquivo que contém as informações do estoque, e aborta o programa caso não seja possível realizar a alocação dinâmica. 

	2. Produto *realocaEstoque() -> Essa função é responsável por realocar dinamicamente o estoque caso essa operação seja necessária para inserir mais produtos. Ela é chamada na main sempre que há a necessidade de aumentar o espaço do estoque, e realoca o estoque de modo que garanta mais 10 espaços livres de memória. Escolhemos a adição de mais 10 espaços de memória, pois julgamos esse número uma boa quantidade de novos espaços, de modo que não aloquemos espaços demais, e nem espaços de menos, o que tornaria necessário utilizar a função realloc repetidas vezes — prejudicial pois ela gasta muito processamento. 

	3. void liberaEstoque() -> Essa função é responsável por liberar a memória reservada para o estoque quando o programa termina ou em caso de erros de alocação ou realocação. A inclusão dessa função evita que hajam memory leaks no programa. 


---A MAIN---

	A função main está definida no arquivo principal.c, e é responsável por fazer o programa todo rodar. Essa função controla as leituras do programa, quando cada função será chamada e o salvamento das informações em um arquivo. 
	
	Toda a lógica de arquivos presente no sistema está dentro do escopo na main. É importante ressaltar de início que 3 informações são armazenadas no arquivo "estoque.bin": o saldo do caixa, a quantidade de produtos no estoque e o estoque. Em um primeiro momento, busca-se esse arquivo e, caso ele exista, lemos as informações presentes nele por meio de fread(). Caso contrário, o programa solicita ao usuário o tamanho do estoque. 

	O laço while faz com que o programa permaneça rodando até que o usuário digite "FE", permitindo que ele faça inúmeras vezes todas as operações possíveis de serem realizadas no sistema. Por meio da função de comparação de strings, é possível chamar as funções correspondentes a cada uma das funcionalidades presentes no sistema. 
	
	Ao finalizar o dia, o programa escreve as informações daquele dia no mesmo arquivo "estoque.bin", guardando-as para serem utilizadas no dia seguinte. Por fim, a memória reservada para o estoque é liberada, evitando memory leaks e permitindo o bom funcionamento do programa. 
































