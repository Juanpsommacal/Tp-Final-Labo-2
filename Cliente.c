#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
const char archivoCliente[20] = "clientes.bin";


//Muestra un cliente
void mostrarCliente(stCliente cliente)
{
    printf("\nNumero de ID: %i", cliente.idCliente);
    printf("\nNombre: %s", cliente.nombre);
    printf("\nApellido: %s", cliente.apellido);
    printf("\nGenero: %c", cliente.genero);
    printf("\nUsername: %s", cliente.userName);
    printf("\neMail: %s", cliente.mail);
    printf("\nDomicilio: %s", cliente.domicilio);
}

//Agrega un nuevo cliente al sistema
stCliente CargarCliente()
{
    stCliente cliente;

    //La id de cada cliente se genera automaticamente
    cliente.idCliente = contarCantidadClientes(archivoCliente) + 1;

    printf("\nIngrese su nombre: ");
    fflush(stdin);
    scanf("%s", cliente.nombre);

    system("cls");

    printf("\nIngrese su apellido: ");
    fflush(stdin);
    scanf("%s", cliente.apellido);

    system("cls");

    do
    {
        printf("\nIngrese su genero, F (femenino), M (masculino), O (otro): ");
        fflush(stdin);
        scanf("%c", cliente.genero);
    }while( (cliente.genero != 'M') && (cliente.genero != 'm') && (cliente.genero != 'F') && (cliente.genero != 'f') && (cliente.genero != 'O') && (cliente.genero != 'o') );

    system("cls");

    printf("\nIngrese su domicilio: ");
    fflush(stdin);
    scanf("%s", cliente.domicilio);

    system("cls");

    printf("\nIngrese un nombre de usuario (lo utilizara para logearse al sistema): ");
    fflush(stdin);
    scanf("%s", cliente.userName);

    system("cls");

    printf("\nIngrese una direccion de eMail valida: ");
    fflush(stdin);
    scanf("%s", cliente.mail);

    system("cls");

    printf("\nIngrese una contraseña: ");
    fflush(stdin);
    scanf("%s", cliente.password);

    system("cls");

    cliente.rol = 0;
    cliente.eliminado = 0;

    return cliente;
}




