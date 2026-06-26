# Define o compilador
CC = gcc

# Flags de compilação (C99 exigido e avisos ativados)
CFLAGS = -std=c99 -Wall 

# Nome do executável gerado
TARGET = exec_mercadinho

# Lista explícita dos arquivos fontes do seu projeto (Resolve o erro do corretor)
SOURCES = principal.c produtos.c venda.c consultas.c gerenciarMemoria.c

# A regra 'all' é a padrão
all: $(TARGET)

# Compila o programa utilizando estritamente a lista de fontes acima
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Regra para rodar o programa 
run: $(TARGET)
	./$(TARGET)

# Regra para gerar o ZIP da entrega corretamente (inclui os cabeçalhos .h também!)
zip:
	zip entrega.zip Makefile README.txt *.c *.h

# Limpa o executável e o zip real gerado (Corrigido para apagar o entrega.zip)
clean:
	rm -f $(TARGET) entrega.zip

.PHONY: all run zip clean