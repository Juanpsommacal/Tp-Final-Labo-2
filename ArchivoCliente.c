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

//Cambia el estado de un cliente, devuelve 1 si se logro con exito
int cambiarEstadoCliente(char nombreArchivo[], int id)
{
    FILE* archivo;
    int flag = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0 && flag == 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;
                //Si eliminado vale 1, lo cambia a 0
                if(cliente.eliminado == 1)
                {
                    cliente.eliminado = 0;
                    fseek(nombreArchivo, -sizeof(stCliente), SEEK_CUR);
                    fwrite(&cliente, sizeof(stCliente), 1, nombreArchivo);
                }
                else
                    //Si eliminado vale 0, lo cambia a 1
                    cliente.eliminado = 1;
                    fseek(nombreArchivo, -sizeof(stCliente), SEEK_CUR);
                    fwrite(&cliente, sizeof(stCliente), 1, nombreArchivo);
            }
        }
    }
    else
        printf("\nError al abrir el archivo %s (cambiarEstadoCliente)", nombreArchivo);
    return flag;
}

//Busca un cliente por su ID y lo muestra por pantalla
int MostrarClientePorId(char nombreArchivo[], int id)
{
    FILE* archivo;
    stCliente cliente;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;
                mostrarCliente(cliente);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarClientePorId)", nombreArchivo);
    }
    return flag;
}

//Modifica un atributo de un cliente, segun la eleccion del usuario
/*void ModificarCliente(char nombreArchivo[],int id, int eleccion)
{
    stCliente clien;
    char term;
    FILE* archivoCliente = fopen(NombrearchivoClientes, "r+b");
    if(archivoCliente != NULL)
    {
        while(fread(&clien, sizeof(stCliente), 1, archivoCliente) > 0)
        {
            if(clien.idCliente == idCliente)
            {
                if(eleccion == 1)
                {
                    printf("\nIngrese el nuevo nombre del cliente o admin: ");
                    scanf("%s", clien.nombre);
                }
                else if(eleccion == 2)
                {
                    printf("\nIngrese el nuevo apellido del cliente o admin: ");
                    scanf("%s", clien.apellido);
                }
                else if(eleccion == 3)
                {
                    printf("\nIngrese el nuevo domicilio del cliente o admin: ");
                    scanf("%s", clien.domicilio);
                }
                else if(eleccion == 4)
                {
                    printf("\nIngrese el nuevo genero del cliente o admin: ");
                    scanf("%s",clien.genero);
                }
                else if(eleccion == 5)
                {
                    printf("\nIngrese el nuevo mail del cliente o admin: ");
                    scanf("%s", clien.mail);
                }
                else if(eleccion == 6)
                {
                    printf("\nIngrese el nuevo username del cliente o admin: ");
                    scanf("%s", clien.userName);
                }
                else if(eleccion == 7)
                {
                    printf("\nIngrese la nueva password del cliente o admin: ");
                    scanf("%s", clien.password);
                }else if(eleccion == 8)
                {
                    if(clien.rol == 1)
                    {
                        clien.rol = 0;
                    }else if (clien.rol == 0)
                    {
                        clien.rol = 1;
                    }

                }
                fseek(archivoCliente, -sizeof(stCliente), SEEK_CUR);
                fwrite(&clien, sizeof(stCliente), 1, archivoCliente);
                break;
            }
        }
        fclose(archivoCliente);
    }else
        printf("\nError al abrir el archivo %s (ModificarCliente)", NombrearchivoClientes);


}*/

