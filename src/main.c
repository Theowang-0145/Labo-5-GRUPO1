#include <stdlib.h>
#include <stdio.h>

#include "arreglo_dinamico.h"
#include "lista_enlazada.h"
#include "lista_doblemente_enlazada.h"
#include "stack.h"

int main (void){

    printf("Lab 5 \n");

    //este segundo commit se va a basar unicamente en inicializar el struct y el arreglo
    //despues se va a interntar insertar al final algunos elementos, imprimir y liberar memoria


    //---------------------inicio seccion de prueba para el arreglo dinamico--------------------------------
    printf("Inicio pruebas de arreglo dinamicos \n"); 

    ArrDinamico arreglo_1; 
    init_arreglo(&arreglo_1, 15); //se le ingresa la posicion del arreglo al puntero que apunta al struct y la capacidad inicial

    //se insertan varios para probar el programa
    insertar_final(&arreglo_1, 20);
    insertar_final(&arreglo_1, 30);
    insertar_final(&arreglo_1, 7);
    insertar_final(&arreglo_1, 100);

    imprimir_arreglo(&arreglo_1); 
    free_arreglo(&arreglo_1); 

    printf("Fin pruebas de arreglo dinamicos \n"); 
    //-------------------------------fin seccion de prueba para el arreglo dinamico----------------------


    return 0; 
}
