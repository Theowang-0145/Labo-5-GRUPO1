CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c \
      src/arreglo_dinamico.c \
      src/lista_enlazada.c \
      src/lista_doblemente_enlazada.c \
      src/stack.c

TARGET = prueba

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)