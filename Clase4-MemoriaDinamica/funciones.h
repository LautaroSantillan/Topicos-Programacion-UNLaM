#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100
#define TAM_2 200
#define SIN_MEM 0
#define TODO_OK 1
#define DUPLICADO 2
#define ERROR 3

typedef struct
{
    int* vec;
    int ce; // cant. de elementos cargados
    int cap; // cant. de elementos totales que se quiere disponer
}
MiVector;


///void* malloc(size_t cantBytes);
///void* callloc(void*, size_t);
///void free(void*);

bool vectorCrear(MiVector* vec);
void mostrar(MiVector *vec);
int vectorOrdInsertar(MiVector* vec, int);
int vectorOrdEliminarElem(MiVector* vec, int);
//buscar con aritmetica de punteros
/*int vectorInsertarPrin(Vector* vec, int);
int vectorInsertarFin(Vector* vec, int);
int vectorInsertarCualPos(Vector* vec, int, int);
int vectorEliminarPos(Vector* vec, int);
int vectorEliminarPri(Vector* vec);
int vectorEliminarUlt(Vector* vec);
int vectorEliminarValor(Vector* vec, int);
int vectorBuscarElemDes(Vector* vec, int elem);
/// ORDENADO
int vectorInsertarOrd(Vector* vec, int);
int vectorBuscarElemOrd(Vector* vec, int elem);
int vectorEliminarValorOrd(Vector* vec, int elem);
int vectorEliminarDupOrd(Vector* vec, int elem);*/
