#ifndef FUNCIONESARCH_H
#define FUNCIONESARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CANT_ARG 4
#define ARG_ARCH_ENT 1
#define ARG_TIPO_ARCH_ENT 2
#define ARG_ARCH_SAL 3
#define ARG_TIPO_ARCH_SAL 4

#define TODO_OK 0
#define ERR_ARG 1
#define ERR_ARCH 2
#define ERR_MEM 3
#define ERR_LINEA_LARGA 4

#define TAM_NOMBRE 20
#define CANT_EMP 8
#define TAM_LINEA 501

#define CANT_EMPL 8

typedef void (*BinATxt)(const void* reg, FILE* archTxt);
typedef void (*TxtABin)(char* linea, void* reg);

typedef struct
{
    int dia;
    int mes;
    int anio;
}
Fecha;

typedef struct
{
    int legajo;
    char nombre[TAM_NOMBRE + 1];
    char sexo;
    Fecha fechaIng;
    float sueldo;
}
Empleado;

void empleadoBinATxtV(const void* reg, FILE* archTxt);
void empleadoBinATxtF(const void* reg, FILE* archTxt);
int empleadoTxtVABin(char* linea, void* reg);
int convertirBinATxt(const char* nomArchBin, const char* nomArchTxt, size_t tamReg ,BinATxt binATxt);
int convertirTxTABin(const char* nomArchTxT, const char* nomArchBin, size_t tamReg , TxtABin txtABin);
void empleadoBinATxtV(const void* reg, FILE* archTxt);
void empleadoBinATxtF(const void* reg, FILE* archTxt);
int empleadoTxtVABin(char* linea, void* reg);
int generarArchivoEmpleados (const char* nomArchEmpl);
int mostrarArchivoEmpleados(const char* nomArchEmpl);
bool errorGrave(int codigo);


#endif // FUNCIONESARCH_H
