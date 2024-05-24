#ifndef FUNCIONESARCH_H
#define FUNCIONESARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_NOMBRE 51
#define CANT_EMPL 8

#define ERR_ARCH 1
#define TODO_OK 0
#define ERR_PARAM 2

#define PARAM_NOM_ARCH 1
#define PARAM_PORC 3
#define PARAM_NOM_IDX 2
#define CANT_PARAM 4

typedef struct
{
    int legajo;
    char nombre[TAM_NOMBRE];
    float sueldo;
}
Empleado;

typedef struct
{
    int legajo;
    long nroReg;
}
EmpleadoIdx;

typedef struct{
    void* vec;
    int ce;
    int cap;
    size_t tamElem;
}Vector;

typedef int (*Cmp)(const void*  ei, const void* e2);

int generarArchivoEmpleados (const char* nomArchEmpl);
int mostrarArchivoEmpleados(const char* nomArchEmpl);
int actualizarSueldosEmpleados(const char* nomArchEmpl, float porc);
int generarIndiceEmpleados(const char* nomArchEmpl, const char* nomArchIdx);
int cargarIndiceEmpleados(Vector* vecIdx, const char* nomArchIdx);
int cmpEmplIdx(const void* e1, const void* e2);
int actualizarSueldo1Empleado(const char* nomArchEmpl, Vector* vecIdx, int legajo, float porc);

bool vectorCrear(Vector* vec, size_t tamElem);
int vectorOrdInsertar(Vector* vec, int elem);


#endif // FUNCIONESARCH_H
