#include "funciones.h"

int main()
{
    /*int matriz[3][ORDEN3] =
    {
      {1,2,3},
      {4,5,6},
      {7,8,9}
    };
    int matriz4[4][ORDEN4] =
    {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
    };*/
////////////////////////////////////////////////////////////////////////////////////////
    /// Suma de los elementos de la Diagonal Principal
    /*int sumaDP = matrizSumarDiagPrin(ORDEN4, matriz4);
    printf("La suma de los elementos de la Diagonal Principal es: %d\n", sumaDP);*/
////////////////////////////////////////////////////////////////////////////////////////
    /// Crear Matriz c/ memoria dinamica
    int** matriz = (int**)matrizCrear(4, 4, sizeof(int));
    matrizCargarTest(matriz, 4, 4);
    int sumaDP = matrizSumarDiagPrin(matriz, 4);
    printf("Suma Diagonal Principal: %d\n", sumaDP);
    int sumaTrianSupDS = matrizSumarTriangSupDiagSecun(matriz, 4);
    printf("Suma Triangulo Superior Diagonal Secundaria: %d\n", sumaTrianSupDS);
    matrizEliminar((void**)matriz, 4);
    puts("\n");
////////////////////////////////////////////////////////////////////////////////////////
    /// Matriz producto c/ memoria dinamica
    puts("---Matriz Producto---");
    int** m1 = (int**)matrizCrear(2, 4, sizeof(int));
    int** m2 = (int**)matrizCrear(4, 3, sizeof(int));
    matrizCargarTest(m1, 2, 4);
    matrizCargarTest(m2, 4, 3);
    int** mp = matrizProducto(m1, m2, 2, 4, 3);
    matrizMostrar(mp, 2, 3);
    matrizEliminar((void**)m1, 2);
    matrizEliminar((void**)m2, 4);
    matrizEliminar((void**)mp, 2);

    return 0;
}
