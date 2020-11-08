#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#include "Producto.h"

// Devuelve 1 si la id ya pertenece a otro producto
int VerificarIdProducto(char nombreArchivo[], int id);

//Retorna la cantidad de productos que hay en el archivo
int contarCantidadProductos(char nombreArchivo[]);

#endif // ARCHIVOPRODUCTO_H_INCLUDED
