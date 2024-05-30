#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_ARG 3
#define ARG_PRODUCTOS 1
#define ARG_MOVIMIENTOS 2

#define TODO_OK 0
#define ERROR_ARG 1
#define ERROR_ARCHIVOS 2

#define CANT_PROD 6
#define CANT_MOV 8

#define NOM_ARCH_PROD_TMP "Productos.tmp"

typedef struct{
    char codigo[7];
    char descripcion[21];
    int stock;
}Producto;

typedef struct{
    char codigo[7];
    int cantidad;
}Movimiento;

int generarProductos(const char* fileName);
int generarMovimientos(const char* fileName);
int mostrarProductos(const char* fileName);
int actualizarProductos(const char * fileNameProd, const char* fileNameMov);
void procesarProductoNuevo(Movimiento* mov, FILE* fileMov, FILE* fileProdTmp);
