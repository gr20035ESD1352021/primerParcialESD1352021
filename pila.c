#include "pila.h"

PILA* crear_pila(){
    PILA* pila = (PILA*)malloc(sizeof(PILA));
    pila->inicio = NULL;
    pila->elementos = 0;
    return pila;
}

void eliminar_pila(PILA* pila){
    while(pila->inicio != NULL){
        extraer_de_pila(pila);
    }
    free(pila);
}

NODO_PILA* crear_nodoPila(float data){
    NODO_PILA* nodo = (NODO_PILA*)malloc(sizeof(NODO_PILA));
    nodo->data = data;
    nodo->link = NULL;
    
    return nodo;
}

void eliminar_nodoPila(NODO_PILA* nodo){
    nodo->link = NULL;
    free(nodo);
}

void insertar_en_pila(PILA* pila, float data){
    NODO_PILA* nodo = crear_nodoPila(data);
    nodo->link = pila->inicio;
    pila->inicio = nodo;
    pila->elementos++;
}

void extraer_de_pila(PILA* pila){
    if(pila->inicio != NULL){
        NODO_PILA* eliminar = pila->inicio;
        pila->inicio = pila->inicio->link;
        eliminar_nodoPila(eliminar);
        pila->elementos--;
    }
}

float get_primero(PILA* pila){
    if(pila->inicio == NULL){
        return (1);
    }else{
        return pila->inicio->data;
    }
}

int pila_vacia(PILA* pila){
    return pila->elementos == 0;
}
