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

#endif // ARBOLES_H_INCLUDED
