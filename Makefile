CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c \
      src/arreglo_dinamico.c \
      src/lista_enlazada.c \
      src/lista_doblemente_enlazada.c \
      src/stack.c

TARGET = prueba

all:
	@echo "Compilando proyecto..."
	@$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@echo "Compilación exitosa."

run: all
	@echo "Ejecutando..."
	@./$(TARGET)

clean:
	@rm -f $(TARGET)