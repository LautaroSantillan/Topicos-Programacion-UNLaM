#include "funciones.h"
/// Productos.dat
int main(int argc, char* argv[])
{
    crearArticulos(argv[1]);
    mostrarArticulos(argv[1]);
    puts("\nDespues de la actualizacion de precios.\n");
    ///Supongamos que queremos aumentar un %15 el valor de c/art
    actualizarArticulos(argv[1]);
    mostrarArticulos(argv[1]);
    return TODO_OK;
}
