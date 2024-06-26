#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR_FILE 1

#define CANT_PROD 10

typedef struct{
    int codArt;
    float precio;
    char descripcion[50];
}Articulo;

int crearArticulos(const char* fileName);
int mostrarArticulos(const char* fileName);
int actualizarArticulos(const char* fileName);
