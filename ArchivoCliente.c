#include "ArchivoCliente.h"
#include <stdlib.h>
#include <stdio.h>

//Retorna la cantidad de clientes que hay en el archivo
int contarCantidadClientes(char nombreArchivo[])
{
    FILE* archivo;
    int contador = 0;
    stCliente cliente;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            //Contamos cada cliente que haya en el archivo
            contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadClientes)", nombreArchivo);

    return contador;
}

// Devuelve 1 si la id ya pertenece a otro cliente
int VerificarIdCliente(char nombreArchivo[], int id)
{
    FILE* archivo;
    int existe = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                //Si la ID ya pertenece a otro cliente, notificamos a quien y cambiamos el valor de "existe"
                printf("\nEsta ID ya pertenece a %s %s", cliente.apellido, cliente.nombre);
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return existe;
}
