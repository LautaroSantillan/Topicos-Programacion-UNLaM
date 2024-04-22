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
//----------------------------------------
    /// Eliminar elemento en X posicion
    vectorEliminarPos(&vec, 7);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Eliminar primer elemento
    vectorEliminarPri(&vec);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Eliminar ultimo elemento
    vectorEliminarUlt(&vec);
    mostrar(&vec);
    puts("\n");
//----------------------------------------
    /// Eliminar elementos duplicados
    puts("\nEliminar Duplicados");
    MiVector vec2;
    vectorCrear(&vec2);
    vectorOrdInsertar(&vec2, 45);
    vectorOrdInsertar(&vec2, 54);
    vectorOrdInsertar(&vec2, 8);
    vectorOrdInsertar(&vec2, 8);
    vectorOrdInsertar(&vec2, 12);
    vectorOrdInsertar(&vec2, 0);
    vectorOrdInsertar(&vec2, 34);
    mostrar(&vec2);
    puts("\n");
    vectorOrdEliminarDup(&vec2, 8);
    mostrar(&vec2);
    puts("\n");

    return 0;
}
