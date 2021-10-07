#include "pila.h"

int main(void){
    
    PILA* pila = crear_pila();
    int x = 1, n, data;
    while(x){
        printf("Opciones\n1 - Agregar a pila\n2 - Extraer de pila\n3 - Obtner primer elemento\n4 - Esta vacia?\n");
        scanf("%d", &n);
        switch(n){
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
                if(pila_vacia(pila)){
                    printf("SI!\n");
                }else{
                    printf("NO!\n");
                }
                break;
            default:
                x = 0;
        }
    }
    
    eliminar_pila(pila);
    
    return 0;
}