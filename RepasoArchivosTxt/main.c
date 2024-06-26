#include "funciones.h"
/// productos.txt
int main(int argc, char* argv[])
{
    Vector vecProd;
    int cantProd = contarProductos(argv[1]);

    crearVector(&vecProd, cantProd, sizeof(Producto));
    procesarProductos(argv[1], &vecProd);

    puts("\nRecorriendo el vector\n");
    recorrerVector(&vecProd, mostrarProducto);

    return TODO_OK;
}
