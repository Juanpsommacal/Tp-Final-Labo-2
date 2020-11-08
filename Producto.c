#include "Producto.h"
#include <stdlib.h>
#include <stdio.h>
const char archivoProducto[20] = "productos.bin";


//Muestra un producto
void mostrarProducto(stProducto producto)
{
    printf("\nNumero de ID: %i", producto.idProducto);
    printf("\nNombre: %s", producto.nombre);
    printf("\nMarca: %s", producto.marca);
    printf("\nPrecio: $%.2f", producto.precio);
}

//Agrega un nuevo producto al sistema
stProducto cargarProducto()
{
    stProducto producto;
    char term;

    //La id de cada producto se genera automaticamente
    producto.idProducto = contarCantidadProductos(archivoProducto) + 1;

    printf("\nIngrese el nombre del producto: ");
    fflush(stdin);
    scanf("%s", &producto.nombre);

    printf("\nIngrese la marca del producto: ");
    fflush(stdin);
    scanf("%s", &producto.marca);

    printf("\nIngrese el precio del producto: ");
    scanf("%f", &producto.precio);

    producto.eliminado = 0;

    return producto;
}
