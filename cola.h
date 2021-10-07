#ifndef COLA_H
#define COLA_H

typedef struct NODO_COLA{
    int data;
    struct NODO_COLA* link;
}NODO_COLA;

typedef struct COLA{
    NODO_COLA* inicio, final;
    int elementos;
}COLA;

COLA* crear_cola();

NODO_COLA* crear_nodoCola(int data);

void eliminar_nodoCola(NODO_COLA* nodo);

#endif //COLA_H