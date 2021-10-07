#include "pila.h"
#include "cola.h"

int main(void) {

    PILA* pila = crear_pila();
    COLA* cola = crear_cola();

    int x, n, data;

    do {
        printf("1 - Pila\n2 - Cola\n");
        scanf("%d", &x);
        switch (x) {
            case 1:
                do {
                    printf("Opciones\n1 - Agregar a pila\n2 - Extraer de pila\n3 - Obtner primer elemento\n4 - Esta vacia?\n");
                    scanf("%d", &n);
                    switch (n) {
                        case 1:
                            printf("Elemento:\n");
                            scanf("%d", &data);
                            insertar_en_pila(pila, data);
                            break;
                        case 2:
                            extraer_de_pila(pila);
                            break;
                        case 3:
                            printf("Primer elemento: %f\n", get_primeroPila(pila));
                            break;
                        case 4:
                            if (pila_vacia(pila)) {
                                printf("NO!\n");
                            } else {
                                printf("SI!\n");
                            }
                            break;
                    }
                } while (n > 0 && n < 5);
                break;
            case 2:
                do {
                    printf("Opciones\n1 - Agregar a cola\n2 - Extraer de cola\n3 - Obtner primer elemento\n4 - Esta vacia?\n");
                    scanf("%d", &n);
                    switch (n) {
                        case 1:
                            printf("Elemento:\n");
                            scanf("%d", &data);
                            insertar_en_cola(cola, data);
                            break;
                        case 2:
                            extraer_de_cola(cola);
                            break;
                        case 3:
                            printf("Primer elemento: %d\n", get_primeroCola(cola));
                            break;
                        case 4:
                            if (cola_vacia(cola)) {
                                printf("NO!\n");
                            } else {
                                printf("SI!\n");
                            }
                            break;
                    }
                } while (n > 0 && n < 5);
                break;

        }
    } while (x == 1 || x == 2);

    eliminar_cola(cola);
    eliminar_pila(pila);

    return 0;
}