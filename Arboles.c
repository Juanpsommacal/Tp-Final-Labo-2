#include "Arboles.h"
#include <stdlib.h>

//Inicializa los valores de un arbol en NULL para el correcto funcionamiento de los demas algoritmos
nodoArbolstProducto* inicializarArbol()
{
    return NULL;
}

//Crea un nodo para el arbol de productos
nodoArbolstProducto* crearNodoArbol(stProducto producto)
{
    //Reservamos el espacio en la memoria
    nodoArbolstProducto* aux = (nodoArbolstProducto*) malloc(sizeof(nodoArbolstProducto));
    //Asignamos NULL a las ramas y le asignamos el producto al nuevo nodo
    aux->producto = producto;
    aux->izq = NULL;
    aux->der = NULL;
    //Retornamos el nodo
    return aux;
}

//Inserta un nodo en el arbol por orden de ID del producto
nodoArbolstProducto* insertarNodoArbol(nodoArbolstProducto* raiz, stProducto producto)
{
    //Si no hay raiz, la raiz ahora es el nuevo nodo
    if(raiz == NULL)
    {
        raiz = crearNodoArbol(producto);
    }
    //Si ya hay raiz, nos fijamos si la id del producto es menor o mayor que la raiz en la que estamos actualmente
    else
    {
        if(producto.idProducto < raiz->producto.idProducto)
            raiz->izq = insertarNodoArbol(raiz->izq, producto);
        else
            raiz->der = insertarNodoArbol(raiz->der, producto);
    }
    //Devolvemos la raiz
    return raiz;
}

//Muestra el contenido del arbol, de 3 formas distintas, a eleccion del usuario
void mostrarNodo(nodoArbolstProducto* raiz)
{
    //Verificamos que el producto no este eliminado para poder mostrarlo
    if (raiz->producto.eliminado == 0)
    {
        mostrarProducto(raiz->producto);
    }
}
void preOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        mostrarNodo(nodo);
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}
void postOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        postOrden(nodo->izq);
        postOrden(nodo->der);
        mostrarNodo(nodo);
    }
}
void inOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        inOrden(nodo->izq);
        mostrarNodo(nodo);
        inOrden(nodo->der);
    }
}
void mostrar(nodoArbolstProducto * raiz,int modoMostrar)
{
    //Organizamos un menu con las distintas formas de mostrar el arbol de producto
    switch(modoMostrar)
    {
        case 1 : preOrden(raiz);
            break;
        case 2 : inOrden(raiz);
            break;
        case 3 : postOrden(raiz);
            break;
    }
}
