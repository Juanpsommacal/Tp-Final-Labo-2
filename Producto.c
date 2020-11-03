#include "Producto.h"
#include <stdlib.h>
#include <stdio.h>

//Muestra un producto
void mostrarProducto(stProducto producto)
{
    printf("\nNumero de ID: %i", producto.idProducto);
    printf("\nNombre: %s", producto.nombre);
    printf("\nMarca: %s", producto.marca);
    printf("\nPrecio: $%.2f", producto.precio);
}
