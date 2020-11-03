#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include "Producto.h"

typedef struct
{
    stProducto producto;
    struct nodoArbolstProducto* izq;
    struct nodoArbolstProducto* der;
}nodoArbolstProducto;

//Inicializa los valores de un arbol en NULL para el correcto funcionamiento de los demas algoritmos
nodoArbolstProducto* inicializarArbol();

//Crea un nodo para el arbol de productos
nodoArbolstProducto* crearNodoArbol(stProducto producto);

//Inserta un nodo en el arbol por orden de ID del producto
nodoArbolstProducto* insertarNodoArbol(nodoArbolstProducto* raiz, stProducto producto);

//Muestra un nodo de un arbol si no figura como eliminado
void mostrarNodo(nodoArbolstProducto* raiz);

//Muestra el arbol en pre orden
void preOrden(nodoArbolstProducto * nodo);

//Muestra el arbol en post orden
void postOrden(nodoArbolstProducto * nodo);

//Muestra el arbol en in orden
void inOrden(nodoArbolstProducto * nodo);

//Muestra el contenido del arbol, de 3 formas distintas
void mostrar(nodoArbolstProducto * raiz, int modoMostrar);

#endif // ARBOLES_H_INCLUDED
