#include "funciones.h"

/// Merge: Productos.dat -> Movimientos.dat
int main(int argc, char* argv[])
{
    if(argc != CANT_ARG)
        return ERROR_ARG;

    int ret;

    ret = generarProductos(argv[ARG_PRODUCTOS]);
    if(ret != TODO_OK)
        return ret;

    ret = generarMovimientos(argv[ARG_MOVIMIENTOS]);
    if(ret != TODO_OK)
        return ret;

    puts("Antes:");
    mostrarProductos(argv[ARG_PRODUCTOS]);
    putchar('\n');

    ret = actualizarProductos(argv[ARG_PRODUCTOS], argv[ARG_MOVIMIENTOS]);
    if(ret != TODO_OK)
        return ret;

    puts("Despues:");
    mostrarProductos(argv[ARG_PRODUCTOS]);
    putchar('\n');

    return 0;
}
