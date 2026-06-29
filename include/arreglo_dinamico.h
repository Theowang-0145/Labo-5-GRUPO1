#ifndef ARREGLO_DINAMICO_h
#define ARREGLO_DINAMICO_h

#include <stddef.h>

                
typedef struct {    //este es el struct base para el arreglo dinamico
    int *data;
    size_t size;        //se utilizan los tipos de datos size_t igual que en la practica
    size_t capacidad;  //tamano actual y capacidad total del arreglo
} ArrDinamico;


//este conjunto de funciones reciben el puntero hacia el arreglo para modificarlo o crearle memoria
void init_arreglo(ArrDinamico *punt_datos, size_t capacidad_inicial); 
void insertar_final(ArrDinamico *punt_datos, int valor); //este debe de tener una verificacion de espacio
void eliminar_elemento(ArrDinamico *punt_datos, int valor); 
void buscar_elemento_por_indice(ArrDinamico *punt_datos, int valor);
void imprimir_arreglo(ArrDinamico *punt_datos);
void free_arreglo(ArrDinamico *punt_datos);


#endif