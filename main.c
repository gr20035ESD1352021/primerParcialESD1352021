#include "unitTest.h"

/*typedef struct 
{
    int array_csv[59][6];
    int array_csvT[6][59];
    int array_csvM[59][59];
}arrays2d;*/

void leerA_archivo(char *direccion_archivo, arrays2d *array_principal)
{

    int x, y;

    FILE *archivo_csv;
    char linea_archivo[MAXCHAR];
    char *token;

    archivo_csv = fopen(direccion_archivo, "r");

    x = 0;

    while (feof(archivo_csv) != true)
    {

        y = 0;

        fgets(linea_archivo, MAXCHAR, archivo_csv);

        token = strtok(linea_archivo, ",");
        while (token != NULL)
        {
            int tamanio_token = strlen(token);

            if (tamanio_token == 1 || tamanio_token == 2)
            {
                int valor_token = atoi(token);
                array_principal->array_csvN[(x - 2)][y] = valor_token;

                y++;
            }
            else
            {
                array_principal->array_csv[x][0] = token;
                //printf("%s", array_principal->array_csv[x][0]);
            }

            token = strtok(NULL, ",");
        }
        //printf("\n");
        x++;
    }
    fclose(archivo_csv);
}

void trasponer_array(arrays2d *array_principal)
{
    int x, y;
    for (x = 0; x < 6; x++)
    {
        for (y = 0; y < 59; y++)
        {
            array_principal->array_csvT[x][y] = array_principal->array_csvN[y][x];
        }
    }
}

void multiplicar_array(arrays2d *array_principal)
{

    int x, y, z;

    for (x = 0; x < 59; x++)
    {
        for (y = 0; y < 59; y++)
        {
            array_principal->array_csvM[x][y] = 0;
        }
    }

    for (x = 0; x < 59; x++)
    {
        for (y = 0; y < 59; y++)
        {
            for (z = 0; z < 6; z++)
            {
                array_principal->array_csvM[x][y] += ((array_principal->array_csvN[x][z]) * (array_principal->array_csvT[z][y]));
            }
        }
    }

    //return *array_principal;
}

const char *integrantes()
{

    return "hs20006,gr20035";
}

int main(void)
{
    int x, y;

    arrays2d array_principal;
    char direccion_archivo[50] = "peliculasFavoritasESD135_2021.csv";

    leerA_archivo(direccion_archivo, &array_principal);
    trasponer_array(&array_principal);
    multiplicar_array(&array_principal);

    printf("\n%s\n", integrantes());
}