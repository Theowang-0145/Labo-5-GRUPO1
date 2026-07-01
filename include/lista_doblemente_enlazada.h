#ifndef lista_doblemente_enlazada_h
#define lista_doblemente_enlazada_h
typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node; //el nodo funciona como punto de conexion entre la memoria y los archivos

typedef struct {
	Node *head;
	Node *tail;
} DoublyLinkedList; //aca se procesan las listas

DoublyLinkedList *createList();//aca se crean las listas con las que se cuenta

void insertAtBeginning(DoublyLinkedList *, int data);
void insertAtPosition(DoublyLinkedList *list, int data, int position);
void insertAtEnd(DoublyLinkedList *list, int data);
void deleteElement(DoublyLinkedList *list, int data); //borrar los datos previene  memory leaks
Node *searchElement(DoublyLinkedList *list, int data);
void printForward(DoublyLinkedList *list); //esto permite el chequeo de que las cosas funcionen 
void printBackward(DoublyLinkedList *list);
//se imprime tanto el fontral como posterior, para saber ern todo momento lo que esta pasando 
void freeList(DoublyLinkedList *list);
//esta ultima llamada busca volver a evitar los memory leaks y finalizar el proceso 

#endif
