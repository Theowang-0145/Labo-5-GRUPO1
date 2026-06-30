#include <stdio.h>
#include <stdlib.h>
#include "lista_enlazada.h"

void init_lista(ListaEnlazada *punt_lista){

	punt_lista->head = NULL; //INICIALIZACION
	punt_lista->size = 0;
}

void insertar_inicio(ListaEnlazada *punt_lista, int valor){

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

void  insertar_final(ListaEnlazada *punt_lista, int valor){

	Nodo *nuevo_nodo = malloc(sizeof(Nodo)); //NUEVO PUNTER0

	if (nuevo_nodo == NULL){ //MANEJO DE ERROR
		printf("Error: no se pudo reservar memoria.\n);
		return;
	}

	nuevo_nodo->data = valor; //ASIGNACION DE DATO
	nuevo_nodo->siguiente = NULL

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
