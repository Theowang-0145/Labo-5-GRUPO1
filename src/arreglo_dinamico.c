#include <stdlib.h>
#include <stdio.h>


#include "arreglo_dinamico.h"

void init_arreglo(ArrDinamico *punt_datos, size_t capacidad_inicial){

    punt_datos->data = NULL;    //se inicializa todo en ceros para que sea valido el comienzo, luego se manejan errores
    punt_datos->size = 0; 
    punt_datos->capacidad = 0; 

    if (punt_datos->capacidad == 0){
        //se pregunta si hay una capacidad valida, sino se escoge una por default
        punt_datos->capacidad = 10;
    }
    //despues e le guardan tantos espacios al arreglo que apunta el puntero dentro del struct
    punt_datos->data = malloc(capacidad_inicial * sizeof (int)); 

    //se utiliza este pointer guard por si no se pudo guardar espacio en la memoria
    if (punt_datos->data == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return;
    }

    punt_datos->capacidad = capacidad_inicial;  //se reemplaza la capacidad al final

}


void insertar_inicio(ArrDinamico *punt_datos, int valor){
    (void)punt_datos;
    (void)valor;
} 


void insertar_final(ArrDinamico *punt_datos, int valor){


    //primero se verifica si hay espacio para poder insertar un valor
    if ((punt_datos->size) == (punt_datos->capacidad)){
        size_t nueva_capacidad = punt_datos->capacidad * 2; 


        //una vez creada una capacidad mayor se genera un nuevo puntero que va a reemplazar el anterior, soloq eu con mas capacidad
        int *nueva_data = realloc(punt_datos->data, nueva_capacidad * sizeof(int));

        if (nueva_data == NULL){
            printf("No se pudo guardar mas espacio para el puntero");
            return;
        }

        //aca se reemplazan tanto los punteros como la capacidad nueva
        punt_datos->data = nueva_data;
        punt_datos->capacidad = nueva_capacidad;
    }

    //aca se buscala posicion del tamano actual del arreglo pues asi se puede colocar al inal de la fila, pues size es 1 veces mayor que las posiciones llenas
    punt_datos->data[punt_datos->size] = valor;

    //se suma un valor a size pues se esta agregando un valor nuevo
    punt_datos->size++;

}

void insertar_posi_espec(ArrDinamico *punt_datos, int valor, int posicion){
    (void)punt_datos;
    (void)valor;
    (void)posicion;
}
void eliminar_elemento_segun_data(ArrDinamico *punt_datos, int valor){
    (void)punt_datos;
    (void)valor;
} 
void buscar(ArrDinamico *punt_datos, int valor){
    (void)punt_datos;
    (void)valor;
}


void imprimir_arreglo(ArrDinamico *punt_datos){


    //esta forma de impresion fue extraida de la practica anterior
    printf("Arreglo: [ ");


    //recorre el coclo hasta size para asi poder imprimir todos los datos
    for (size_t i = 0; i < punt_datos->size; i++) {

        printf("%d ", punt_datos->data[i]);

    }
    printf("]\n");
    printf("Size: %zu | Capacidad: %zu\n", punt_datos->size, punt_datos->capacidad);

}
void free_arreglo(ArrDinamico *punt_datos){

    //primero se libera la memoria del puntero y despues se deja en limpio el struct, el puntero apuntando a null reseteando la estructura
    free(punt_datos->data);

    punt_datos->data = NULL;
    punt_datos->size = 0;
    punt_datos->capacidad = 0;
}