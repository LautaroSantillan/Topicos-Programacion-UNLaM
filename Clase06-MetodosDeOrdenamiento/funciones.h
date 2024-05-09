#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIN_MEM 0
#define TODO_OK 1
#define DUPLICADO 2
#define ERROR 3

typedef struct{
    int* vec;
    int ce; // cant. de elementos cargados
    int cap; // cant. de elementos totales que se quiere disponer
}MiVector;

bool vectorCrear(MiVector*);
void vectorMostrar(MiVector*);
int vectorInsertarFin(MiVector*, int);
void vectorInicializarRandom(MiVector*, int);
/// METODOS DE ORDENAMIENTO
void intercambiar(int*, int*);
int* buscarMenor(int*, int*);
void vectorOrdenarBurbujeo(MiVector*);
void vectorOrdenarSeleccion(MiVector*);
void vectorOrdenarInsercion(MiVector*);
