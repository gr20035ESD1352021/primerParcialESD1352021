#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct NODO_PILA{
    float data;
    struct NODO_PILA* link;
}NODO_PILA;

typedef struct PILA{
    NODO_PILA* inicio;
    int elementos;
}PILA;

PILA* crear_pila();

void eliminar_pila(PILA* pila);

NODO_PILA* crear_nodoPila(float data);

void eliminar_nodoPila(NODO_PILA* nodo);

void insertar_en_pila(PILA* pila, float data);

void extraer_de_pila(PILA* pila);

float get_primeroPila(PILA* pila);

int pila_vacia(PILA* pila); // 0 = Vacia

#endif //PILA_H