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
//Funcion que permite analizar si el nodo es hoja, es decir, uno de los ultimos nodos
int esHoja(nodoArbolstProducto * arbol)
{
    if ((arbol->izq == NULL)&&(arbol->der == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Funcion para borrar un nodo por idProducto
nodoArbolstProducto * borrarNodo(nodoArbolstProducto * nodo,int idProducto)
{
    if(nodo == NULL)
    {

    }
    else
    {
        if(nodo->producto.idProducto == idProducto)
        {
            if(nodo->izq!=NULL)
            {
                nodoArbolstProducto * masDerecha = nodoMasDerecha(nodo->izq);
                nodo->producto = masDerecha->producto;
                nodo->izq = borrarNodo(nodo->izq,masDerecha->producto.idProducto);
            }
            else if (nodo->der!=NULL)
            {
                nodoArbolstProducto * masIzquierda = nodoMasIzquierda(nodo->der);
                nodo->producto = masIzquierda->producto;
                nodo->der = borrarNodo(nodo->der,masIzquierda->producto.idProducto);
            }

            else
            {
                if (esHoja(nodo) == 1)
                {
                    free(nodo);
                    nodo = NULL;
                }
            }
        }
        else if (idProducto > nodo->producto.idProducto)
        {
            nodo->der = borrarNodo(nodo->der,idProducto);
        }
        else if (idProducto < nodo->producto.idProducto)
        {
             nodo->izq = borrarNodo(nodo->izq,idProducto);
        }

    }
    return nodo;
}
//Funcion para retornar el nodo mas a la derecha del arbol
nodoArbolstProducto * nodoMasDerecha(nodoArbolstProducto * nodo)
{
    if (nodo!=NULL)
    {
        if (nodo->der!=NULL)
        {
            nodo = nodoMasDerecha(nodo->der);
        }
    }
    return nodo;
}
//Funcion para retornar el nodo mas a la izquierda del arbol
nodoArbolstProducto * nodoMasIzquierda(nodoArbolstProducto * nodo)
{
    if (nodo!=NULL)
    {
        if (nodo->izq!=NULL)
        {
            nodo = nodoMasIzquierda(nodo->izq);
        }
    }
    return nodo;
}
//Funcion para buscar el nodo por idProducto
nodoArbolstProducto * buscarPorIdProducto (nodoArbolstProducto * nodo,int idProducto)
{
    nodoArbolstProducto * aux;
    if (nodo!=NULL)
    {
        if (nodo->producto.idProducto == idProducto)
        {
            aux = nodo;
        }else
        {
            buscarPorLegajo(nodo->der,idProducto);
            buscarPorLegajo(nodo->izq,idProducto);
        }
    }
    return aux;
}
