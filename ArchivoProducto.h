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
int ingresarProductoAlArchivo(char nombreArchivo[], stProducto producto);

//Retorna la cantidad de productos que hay en el archivo, que cumplan con el estado recibido por parametro
int contarCantidadProductosPorEstado(char nombreArchivo[], int estado);

//Muestra todos los productos con el mismo estado que se pase por parametro. resumido = 1 muestra resumido, si es 0 muestra toda la descripcion
void mostrarProductoPorEstado(char nombreArchivo[], int estado, int resumido);

//Retorna el estado del producto
int verificarEstadoProducto(char nombreArchivo[], int id);

//Modifica un atributo recibido por parametro de un producto
int ModificarProducto(char nombreArchivo[], int id, int eleccion);

//Busca un producto por su ID y lo retorna
stProducto retornarProductoPorId(char nombreArchivo[], int id);
#endif // ARCHIVOPRODUCTO_H_INCLUDED
