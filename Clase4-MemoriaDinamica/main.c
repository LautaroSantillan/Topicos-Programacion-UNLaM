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

    return 0;
}
