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

    printf("\nInicio pruebas para listas enlazadas\n\n");

    ListaEnlazada lista;
    init_lista(&lista);

    lista_insertar_inicio(&lista, 20);
    lista_insertar_inicio(&lista, 10);
    lista_insertar_final(&lista, 30);
    lista_insertar_final(&lista, 40);

    printf("La lista inicial es la siguiente:\n");
    imprimir_lista(&lista);

    printf("\nPrueba de insertar el elemento 25 en la posicion 2\n");
    lista_insertar_posicion(&lista, 25, 2);
    imprimir_lista(&lista);

    printf("\nPrueba de buscar el elemento 30\n");
    int posicion = lista_buscar_elemento(&lista, 30);

    if (posicion != -1){
        printf("El elemento fue encontrado en la posicion: %d\n", posicion);
    }
    else{
        printf("El elemento no fue encontrado.\n");
    }

    printf("\nSe va a eliminar el elemento de valor 25\n");
    lista_eliminar_elemento(&lista, 25);
    imprimir_lista(&lista);

    free_lista(&lista);

    printf("\nFin de pruebas de listas enlazadas\n");

    //--------------------------------Fin seccion de prueba para listas enlazadas------------------------


   //---------------------------------INICIO DE PRUEBA PARA LISTAS DOBLEMENTE ENLAZADAS-------------------

    DoublyLinkedList *list = createList();
//Aca se crean las dos lista, la primera coloca los valores adelante
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 5);
//Mientras que aca, la segunda lista se crea y manda los valores al final 
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
//para provar la modificacion de elementos, se cambia el elemento 20 a valor 15 en la lista 2 para probar errores despues
    insertAtPosition(list, 15, 2);
//estos print son informativos de que algo esta ocurriendo, sea hacia adelante, o atras
    printf("Hacia adelante:\n");
    printForward(list);

    printf("\nHacia atras:\n");
    printBackward(list);
//esto es lo mencionado anteriormente, se genera a proposito un fallo para ver que la insercion de elementos en una lista si ocurre
    Node *found = searchElement(list, 20);

    if (found != NULL) {
        printf("\nElemento 20 encontrado\n");
    }
//ahora, usando el mismo elemento 15, se borra para generar otra busqueda despues de un elemento que sabemos, ya existe
    deleteElement(list, 15);

    printf("\nDespues de eliminar 15:\n");
    printForward(list);
//aca ya se solicita eliminar esta lista para disminuir el uso de memoria 
    freeList(list);

//---------------------------------------- FIN DE PRUEBAS DE DOBLE LISTAS ENLAZADAS------------------------

//--------------------------------------- PRUEBA DE STACK ------------------------------------------------------

    Stack *stack = createStack();
//aca se añaden unos valor que luego se moveran para denotar las modificaciones que se realizan 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printStack(stack);
//se imprime previo a la modificacion por control 
    printf("Top: %d\n", peek(stack));
//aca se modificara quien este de primero
    printf("Pop: %d\n", pop(stack));
//y aca se modifica  en el popo el stack para ir eliminando los elementos que se encuentras modificados en el top y por tanto, en el ultimo stack generado 
    printStack(stack);
//por ultimo, el sistema nos informa que ha concluido con la gecuioon yu que el stack temporal esta vacio 
    printf("Esta vacio?: %d\n", isEmpty(stack));

    freeStack(stack);
//para buenas practicas, se elimina el espacio en memoria asignado al stack
    return 0;
}

//---------------------------------------- FIN DE PRUEBAS PARA STACK-----------------------------------------

