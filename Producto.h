#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

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

#endif // PRODUCTO_H_INCLUDED
