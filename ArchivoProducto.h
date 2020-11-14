#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "Arboles.h"

// Devuelve 1 si la id ya pertenece a otro producto
int VerificarIdProducto(char nombreArchivo[], int id);

//Retorna la cantidad de productos que hay en el archivo
int contarCantidadProductos(char nombreArchivo[]);

//Cambia el estado de un producto, devuelve 1 si se logro con exito
int cambiarEstadoProducto(char nombreArchivo[], int id);

//Busca un producto por su ID y lo muestra por pantalla
int mostrarProductoPorId(char nombreArchivo[], int id);

//Recibe un producto y lo guarda en el archivo
void ingresarProductoAlArchivo(char nombreArchivo[], stProducto producto);

#endif // ARCHIVOPRODUCTO_H_INCLUDED
