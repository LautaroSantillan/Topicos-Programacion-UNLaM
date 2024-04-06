#include "funciones.h"

int main()
{
    Vector unVec;
    int valores[] = {0, 10, 49, 23, 77, 60, 7, 8, 49, 87, 98, 15, 56, 49, 21};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); ++i) {
        unVec.vec[i] = valores[i];
    }
    unVec.ce = sizeof(valores) / sizeof(valores[0]);

// ---------------------------------------------------------------------------------------------------------------
    /// CREAR VECTOR
    //vectorCrear(&unVec); // Inicializar un vector (TDA)
// ---------------------------------------------------------------------------------------------------------------
    /// Insertar en orden
    /*int resIns = vectorInsertarOrd(&unVec,5); //Resultado de la insercion
    if (resIns == 2)
        puts("El vector esta lleno");
    else if (resIns == 1)
        puts("El elemento esta duplicado");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Insertar al principio
    /*int resIns = vectorInsertarPrin(&unVec, 45);
    if (resIns == 2)
        puts("El vector esta lleno");
    else if (resIns == 1)
        puts("El elemento esta duplicado");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Insertar al final
    /*int resIns = vectorInsertarFin(&unVec, 45);
    if (resIns == 2)
        puts("El vector esta lleno");
    else if (resIns == 1)
        puts("El elemento esta duplicado");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Insertar en cualquier posicion
    /*int resIns = vectorInsertarCualPos(&unVec, 11, 888);
    if (resIns == 2)
        puts("El vector esta lleno");
    else if (resIns == 1)
        puts("El elemento esta duplicado");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar por posicion
    /*int resIns = vectorEliminarPos(&unVec, 80);
    if (resIns == 0)
        puts("Se elimino correctamente");
    else if (resIns == 3)
        puts("No se elimino correctamente");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar primero
    /*int resIns = vectorEliminarPri(&unVec);
    if (resIns == 0)
        puts("Se elimino correctamente");
    else if (resIns == 3)
        puts("No se elimino correctamente");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar ultimo
    /*int resIns = vectorEliminarUlt(&unVec);
    if (resIns == 0)
        puts("Se elimino correctamente");
    else if (resIns == 3)
        puts("No se elimino correctamente");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar por valor
    int resIns = vectorEliminarValor(&unVec, 49);
    if (resIns == 0)
        puts("Se elimino correctamente");
    else if (resIns == 3)
        puts("No se elimino correctamente");
    mostrar(&unVec);


    return 0;
}
