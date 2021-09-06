#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHAR 60

typedef struct 
{
    int array_csv[59][6];
    int array_csvT[6][59];
    int array_csvM[59][59];
}arrays2d;

void leerA_archivo(char *direccion_archivo, arrays2d *array_principal)
{

    int x, y;

    FILE *archivo_csv;
    char linea_archivo[MAXCHAR];
    char *token;

    archivo_csv = fopen(direccion_archivo, "r");

    x = 0;

    while(feof(archivo_csv) != true)
    {

        y = 0;

        fgets(linea_archivo, MAXCHAR, archivo_csv);
        
        token = strtok(linea_archivo, ",");
        while(token != NULL)
        {
            int tamanio_token = strlen(token);

            if(tamanio_token == 1 || tamanio_token == 2)
            {
                int valor_token = atoi(token);
                array_principal->array_csv[(x - 2)][y] = valor_token;

                y++;
            }
            
            token = strtok(NULL, ",");
        }
        x++;
    }
    fclose(archivo_csv);
}

void trasponer_array(arrays2d *array_principal)
{
    int x, y;
    for(x = 0; x < 6; x++)
    {
        for(y = 0; y < 59; y++)
        {
            array_principal->array_csvT[x][y] = array_principal->array_csv[y][x];
        }
    }
}

int main(void)
{
    int x, y;

    arrays2d array_principal;
    char direccion_archivo[50] = "peliculasFavoritasESD135_2021.csv";

    leerA_archivo(direccion_archivo, &array_principal);
    trasponer_array(&array_principal);

    /*for(x = 0; x < 59; x++)
    {
        for(y = 0; y < 6; y++)
        {
            printf("%d", array_principal.array_csv[x][y]);
        }
        printf("\n");
    }

    for(x = 0; x < 6; x++)
    {
        for(y = 0; y < 59; y++)
        {
            printf("%d", array_principal.array_csvT[x][y]);
        }
        printf("\n");
    }*/
}