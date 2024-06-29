/***************************************************************************************
******************************* Complete sus datos *************************************
****************************************************************************************
* Apellido, Nombres: Santillan, Lautaro Ezequiel
*
* DNI: 45175053
*
***************************************************************************************/
/***************************************************************************************
********************* Descomente la solución que quiere probar: ************************
***************************************************************************************/
#define SOLUCION_DOC
//#define SOLUCION_ALU
/***************************************************************************************
************************************ Corrección ****************************************
****************************************************************************************
*
****************************************************************************************
* Nota:
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Vector/Vector.h"
#include "../SolucionParcialDeliveryTopicos/TiposDelivery.h"
#include "../SolucionParcialDeliveryTopicos/SolucionDelivery.h"
#include "../UtilitariasTopicos/Utilitarias.h"

void trozarRegistro(char* linea, Pedido* reg);
char* strchr_ALU(const char* str, int caracter);
char* strcpy_ALU(char *dest, const char *orig);

int main()
{
	generarArchivoPedidos();
	generarArchivoRecetas();
	generarArchivoIngredientes();

	mostrarArchivoPedidos("Pedidos.txt");
	mostrarArchivoRecetas("Recetas.dat");

	puts("Ingredientes antes de la actualizacion");
	mostrarArchivoIngredientes("Ingredientes.dat");

	int resp;

#ifdef SOLUCION_DOC
	resp = satisfacerPedidos("Pedidos.txt", "Recetas.dat", "Ingredientes.dat");
#else
	resp = satisfacerPedidos_ALU("Pedidos.txt", "Recetas.dat", "Ingredientes.dat");
#endif

	if(resp != TODO_OK)
	{
		puts("Error actualizando los pedidos.");
		return resp;
	}

	puts("Ingredientes despues de la actualizacion");
	mostrarArchivoIngredientes("Ingredientes.dat");

	return TODO_OK;
}


///Procesa los pedidos del archivo Pedidos.txt, actualizando el archivo Ingredientes.dat, para que �ste refleje la cantidad que queda en stock luego de despachar los pedidos.
int satisfacerPedidos_ALU(const char* nombreArchPedidos, const char* nombreArchRecetas, const char* nombreArchIngredientes)
{
    FILE* fileRecetas = fopen(nombreArchRecetas, "rb");
    if(!fileRecetas){
        puts("Error al abrir el archivo de recetas.\n");
        return ERR_ARCHIVO;
    }
    FILE* fileIngredientes = fopen(nombreArchIngredientes, "r+b");
    if(!fileIngredientes){
        puts("Error al abrir el archivo de ingredientes.\n");
        fclose(fileRecetas);
        return ERR_ARCHIVO;
    }
    FILE* filePedidos = fopen(nombreArchPedidos, "rt");
    if(!filePedidos){
        puts("Error al abrir el archivo de pedidos.\n");
        fclose(fileRecetas);
        fclose(fileIngredientes);
        return ERR_ARCHIVO;
    }

    Receta rec;
    Ingrediente ingr;
    Pedido ped;
    Vector vecRecetas;
    char linea[100];

    fseek(fileRecetas, 0L, SEEK_END);
    size_t tamanio = ftell(fileRecetas) / sizeof(Receta);
    fseek(fileRecetas, 0L, SEEK_SET);
    vectorCrear(&vecRecetas, tamanio);

    fread(&rec, sizeof(Receta), 1, fileRecetas);
    fread(&ingr, sizeof(Ingrediente), 1, fileIngredientes);
    trozarRegistro(linea, &ped);

    while(!feof(fileRecetas) && !feof(fileIngredientes) && fgets(linea, sizeof(linea), filePedidos)){
        while(strcmp(ped.codReceta, rec.codReceta) == 0){
            while(strcmp(ingr.codIngr, rec.codIngr) == 0){
                fflush(fileIngredientes);
                ingr.stock -= rec.cantidad;
                fseek(fileIngredientes, -(long)sizeof(Ingrediente), SEEK_CUR);
                fwrite(&ingr, sizeof(Ingrediente), 1, fileIngredientes);
           }
           fread(&ingr, sizeof(Ingrediente), 1, fileIngredientes);
        }
        fread(&rec, sizeof(Receta), 1, fileRecetas);
        trozarRegistro(linea, &ped);
    }

    fclose(fileRecetas);
    fclose(fileIngredientes);
    fclose(filePedidos);
	return TODO_OK;
}

void trozarRegistro(char* linea, Pedido* reg){
    char* punteroLinea;

    punteroLinea = strchr_ALU(linea, '|');
    punteroLinea = '\0';
    sscanf(linea, "%d", &reg->nroPedido);
    punteroLinea++;

    punteroLinea = strchr_ALU(linea, '|');
    punteroLinea = '\0';
    strcpy_ALU(linea, reg->codReceta);
    punteroLinea++;

    punteroLinea = strchr_ALU(linea, '|');
    sscanf(linea, "%d", &reg->cantidad);
}

char* strchr_ALU(const char* str, int caracter){
    while(*str != '\0'){
        if(*str == (char)caracter)
            return (char*)str;
        str++;
    }
    return NULL;
}

char* strcpy_ALU(char *dest, const char *orig){
    char *aux = dest;
    while(*orig){
        *dest=*orig;
        orig++;
        dest++;
    }
    *dest='\0';
    return aux;
}
