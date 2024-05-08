#include "funciones.h"

int matrizSumarDiagPrin(int** matriz, int orden)
{
    int sumaDP = 0;
    for(int i = 0; i < orden; i++)
        sumaDP += matriz[i][i];
    return sumaDP;
}

int matrizSumarDiagSecun(int** matriz, int orden)
{
    int sumaDS = 0;
    for(int i = 0, j = orden - 1; i < orden; i++, j--)
        sumaDS += matriz[i][j];
    return sumaDS;
}

int matrizSumarTriangSupDiagSecun(int** matriz, int orden)
{
    int sumaTriangSupDiagSecun = 0;
    for(int i = 0, limJ = orden - 2; i <= orden - 2; i++, limJ--)
    {
        for(int j = 0; j <= limJ; j++)
            sumaTriangSupDiagSecun += matriz[i][j];
    }
    return sumaTriangSupDiagSecun;
}

void** matrizCrear(size_t filas, size_t cols, size_t tamElem)
{
    void** matriz = malloc(filas * sizeof(void*));
    if(!matriz)
        return NULL;

    void** ult = matriz + filas - 1;
    for(void** i = matriz; i <= ult; i++)
    {
        *i = malloc(cols * tamElem);
        if(!*i)
        {
            int filasADestruir = i - matriz;
            matrizEliminar(matriz, filasADestruir);
            return NULL;
        }
    }

    return matriz;
}

void matrizEliminar(void** matriz, size_t filas)
{
    void** ult = matriz + filas - 1;
    for(void** i = matriz; i < ult; i++)
        free(*i);
    free(matriz);
}

void matrizCargarTest(int** matriz, size_t filas, size_t cols)
{
    int cont = 1;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < cols; j++)
            matriz[i][j] = cont++;
    }
}

int** matrizProducto(int** m1, int**m2, size_t filasM1, size_t filasM1colsM2, size_t colsM2)
{
    int** matrizProd = (int**)matrizCrear(filasM1, colsM2, sizeof(int));

    for(int i = 0; i < filasM1; i++)
    {
        for(int j = 0; j < colsM2; j++)
        {
            matrizProd[i][j] = 0;
            for(int k = 0; k < filasM1colsM2; k++)
                matrizProd[i][j] += m1[i][k] * m2[k][j];
        }
    }

    return matrizProd;
}

void matrizMostrar(int** matriz, size_t filas, size_t cols)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }
}

void matrizMostrarEnEspiral(int** matriz, size_t filas, size_t cols)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = i; j < cols; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }
//    int i = 0;
//    for(int j = 0; j < cols; j++)
//        printf("%3d ", matriz[i][j]);
//    i++;
//    printf("%3d ", matriz[i][cols-1]);
//    i++;
//    for(int j = cols-1; j < filas; j--)
//        printf("%3d ", matriz[i][j]);
//    i--;
//    for(int j = 0; j < cols-1; j++)
//        printf("%3d ", matriz[i][j]);
}
