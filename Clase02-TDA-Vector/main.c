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
    /*int resIns = vectorEliminarValor(&unVec, 49);
    if (resIns == 0)
        puts("Se elimino correctamente");
    else if (resIns == 3)
        puts("No se elimino correctamente");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Buscar en vector ordenado
    /*int resIns = vectorBuscarElemOrd(&unVec, 3);
    if (resIns == 0)
        puts("Elemento encontrado ");
    else if (resIns == 3)
        puts("No se encontro el elemento");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar en vector ordenado
    /*int resIns = vectorEliminarValorOrd(&unVec, 5);
    if (resIns == 0)
        puts("Se elimino el elemento");
    else if (resIns == 3)
        puts("No se pudo eliminar el elemento, ya que no se encuentra");
    mostrar(&unVec);*/
// ---------------------------------------------------------------------------------------------------------------
    /// Eliminar valores duplicados en un vector ordenado
    int resIns = vectorEliminarDupOrd(&unVec, 0);
    if (resIns == 0)
        puts("Se eliminaron los elementos duplicados");
    else if (resIns == 3)
        puts("No hay elementos duplicados");
    mostrar(&unVec);


    return 0;
}
