#ifndef COLA_H
#define COLA_H

typedef struct NODO_COLA{
    int data;
    struct NODO_COLA* link;
}NODO_COLA;

typedef struct COLA{
    NODO_COLA* inicio;
    NODO_COLA* final;
    
    int elementos;
}COLA;

COLA* crear_cola();

void eliminar_cola(COLA* cola);

NODO_COLA* crear_nodoCola(int data);

void eliminar_nodoCola(NODO_COLA* nodo);

void insertar_en_cola(COLA* cola, int data);

void extraer_de_cola(COLA* cola);

int get_primeroCola(COLA* cola);

int cola_vacia(COLA* cola);

#endif //COLA_H