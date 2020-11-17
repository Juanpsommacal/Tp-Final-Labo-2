#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "string.h"
#include <stdlib.h>
#include "Producto.h"

typedef struct
{
    stProducto producto;
    struct nodoListaProducto* siguiente;
}nodoListaProducto;

//Inicializa los valores de la lista en NULL para el correcto funcionamiento del resto de los algoritmos
nodoListaProducto* inicializarLista();

//Crea un nodo para la lista de productos
nodoListaProducto* crearNodoLista(stProducto producto);

//Agrega un nuevo nodo al principio de la lista
nodoListaProducto* agregarAlPrincipio(nodoListaProducto* lista, nodoListaProducto* nuevoNodo);

//Busca el ultimo nodo de la lista
nodoListaProducto* buscarUltimoNodo(nodoListaProducto* lista);

//Agrega un nuevo nodo al final de la lista
nodoListaProducto* agregarAlFinal(nodoListaProducto* lista, nodoListaProducto* nuevoNodo);

//Agrega un nuevo nodo a la lista, por orden de producto alfabetico
nodoListaProducto* agregarEnOrdenPorNombreDeProducto(nodoListaProducto* lista, nodoListaProducto* nuevoNodo);

//Muestra la lista
void mostrarLista(nodoListaProducto* lista);

//Borra un nodo, buscandolo por su ID
nodoListaProducto* borrarNodoPorIdProducto(nodoListaProducto* lista, int idABorrar);

//Borra un nodo, sirve para borrar toda la lista
nodoListaProducto * borrarNodo(nodoListaProducto * lista);

//Suma el total de costos de la lista
float contarTotalPedido(nodoListaProducto* lista);
#endif // LISTAS_H_INCLUDED
