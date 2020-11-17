#include "Producto.h"
char archivoProducto[20] = "Productos.bin";


//Muestra un producto
void mostrarProducto(stProducto producto)
{
    printf("\nNumero de ID: %i", producto.idProducto);
    printf("\nMarca: %s", producto.marca);
    printf("\nNombre: %s", producto.nombre);
    printf("\nPrecio: $%.2f", producto.precio);
    printf("\n------------------------------------------");
}

//Agrega un nuevo producto al sistema
stProducto cargarProducto()
{
    stProducto producto;

    //La id de cada producto se genera automaticamente
    producto.idProducto = contarCantidadProductos(archivoProducto) + 1;

    printf("\nIngrese la marca del producto: ");
    fflush(stdin);
    gets(producto.marca);

    printf("\nIngrese el nombre del producto: ");
    fflush(stdin);
    gets(producto.nombre);

    printf("\nIngrese el precio del producto: ");
    scanf("%f", &producto.precio);

    producto.eliminado = 0;

    return producto;
}

//Muestra la marca, nombre y la id de un producto
void mostrarProductoResumido(stProducto producto)
{
    printf("\n%s %s: %i", producto.marca, producto.nombre, producto.idProducto);
}
