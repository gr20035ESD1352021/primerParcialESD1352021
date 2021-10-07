#include "cola.h"

#include <stdlib.h>
#include <stdio.h>

COLA* crear_cola(){
    COLA* cola = (COLA*)malloc(sizeof(COLA));
    cola->inicio = NULL;
    cola->final = NULL;
    cola->elementos = 0;
    return cola;
}

void eliminar_cola(COLA* cola){
    while(cola->inicio != NULL){
        extraer_de_cola(cola);
    }
    free(cola);
}

NODO_COLA* crear_nodoCola(int data){
    NODO_COLA* nodo = (NODO_COLA*)malloc(sizeof(NODO_COLA));
    nodo->data = data;
    nodo->link = NULL;
    
    return nodo;
}

void eliminar_nodoCola(NODO_COLA* nodo){
    nodo->data = 0;
    nodo->link = NULL;
    free(nodo);
}

void insertar_en_cola(COLA* cola, int data){
    NODO_COLA* nodo = crear_nodoCola(data);
    if(cola->inicio == NULL){
        cola->inicio = nodo;
        cola->final = nodo;
        cola->elementos++;
    }else{
        cola->final->link = nodo;
        cola->final = nodo;
        cola->elementos++;
    }       
}

void extraer_de_cola(COLA* cola){
    if(cola->inicio){
        NODO_COLA* eliminar = cola->inicio;
        cola->inicio = cola->inicio->link;
        eliminar_nodoCola(eliminar);
        cola->elementos--;
        if(cola->inicio == NULL){
            cola->final = NULL;
        }
    }
}

int get_primeroCola(COLA* cola){
    if(cola->inicio == NULL){
        return 0;
    }else{
        return cola->inicio->data;
    }
}

int cola_vacia(COLA* cola){
    return cola->elementos > 0;
}