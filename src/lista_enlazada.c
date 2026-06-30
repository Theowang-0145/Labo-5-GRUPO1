#include <stdio.h>
#include <stdlib.h>
#include "lista_enlazada.h"

void init_lista(ListaEnlazada *punt_lista){

	punt_lista->head = NULL; //INICIALIZACION
	punt_lista->size = 0;
}

void lista_insertar_inicio(ListaEnlazada *punt_lista, int valor){

	Nodo *nuevo_nodo = malloc(sizeof(Nodo)); //NUEVO PUNTERO

	if (nuevo_nodo == NULL){ //MANEJO DE ERROR
		printf("Error: no se pudo reservar memoria.\n");
		return;
	}

	nuevo_nodo->data = valor; //ASIGNACION DE DATO
	nuevo_nodo->siguiente = punt_lista->head; //ENLACE AL NODO ACTUAL

	punt_lista->head = nuevo_nodo; //REEMPLAZO DEL INICIO
	punt_lista->size++; //AUMENTO
}

void  lista_insertar_final(ListaEnlazada *punt_lista, int valor){

	Nodo *nuevo_nodo = malloc(sizeof(Nodo)); //NUEVO PUNTER0

	if (nuevo_nodo == NULL){ //MANEJO DE ERROR
		printf("Error: no se pudo reservar memoria.\n");
		return;
	}

	nuevo_nodo->data = valor; //ASIGNACION DE DATO
	nuevo_nodo->siguiente = NULL;

	if (punt_lista->head == NULL){ //LISTA VACIA
		punt_lista->head = nuevo_nodo;
	}
	else{
		Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR

		while (actual->siguiente != NULL){ //RECORRIDO
			actual = actual->siguiente;
		}

		actual->siguiente = nuevo_nodo; //ENLACE FINAL
	}

	punt_lista->size++; //AUMENTO
}

void imprimir_lista(ListaEnlazada *punt_lista){

	Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR

	printf("Lista: [ ");

	while (actual != NULL){ //RECORRIDO
		printf("%d ", actual->data);
		actual = actual->siguiente;
	}

	printf("]\n");
	printf("Size: %zu\n", punt_lista->size);
}

void free_lista(ListaEnlazada *punt_lista){

	Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR

	while (actual != NULL){ //LIBERACION DE MEMORIA
		Nodo *temp = actual;
		actual = actual->siguiente;
		free(temp);
	}

	punt_lista->head = NULL;
	punt_lista->size = 0;
}

void lista_insertar_posicion(ListaEnlazada *punt_lista, int valor, size_t posicion){

	if (posicion > punt_lista->size){ //MANEJO DE ERROR
		printf("Posicion fuera de rango.\n");
		return;
	}

	if (posicion == 0){ //INSERCION AL INICIO
		lista_insertar_inicio(punt_lista, valor);
		return;
	}

	if (posicion == punt_lista->size){ //INSERCION AL FINAL
		lista_insertar_final(punt_lista, valor);
		return;
	}

	Nodo *nuevo_nodo = malloc(sizeof(Nodo)); //NUEVO PUNTERO

	if (nuevo_nodo == NULL){ //MANEJO DE ERROR
		printf("Error: no se pudo reservar memoria.\n");
		return;
	}

	nuevo_nodo->data = valor;

	Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR

	for (size_t i = 0; i < posicion - 1; i++){ //RECORRIDO
		actual = actual->siguiente;
	}

	nuevo_nodo->siguiente = actual->siguiente; //NUEVO ENLACE
	actual->siguiente = nuevo_nodo; //REEMPLAZO

	punt_lista->size++; //AUMENTO
}

void lista_eliminar_elemento(ListaEnlazada *punt_lista, int valor){

	if (punt_lista->head == NULL){ //MANEJO DE ERROR
		printf("La lista esta vacia.\n");
		return;
	}

	Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR
	Nodo *anterior = NULL;

	while (actual != NULL && actual->data != valor){ //BUSQUEDA
		anterior = actual;
		actual = actual->siguiente;
	}

	if (actual == NULL){ //DATO NO ENCONTRADO
		printf("Elemento no encontrado.\n");
		return;
	}

	if (anterior == NULL){ //ELIMINACION DEL PRIMER NODO
		punt_lista->head = actual ->siguiente;
	}

	free(actual); //LIBERACION
	punt_lista->size--; //DISMINUCION DE TAMANO
}

int lista_buscar_elemento(ListaEnlazada *punt_lista, int valor){

	Nodo *actual = punt_lista->head; //PUNTERO AUXILIAR
	int posicion = 0;

	while (actual != NULL){ //RECORRIDO
		if (actual->data == valor){
			return posicion; //RETORNA POSICION
		}

		actual = actual->siguiente;
		posicion++;
	}

	return -1; //NO ENCONTRADO
}
