#include "funciones.h"

int generarProductos(const char* fileName)
{
    Producto productos[CANT_PROD] = {
        {"00", "Higo", 100},
        {"04", "Banana", 100},
        {"07", "Pera", 50},
        {"09", "Manzana", 70},
        {"14", "Durazno", 90},
        {"16", "Sandia", 90}
    };
    FILE* fileProd = fopen(fileName, "wb");
    if(!fileProd)
    {
        puts("Error al crear el archivo de productos\n");
        return ERROR_ARCHIVOS;
    }
    fwrite(productos, sizeof(Producto), CANT_PROD, fileProd);
    fclose(fileProd);
    return TODO_OK;

}

int generarMovimientos(const char* fileName)
{
    Movimiento movimientos[CANT_MOV] = {
        {"01", 20},
        {"07", 20},
        {"07", -10},
        {"08", 40},
        {"12", 60},
        {"12", -10},
        {"15", 80},
        {"15", 40},
    };
    FILE* fileMov = fopen(fileName, "wb");
    if(!fileMov)
    {
        puts("Error al crear el archivo de movimientos\n");
        return ERROR_ARCHIVOS;
    }
    fwrite(movimientos, sizeof(movimientos), CANT_MOV, fileMov);
    fclose(fileMov);
    return TODO_OK;
}

int mostrarProductos(const char* fileName)
{
    FILE* fileProd = fopen(fileName, "rb");
    if(!fileProd)
    {
        puts("Error al abrir el archivo de productos\n");
        return ERROR_ARCHIVOS;
    }

    Producto prod;
    while(!feof(fileProd))
    {
        printf("%-6s %-20s %03d\n", prod.codigo, prod.descripcion, prod.stock);
        fread(&prod, sizeof(Producto), 1, fileProd);
    }
    fclose(fileProd);
    return TODO_OK;
}

int actualizarProductos(const char * fileNameProd, const char* fileNameMov)
{
    FILE* fileProd = fopen(fileNameProd, "rb");
    if(!fileProd)
        return ERROR_ARCHIVOS;

    FILE* fileMov = fopen(fileNameMov, "rb");
    if(!fileMov)
    {
        fclose(fileProd);
        return ERROR_ARCHIVOS;
    }

    FILE* fileProdTmp = fopen(NOM_ARCH_PROD_TMP, "wb");
    if(!fileProdTmp)
    {
        fclose(fileProd);
        fclose(fileMov);
        return ERROR_ARCHIVOS;
    }

    Producto prod;
    Movimiento mov;
    int comp;

    fread(&prod, sizeof(Producto), 1, fileProd);
    fread(&mov, sizeof(Movimiento), 1, fileMov);
    while(!feof(fileProd) && !feof(fileMov))
    {
        comp = strcmp(prod.codigo, mov.codigo);
        if(comp == 0)
        {
            prod.stock += mov.cantidad;
            fread(&mov, sizeof(Movimiento), 1, fileMov);
        }

        if(comp < 0) /// Producto sin movimientos
        {
            fwrite(&prod, sizeof(Producto), 1, fileProdTmp);
            fread(&prod, sizeof(Producto), 1, fileProd);
        }

        if(comp > 0) /// Movimiento sin producto (Producto nuevo)
            procesarProductoNuevo(&mov, fileMov, fileProdTmp);
    }

    while(!feof(fileProd))
    {
        fwrite(&prod, sizeof(Producto), 1, fileProdTmp);
        fread(&prod, sizeof(Producto), 1, fileProd);
    }

    while(!feof(fileMov))
        procesarProductoNuevo(&mov, fileMov, fileProdTmp);

    fclose(fileProd);
    fclose(fileMov);
    fclose(fileProdTmp);

    remove(fileNameProd);
    rename(NOM_ARCH_PROD_TMP, fileNameProd);

    return TODO_OK;
}

void procesarProductoNuevo(Movimiento* mov, FILE* fileMov, FILE* fileProdTmp)
{
    Producto prodNuevo;
    strcpy(prodNuevo.codigo, mov->codigo);
    *prodNuevo.descripcion = '\0';
    prodNuevo.stock = mov->cantidad;
    fread(mov, sizeof(Movimiento), 1, fileMov);
    while(!feof(fileMov) && strcmp(prodNuevo.codigo, mov->codigo) == 0)
    {
        prodNuevo.stock += mov->cantidad;
        fread(mov, sizeof(Movimiento), 1, fileMov);
    }
    fwrite(&prodNuevo, sizeof(Producto), 1, fileProdTmp);
}
