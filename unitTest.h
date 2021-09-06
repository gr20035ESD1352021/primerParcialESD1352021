#ifndef __UNITTEST_H
#define __UNITTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <CUnit/CUnit.h>

#define MAXCHAR 60

typedef struct
{
    int array_csvN[59][6];
    int array_csvT[6][59];
    int array_csvM[59][59];
    char *array_csv[67][1];
} arrays2d;

void leerA_archivo(char *direccion_archivo, arrays2d *array_principal);

void trasponer_array(arrays2d *array_principal);

void multiplicar_array(arrays2d *array_principal);

const char *integrantes();

#endif