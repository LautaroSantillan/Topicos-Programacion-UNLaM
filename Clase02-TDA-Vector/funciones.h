#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100
#define TODO_OK 0
#define DUPLICADO 1
#define VEC_LLENO 2
#define ERROR 3

typedef struct
{
    int vec[TAM];
    int ce;
}
Vector;

void vectorCrear(Vector* vec);
void mostrar(Vector *vec);
int vectorInsertarOrd(Vector* vec, int);
/// DESORDENADO: OFF
int vectorInsertarPrin(Vector* vec, int);
int vectorInsertarFin(Vector* vec, int);
int vectorInsertarCualPos(Vector* vec, int, int);
int vectorEliminarPos(Vector* vec, int);
int vectorEliminarPri(Vector* vec);
int vectorEliminarUlt(Vector* vec);
int vectorEliminarValor(Vector* vec, int); /// Funciona tambien para eliminar más de una ocurrencia
