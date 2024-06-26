#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR_FILE 1
#define ERROR_MEM 2

#define CANT_PROD 10

typedef struct{
    void* vec;
    int capacidad;
    int ce;
    unsigned tam;
}Vector;

typedef struct{
    int cod;
    float precio;
    char descripcion[50];
}Producto;

int contarProductos(const char* fileName);
int procesarProductos(const char* fileName, Vector* vecProd);
void trozar(Producto *prod, char* linea);
int compararDescripcion(const void* a, const void* b);
void mostrarProducto(const void* a);
int compararDescripcion(const void* a, const void* b);

typedef void (*accion)(const void*);
int crearVector(Vector* vec, int ce, unsigned tam);
void recorrerVector(Vector* vec, accion Accion);
int insertarOrdenado(Vector* vec, const Producto* prod, int (*comparar)(const void*, const void*));
