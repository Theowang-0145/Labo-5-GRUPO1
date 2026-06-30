#include <stdlib.h>
#include <stdio.h>

#include "arreglo_dinamico.h"
#include "lista_enlazada.h"
#include "lista_doblemente_enlazada.h"
#include "stack.h"

int main (void){
    //---------------------inicio seccion de prueba para el arreglo dinamico--------------------------------
    size_t valor;
    size_t valor_pruebas;
    
    printf("Inicio pruebas de arreglo dinamicos \n"); 
    

    ArrDinamico arreglo_1; 
    init_arreglo(&arreglo_1, 10); //se le ingresa la posicion del arreglo al puntero que apunta al struct y la capacidad inicial

    //se insertan varios para probar el programa
    insertar_final(&arreglo_1, 10);
    insertar_final(&arreglo_1, 20);
    insertar_final(&arreglo_1, 30);
    insertar_final(&arreglo_1, 40);
    insertar_final(&arreglo_1, 50);
    insertar_final(&arreglo_1, 160);
    insertar_final(&arreglo_1, 170);
    insertar_final(&arreglo_1, 180);
    insertar_final(&arreglo_1, 190);
    insertar_final(&arreglo_1, 1);
    //intencionalmente se insertan 10 para poder ingresar uno nuevo y verificar la funcion de aumentar capacidad


    printf("\n");
    printf("El arreglo a analizar es el siguiente: \n"); 
    printf("--------------------------- \n"); 
    imprimir_arreglo(&arreglo_1); 
    printf("--------------------------- \n"); 
    printf("\n");

    valor_pruebas = 14;
    printf("Prueba de insertar un elemento de valor :%zu \n", valor_pruebas); 
    insertar_final(&arreglo_1, valor_pruebas);
    printf("--------------------------- \n"); 
    imprimir_arreglo(&arreglo_1); 
    printf("--------------------------- \n");
    printf("\n");

    valor_pruebas = 8;
    printf("Prueba de buscar un elemento en la posicion :%zu \n", valor_pruebas); 
    valor = buscar_elemento_por_indice(&arreglo_1,valor_pruebas); 
    printf("El valor buscado es:%zu \n", valor); 
    printf("\n");

    valor_pruebas = 3;
    printf("Se va a eliminar el elemento en la posicion: %zu \n", valor_pruebas); 
    eliminar_elemento_por_indice(&arreglo_1, valor_pruebas); 
    printf("--------------------------- \n"); 
    imprimir_arreglo(&arreglo_1); 
    printf("--------------------------- \n");
    printf("\n");

    free_arreglo(&arreglo_1); 

    printf("Fin pruebas de arreglo dinamicos \n"); 
    //-------------------------------fin seccion de prueba para el arreglo dinamico----------------------

    //-------------------------------Inicio seccion de prueba para listas enlazadas----------------------

    printf("\nInicio pruebas para listas enlazadas\n\n")

    ListaEnlazada lista;
    init_lista(&lista);

    insertar_inicio(&lista, 20);
    insertar_inicio(&lista, 10);
    insertar_final(&lista, 30);
    insertar_final(&lista, 40);

    printf("La lista inicial es la siguiente:\n");
    imprimir_lista(&lista);

    printf("\nPrueba de insertar el elemento 25 en la posicion 2\n");
    insertar_posicion(&lista, 25, 2);
    imprimir_lista(&lista);

    printf("\nPrueba de buscar el elemento 30\n");
    int posicion = buscar_elemento(&lista, 30);

    if (posicion != -1){
        printf("El elemento fue encontrado en la posicion: %d\n", posicion);
    }
    else{
        printf("El elemento no fue encontrado.\n");
    }

    printf("\nSe va a eliminar el elemento de valor 25\n");
    eliminar_elemento(&lista, 25);
    imprimir_lista(&lista);

    free_lista(&lista);

    printf("\nFin de pruebas de listas enlazadas\n");

    //--------------------------------Fin seccion de prueba para listas enlazadas------------------------

    return 0;
}
