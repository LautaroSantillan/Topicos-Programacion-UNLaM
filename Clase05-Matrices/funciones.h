#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ORDEN3 3
#define ORDEN4 4

void** matrizCrear(size_t filas, size_t cols, size_t tamElem); /// cols == columnas
void matrizEliminar(void** matriz, size_t filas);
void matrizCargarTest(int** matriz, size_t filas, size_t cols);
int matrizSumarDiagPrin(int** matriz, int orden);
int matrizSumarDiagSecun(int** matriz, int orden);
int matrizSumarTriangSupDiagSecun(int** matriz, int orden);
int** matrizProducto(int** m1, int**m2, size_t filasM1, size_t filasM1colsM2, size_t colsM2);
void matrizMostrar(int** matriz, size_t filas, size_t cols);
