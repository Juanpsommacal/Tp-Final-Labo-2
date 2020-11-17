#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int idProducto;
    char nombre[30];
    char marca[20];
    float precio;
    int eliminado; // 0: Activo; 1: Eliminado
}stProducto;

//Muestra un producto
void mostrarProducto(stProducto producto);

//Agrega un nuevo producto al sistema
stProducto cargarProducto();

//Muestra la marca, nombre y la id de un producto
void mostrarProductoResumido(stProducto producto);

#endif // PRODUCTO_H_INCLUDED
