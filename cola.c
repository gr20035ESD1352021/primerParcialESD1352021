#include "cola.h"

#include <stdlib.h>
#include <stdio.h>

COLA* crear_cola(){
    COLA* cola = (COLA*)malloc(sizeof(COLA));
    cola->inicio = cola->final = NULL;
    cola->elementos = 0;
    return cola;
}

void eliminar_cola(COLA* cola){
    
}

NODO_COLA* crear_nodoCola(int data){
    NODO_COLA* nodo = (NODO_COLA*)malloc(sizeof(NODO_COLA));
    nodo->data = data;
    nodo->link = NULL;
    
    return nodo;
}

void eliminar_nodoCola(NODO_COLA* nodo){
    nodo->data = NULL;
    nodo->link = NULL;
    free(nodo);
}

void insertar_en_cola(COLA* cola, int data){
    NODO_COLA* nodo = crear_nodoCola(data);
    if(cola->inicio == NULL){
        cola->inicio = nodo;
        cola->final = nodo;
    }else{
        cola->final->link = nodo;
        cola->final = nodo;
    }       
}

int get_primeroCola(COLA* cola){
    if(cola->inicio == NULL){
        return 0;
    }else{
        return cola->inicio->data;
    }
}