#include "funciones.h"

int crearArticulos(const char* fileName){
    Articulo art[CANT_PROD] = {
        {1, 10.0, "Pelota Futbol"},
        {2, 15.0, "Raqueta"},
        {3, 9.0, "Pelota Basquet"},
        {4, 100.0, "Bicicleta"},
        {5, 7.0, "Guantes de Boxeo"},
        {6, 3.0, "Antiparras"},
        {7, 55.0, "Zapatillas Running"},
        {8, 12.0, "Casco para ciclismo"},
        {9, 8.0, "Pelota de Voley"},
        {10, 65.0, "Equipo de Golf"}
    };

    FILE* pf = fopen(fileName, "wb");
    if(!pf){
        puts("Error al crear archivo de productos.\n");
        return ERROR_FILE;
    }
    fwrite(art, sizeof(Articulo), CANT_PROD, pf);
    fclose(pf);
    return TODO_OK;
}

int mostrarArticulos(const char* fileName){
    FILE* pf = fopen(fileName, "rb");
    if(!pf){
        puts("Error al abrir el archivo de productos.\n");
        return ERROR_FILE;
    }

    Articulo art;
    fread(&art, sizeof(Articulo), 1, pf);
    puts("Cod Precio     Descripcion\n");
    while(!feof(pf)){
         printf("%-3d %-10.2f %-20s\n", art.codArt, art.precio, art.descripcion);
         fread(&art, sizeof(Articulo), 1, pf);
    }
    fclose(pf);
    return TODO_OK;
}

int actualizarArticulos(const char* fileName){
    FILE* pf = fopen(fileName, "r+b");
    if(!pf){
        puts("Error al abrir el archivo de productos.\n");
        return ERROR_FILE;
    }

    Articulo art;
    fseek(pf, 0L, SEEK_END);
    unsigned tam = sizeof(Articulo);
    int cantRegs = ftell(pf) / tam;
    rewind(pf);
    for(int i = 0; i < cantRegs; i++){
        fflush(pf);
        fread(&art, sizeof(Articulo), 1, pf);
        art.precio *= 1.15;
        fseek(pf, -1 * tam, SEEK_CUR);
        fwrite(&art, sizeof(Articulo), 1, pf);
    }

    fclose(pf);
    return TODO_OK;
}
