#include "funciones.h"

int main()
{
    MiVector vec;
    vectorCrear(&vec);
    vectorOrdInsertar(&vec, 45);
    vectorOrdInsertar(&vec, 54);
    vectorOrdInsertar(&vec, 312);
    vectorOrdInsertar(&vec, 254);
    vectorOrdInsertar(&vec, 12);
    vectorOrdInsertar(&vec, 0);
    vectorOrdInsertar(&vec, 34);
    mostrar(&vec);
    puts("\n");
    vectorOrdEliminarElem(&vec, 45);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Insertar elemento al Principio
    vectorInsertarPrin(&vec, 87);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Insertar elemento al Final
    vectorInsertarFin(&vec, 521);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Insertar elemento en X posicion
    vectorInsertarCualPos(&vec, 10, 3);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Buscar elemento
    vectorOrdBuscarElem(&vec, 254);
    puts("\n");

    return 0;
}
