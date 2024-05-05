#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
typedef struct Datos
{
    char *descripcion;
    int valor;
}Datos;

typedef struct TNodo
{
    Datos info;
    struct TNodo *siguiente;
}TNodo;

//**********************FUNCIONES**********************************
TNodo *crearListaVacia();
TNodo *crearNodo(Datos info);
void insertarNodo(TNodo **listaPrueba, Datos info);
Datos cargar();
void liberarMemoria(TNodo *tareas);
int main(int argc, char const *argv[])
{
    TNodo *ListaPrueba;
    ListaPrueba = crearListaVacia();
    Datos info = cargar();
    insertarNodo(&ListaPrueba, info);
    printf("%s, %d", ListaPrueba->info.descripcion, ListaPrueba->info.valor);
    liberarMemoria(ListaPrueba);
    return 0;
}

TNodo *crearListaVacia(){
    return NULL;
}
TNodo *crearNodo(Datos info){
    TNodo *nuevoNodo = (TNodo *)malloc(sizeof(TNodo));
    nuevoNodo->info= info;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(TNodo **listaPrueba, Datos info)
{
    TNodo *nuevoNodo = crearNodo(info);
    nuevoNodo->siguiente = *listaPrueba;
    *listaPrueba = nuevoNodo;
}

Datos cargar()
{
    Datos info;
    info.descripcion = "HOLA MUNDO";
    info.valor=200;
    return info;
}
void liberarMemoria(TNodo *tareas) {
    TNodo *aux = tareas;
    TNodo *auxAnterior = tareas;
    TNodo *auxActual = tareas;

    while (aux) {
        if (aux->info.descripcion) {
            free(aux->info.descripcion);
        }
        aux = aux->siguiente;
    }

    while (auxActual) {
        auxAnterior = auxActual;
        auxActual = auxActual->siguiente;
        free(auxAnterior);
    }
}
