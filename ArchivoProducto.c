#include "ArchivoProducto.h"
#include <stdlib.h>
#include <stdio.h>

// Devuelve 1 si la id ya pertenece a otro producto
int VerificarIdProducto(char nombreArchivo[], int id)
{
    FILE* archivo;
    int existe = 0;
    stProducto producto;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                //Si la ID ya pertenece a otro producto, notificamos a cual y cambiamos el valor de "existe"
                printf("\nEsta ID ya pertenece a %s %s", producto.marca, producto.nombre);
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdProducto)", nombreArchivo);

    return existe;
}

//Retorna la cantidad de productos que hay en el archivo
int contarCantidadProductos(char nombreArchivo[])
{
    FILE* archivo;
    int contador = 0;
    stProducto producto;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            //Contamos cada producto que haya en el archivo
            contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadProductos)", nombreArchivo);

    return contador;
}
