#ifndef lista_enlazada_h
#define lista_enlazada_h

#include <stddef.h>

typedef struct Nodo { //STRUCT BASE DEL NODO
	int data;
	struct Nodo *siguiente;
} Nodo;

typedef struct { //STRUCT BASE DE LA LISTA
	Nodo *head;
	size_t size;
} ListaEnlazada;

void init_lista(ListaEnlazada *punt_lista);
void insertar_inicio(ListaEnlazada *punt_lista, int valor);
void insertar_final(ListaEnlazada *punt_lista, int valor);
void insertar_posicion(ListaEnlazada *punt_lista, int valor, size_t posicion);
void eliminar_elemento(ListaEnlazada *punt_lista, int valor);
int buscar_elemento(ListaEnlazada *punt_lista, int valor);
void imprimir_lista(ListaEnlazada *punt_lista);
void free_lista(ListaEnlazada *punt_lista);

#endif
