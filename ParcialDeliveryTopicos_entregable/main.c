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
//#define SOLUCION_DOC
#define SOLUCION_ALU
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

//void trozarRegistro(char* linea, Pedido* reg);
//char* strchr_ALU(const char* str, int caracter);
char* strcpy_ALU(char *dest, const char *orig);

void leerPedidos_ALU(const char* nombreArchPedidos, Vector* pedidos);
void generarIndices_ALU(Vector* indRecetas, Vector* indIngredientes);
void procesarPedido_ALU(const Pedido* pedido, Vector* recetas, Vector* ingredientes);
void cargarIngredientesReceta_ALU(const char* codReceta, Vector* recetas, Vector* ingredientesReceta);
void actualizarStock_ALU(const char* codIngr, int cantidad, Vector* ingredientes);
void trozarRegistro(char* linea, Pedido* reg);
void copiarIndiceRecetas(void* pvIdx, const void* pvReg, int nroReg);
void copiarIndiceIngredientes(void* pvIdx, const void* pvReg, int nroReg);
int compararRecetas(const void* e1, const void* e2);
int compararIngredientes(const void* e1, const void* e2);
void copiarReceta(void* pvDest, const void* pvOrig);

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
    Vector pedidos;
    vectorCrear(&pedidos, sizeof(Pedido));

    leerPedidos_ALU(nombreArchPedidos, &pedidos);

    Vector indRecetas, indIngredientes;
    vectorCrear(&indRecetas, sizeof(IndReceta));
    vectorCrear(&indIngredientes, sizeof(IndIngrediente));

    generarIndices_ALU(&indRecetas, &indIngredientes);

    Vector ingredientes;
    vectorCargarDeArchivo(nombreArchIngredientes, &ingredientes, sizeof(Ingrediente));

    VectorIterador it;
    vectorItCrear(&it, &pedidos);

    Pedido* pedido;
    while ((pedido = vectorItSiguiente(&it)) != NULL) {
        procesarPedido_ALU(pedido, &indRecetas, &ingredientes);
    }

    vectorGrabar(&ingredientes, nombreArchIngredientes);

    vectorDestruir(&pedidos);
    vectorDestruir(&indRecetas);
    vectorDestruir(&indIngredientes);
    vectorDestruir(&ingredientes);

    return TODO_OK;
}

void leerPedidos_ALU(const char* nombreArchPedidos, Vector* pedidos) {
    FILE* fp = fopen(nombreArchPedidos, "rt");
    if (!fp) {
        perror("Error abriendo archivo de pedidos");
        return;
    }

    Pedido pedido;
    char linea[256];
    while (fgets(linea, sizeof(linea), fp)) {
        trozarRegistro(linea, &pedido);
        vectorInsertarAlFinal(pedidos, &pedido);
    }

    fclose(fp);
}

void generarIndices_ALU(Vector* indRecetas, Vector* indIngredientes) {
    generarIndice("Recetas.dat", sizeof(Receta), sizeof(IndReceta), copiarIndiceRecetas, compararRecetas);
    generarIndice("Ingredientes.dat", sizeof(Ingrediente), sizeof(IndIngrediente), copiarIndiceIngredientes, compararIngredientes);
}

void procesarPedido_ALU(const Pedido* pedido, Vector* recetas, Vector* ingredientes) {
    // Cargar la receta en el vector
    Vector ingredientesReceta;
    vectorCrear(&ingredientesReceta, sizeof(Receta));

    cargarIngredientesReceta_ALU(pedido->codReceta, recetas, &ingredientesReceta);

    // Descontar ingredientes
    VectorIterador it;
    vectorItCrear(&it, &ingredientesReceta);

    Receta* receta;
    while ((receta = vectorItSiguiente(&it)) != NULL) {
        actualizarStock_ALU(receta->codIngr, receta->cantidad * pedido->cantidad, ingredientes);
    }

    vectorDestruir(&ingredientesReceta);
}

void cargarIngredientesReceta_ALU(const char* codReceta, Vector* recetas, Vector* ingredientesReceta) {
    IndReceta indBuscado = { .codReceta = "" };
    strcpy_ALU(indBuscado.codReceta, codReceta);

    IndReceta* indReceta = vectorOrdBuscar(recetas, &indBuscado, compararRecetas);
    if (indReceta) {
        int nroReg = indReceta->nroReg;
        Receta receta;

        while (nroReg < vectorCantidadElementos(recetas)) {
            vectorRecorrer(recetas, copiarReceta, &receta);
            if (strcmp(receta.codReceta, codReceta) == 0) {
                vectorInsertarAlFinal(ingredientesReceta, &receta);
            }
        }
    }
}

void actualizarStock_ALU(const char* codIngr, int cantidad, Vector* ingredientes) {
    Ingrediente ingrBuscado = { .codIngr = "" };
    strcpy_ALU(ingrBuscado.codIngr, codIngr);

    Ingrediente* ingrediente = vectorOrdBuscar(ingredientes, &ingrBuscado, compararIngredientes);
    if (ingrediente) {
        ingrediente->stock -= cantidad;
    }
}

void copiarReceta(void* pvDest, const void* pvOrig) {
    Receta* dest = (Receta*)pvDest;
    const Receta* orig = (const Receta*)pvOrig;
    strcpy_ALU(dest->codReceta, orig->codReceta);
    strcpy_ALU(dest->codIngr, orig->codIngr);
    dest->cantidad = orig->cantidad;
}

void trozarRegistro(char* linea, Pedido* reg) {
    char* token = strtok(linea, ",");
    reg->nroPedido = atoi(token);
    token = strtok(NULL, ",");
    strcpy_ALU(reg->codReceta, token);
    token = strtok(NULL, ",");
    reg->cantidad = atoi(token);
}

void copiarIndiceRecetas(void* pvIdx, const void* pvReg, int nroReg) {
    IndReceta* idx = (IndReceta*)pvIdx;
    const Receta* reg = (const Receta*)pvReg;
    strcpy_ALU(idx->codReceta, reg->codReceta);
    idx->nroReg = nroReg;
}

void copiarIndiceIngredientes(void* pvIdx, const void* pvReg, int nroReg) {
    IndIngrediente* idx = (IndIngrediente*)pvIdx;
    const Ingrediente* reg = (const Ingrediente*)pvReg;
    strcpy_ALU(idx->codIngr, reg->codIngr);
    idx->nroReg = nroReg;
}

int compararRecetas(const void* e1, const void* e2) {
    const IndReceta* rec1 = (const IndReceta*)e1;
    const IndReceta* rec2 = (const IndReceta*)e2;
    return strcmp(rec1->codReceta, rec2->codReceta);
}

int compararIngredientes(const void* e1, const void* e2) {
    const IndIngrediente* ingr1 = (const IndIngrediente*)e1;
    const IndIngrediente* ingr2 = (const IndIngrediente*)e2;
    return strcmp(ingr1->codIngr, ingr2->codIngr);
}


/*void trozarRegistro(char* linea, Pedido* reg){
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
}*/

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
