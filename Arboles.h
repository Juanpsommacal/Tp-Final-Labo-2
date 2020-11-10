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

//Busca el nodo de mas izquierda del arbol
nodoArbolstProducto* buscarMasIzquierda(nodoArbolstProducto* raiz);

//Busca el nodo de mas derecha del arbol
nodoArbolstProducto* buscarMasDerecha(nodoArbolstProducto* raiz);

//Devuelve 1 si el nodoArbol es hoja, 0 si no lo es
int esHoja(nodoArbolstProducto* raiz);

//Busca un nodo en un arbol y lo retorna
nodoArbolstProducto* buscarNodoArbol(nodoArbolstProducto* raiz, int idABuscar);

//Busca un producto por su ID en el arbol y lo elimina, devuelve 1 si se cambio con exito, o 0 si no se pudo cambiar
int cambiarEstadoNodoArbol(nodoArbolstProducto* raiz, int idABorrar);

//Carga un arbol binario desde el archivo de productos ordenados por ID
nodoArbolstProducto* cargarArbolDesdeArchivo(char nombreArchivo[]);

#endif // ARBOLES_H_INCLUDED
