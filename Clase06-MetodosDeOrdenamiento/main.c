#include "funciones.h"

int main()
{
// -------------------------------------------------------------------------------
    /// CREAR VECTOR E INSERTAR
    /*MiVector vec;
    vectorCrear(&vec);
    vectorInsertarFin(&vec, 120);
    vectorInsertarFin(&vec, 64);
    vectorInsertarFin(&vec, 12);
    vectorInsertarFin(&vec, 26);
    vectorInsertarFin(&vec, 8);
    vectorInsertarFin(&vec, 0);
    vectorInsertarFin(&vec, 33);
    vectorInsertarFin(&vec, 19);
    vectorInsertarFin(&vec, 1);
    vectorInsertarFin(&vec, 61);
    vectorInsertarFin(&vec, 24);
    vectorInsertarFin(&vec, 99);
    vectorInsertarFin(&vec, 84);
    vectorInsertarFin(&vec, 56);
    vectorMostrar(&vec);
    puts("\n");
    /// METODO: BURBUJEO
    puts("--- BURBUJEO ---");
    vectorOrdenarBurbujeo(&vec);
    vectorMostrar(&vec);
    puts("\n");
    /// METODO: SELECCION
    puts("--- SELECCION ---");
    vectorOrdenarSeleccion(&vec);
    vectorMostrar(&vec);
    puts("\n");
    /// METODO: INSERCION
    puts("--- INSERCION ---");
    vectorOrdenarInsercion(&vec);
    vectorMostrar(&vec);
    free(vec.vec);
    puts("\n");*/
// -------------------------------------------------------------------------------
    /// TIEMPO DE EJECUCION C/METODO
    MiVector vecRandom;
    vectorInicializarRandom(&vecRandom, 6000);
    vectorMostrar(&vecRandom);
    puts("\n");
     /// Ordenar vector y contabilizar tiempo
//    int segInicial = time(NULL);
//    vectorOrdenarBurbujeo(&vecRandom);
//    int segFin = time(NULL);
//    printf("TIEMPO: %d\n", segFin-segInicial);
    //vectorMostrar(&vecRandom);
    free(vecRandom.vec);
    puts("\n");

    return 0;
}
