#include "Cliente.h"
char archivoCliente[20] = "Clientes.bin";
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
    printf("\n------------------------------------------");
}

//Muestra solo el username y la id de un cliente
void mostrarClienteResumido(stCliente cliente)
{
    printf("\n%s: %i", cliente.userName, cliente.idCliente);
}

//Agrega un nuevo cliente al sistema
stCliente CargarCliente()
{
    stCliente cliente;

    //La id de cada cliente se genera automaticamente
    cliente.idCliente = contarCantidadClientes(archivoCliente) + 1;

    system("cls");
    printf("\nIngrese su nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    system("cls");

    printf("\nIngrese su apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

    system("cls");

    do
    {
        printf("\nIngrese su genero, F (femenino), M (masculino), O (otro): ");
        fflush(stdin);
        scanf("%c", &cliente.genero);
    }while((cliente.genero != 'f') && (cliente.genero != 'o') && (cliente.genero != 'm'));

    system("cls");

    printf("\nIngrese su domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

    system("cls");

    printf("\nIngrese un nombre de usuario (lo utilizara para logearse al sistema): ");
    fflush(stdin);
    gets(cliente.userName);

    system("cls");

    printf("\nIngrese una direccion de eMail valida: ");
    fflush(stdin);
    gets(cliente.mail);

    system("cls");

    printf("\nIngrese una contraseña: ");
    fflush(stdin);
    gets(cliente.password);

    system("cls");

    cliente.rol = 0;
    cliente.eliminado = 0;

    return cliente;
}




