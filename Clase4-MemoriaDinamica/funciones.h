#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIN_MEM 0
#define TODO_OK 1
#define DUPLICADO 2
#define ERROR 3

typedef struct{
    int* vec;
    int ce; // cant. de elementos cargados
    int cap; // cant. de elementos totales que se quiere disponer
}MiVector;

///void* malloc(size_t cantBytes);
///void* callloc(void*, size_t);
///void free(void*);

bool vectorCrear(MiVector* vec);
void mostrar(MiVector *vec);
int vectorOrdInsertar(MiVector* vec, int);
int vectorOrdBuscarElem(MiVector* vec, int);
int vectorOrdEliminarElem(MiVector* vec, int);
int vectorInsertarPrin(MiVector* vec, int);
int vectorInsertarFin(MiVector* vec, int);
int vectorInsertarCualPos(MiVector* vec, int, int);
int vectorEliminarPos(MiVector* vec, int);
int vectorEliminarPri(MiVector* vec);
int vectorEliminarUlt(MiVector* vec);
int vectorOrdEliminarDup(MiVector* vec, int);
///int vectorBuscarElemDes(MiVector* vec, int elem);
