#include "funciones.h"

int contarProductos(const char* fileName){
    FILE* pf = fopen(fileName, "r");
    if(!pf){
        puts("Error al abrir el archivo\n");
        return ERROR_FILE;
    }

    char aux[100];
    int cant = 0;
    while(fgets(aux, 100, pf))
        cant++;

    fclose(pf);
    return cant;
}

int procesarProductos(const char* fileName, Vector* vecProd){
    FILE* pf = fopen(fileName, "r");
    if(!pf){
        puts("Error al abrir el archivo\n");
        return ERROR_FILE;
    }

    Producto prodActual;
    char linea[100];

    while(fgets(linea, 100, pf)){
        trozar(&prodActual, linea);
        insertarOrdenado(vecProd, &prodActual, compararDescripcion);
    }

    fclose(pf);
    return TODO_OK;
}

void trozar(Producto *prod, char* linea){
    char* punteroLinea = strrchr(linea, '|');
    *punteroLinea = '\0';
    punteroLinea++;
    sscanf(punteroLinea, "%f", &prod->precio);

    punteroLinea = strrchr(linea, '|');
    *punteroLinea = '\0';
    punteroLinea++;
    strcpy(prod->descripcion, punteroLinea);

    sscanf(linea, "%d", &prod->cod);

    mostrarProducto(prod);
}

void mostrarProducto(const void* a){
    Producto *prod = (Producto*) a;
    printf("%d %.2f %-20s\n", prod->cod, prod->precio, prod->descripcion);
}

int compararDescripcion(const void* a, const void* b){
    Producto* aux1 = (Producto*) a;
    Producto* aux2 = (Producto*) b;
    return strcmpi(aux1->descripcion, aux2->descripcion);
}

int crearVector(Vector* vec, int ce, unsigned tam){
    vec->vec = malloc(ce * tam);
    if(!vec->vec)
        return ERROR_MEM;

    vec->capacidad = ce;
    vec->ce = 0;
    vec->tam = tam;
    return TODO_OK;
}

void recorrerVector(Vector* vec, accion Accion){
    void* ini;
    void* ult = vec->vec + vec->ce * vec->tam;
    for(ini = vec->vec; ini < ult; ini += vec->tam)
        Accion(ini);
}

int insertarOrdenado(Vector* vec, const Producto* prod, int (*comparar)(const void*, const void*)) {
    if (vec->ce >= vec->capacidad) {
        puts("No hay espacio en el vector\n");
        return ERROR_MEM;
    }

    void* ini = vec->vec;
    void* ult = vec->vec + vec->ce * vec->tam;
    void* pos = ini;

    while (pos < ult && comparar(pos, prod) < 0)
        pos += vec->tam;

    if (pos < ult)
        memmove(pos + vec->tam, pos, ult - pos);

    memcpy(pos, prod, vec->tam);
    vec->ce++;
    return TODO_OK;
}
