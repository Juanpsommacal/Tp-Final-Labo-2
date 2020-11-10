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

//Cambia el estado de un producto, devuelve 1 si se logro con exito
int cambiarEstadoProducto(char nombreArchivo[], int id)
{
    FILE* archivo;
    int flag = 0;
    stProducto producto;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0 && flag == 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
                //Si eliminado vale 1, lo cambia a 0
                if(producto.eliminado == 1)
                {
                    producto.eliminado = 0;
                    fseek(nombreArchivo, -sizeof(stProducto), SEEK_CUR);
                    fwrite(&producto, sizeof(stProducto), 1, nombreArchivo);
                }
                else
                    //Si eliminado vale 0, lo cambia a 1
                    producto.eliminado = 1;
                    fseek(nombreArchivo, -sizeof(stProducto), SEEK_CUR);
                    fwrite(&producto, sizeof(stProducto), 1, nombreArchivo);
            }
        }
    }
    else
        printf("\nError al abrir el archivo %s (cambiarEstadoProducto)", nombreArchivo);
    return flag;
}

//Busca un producto por su ID y lo muestra por pantalla
int mostrarProductoPorId(char nombreArchivo[], int id)
{
    FILE* archivo;
    stProducto producto;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
                mostrarProducto(producto);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarProductoPorId)", nombreArchivo);
    }
    return flag;
}


