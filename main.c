#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArregloClientes.h"
const char archivoPedido[20] = "Pedidos.bin";


int main()
{
    char archivoCliente[20] = "Clientes.bin";
    char archivoProducto[20] = "Productos.bin";
    /*int cantidadClientes;
    //Contamos la cantidad de clientes que hay en el archivo
    cantidadClientes = contarCantidadClientes(nombreArchivo);
    //Reservamos el espacio en la memoria
    stCelda* ADL = (stCelda*)malloc(cantidadClientes * sizeof(stCelda));*/
    int menu = 0, validacion = 1, rolUsuario, idModificacion;
    char term = '\n';
    stCliente clienteMenu;

    /*cliente.idCliente = 2;
    strcpy(cliente.nombre,"Juan");
    strcpy(cliente.apellido,"Sommacal");
    strcpy(cliente.userName,"Juansomma");
    strcpy(cliente.password,"laboratorio2");
    strcpy(cliente.mail,"Juansomma@gmail.com");
    strcpy(cliente.domicilio,"Micasa123");
    cliente.rol = 0;
    cliente.genero = 'm';
    cliente.eliminado = 1;
    ingresarClienteAlArchivo(archivoCliente, cliente);*/

    do
    {
        do
        {
            do
            {
                system("cls");
                printf("\t Bienvenidos a YouTicsYa!!");
                printf("\nIngrese el numero correspondiente al menu que desea ingresar o ingrese 0 para salir: ");
                printf("\n1: Iniciar sesion");
                printf("\n2: Crear una cuenta nueva");
                if(menu != 1 && menu != 2 && menu != 0)
                    printf("\nIngrese una opcion valida.");
                printf("\n\t");
                fflush(stdin);
            //La siguiente linea de codigo no nos permite ingresar caracteres en el scanf.
            }while(scanf("%d%c", &menu, &term) != 2 || term != '\n');
        }while(menu < 0 || menu > 2);
        switch(menu)
        {
        case 1:
            {
                do
                {
                    system("cls");
                    printf("\nIngrese su nombre de usuario: ");
                    if(validacion == 0)
                        printf("\nEse username no existe");
                    printf("\n\t");
                    fflush(stdin);
                    scanf("%s", clienteMenu.userName);
                    validacion = verificarUserName(archivoCliente, clienteMenu.userName);
                }while(validacion == 0);
                do
                {
                    system("cls");
                    printf("\nIngrese su clave: ");
                    if(validacion == 0)
                        printf("\nClave incorrecta");
                    printf("\n\t");
                    fflush(stdin);
                    scanf("%s", clienteMenu.password);
                    validacion = verificarPassword(archivoCliente, clienteMenu.userName, clienteMenu.password);
                }while(validacion == 0);

                //Dividimos el menu en 2 partes. Si rol es 1, va al menu de admin, sino al de cliente
                rolUsuario = verificarRol(archivoCliente, clienteMenu.userName);
                if(rolUsuario == 1)
                {
                    do
                    {
                        do
                        {
                            system("cls");
                            printf("\n\tBienvenido Administrador %s", clienteMenu.userName);
                            printf("\nIngrese la opcion del menu al que desea ingresar o ingrese 0 para salir: ");
                            printf("\n1: Administracion de clientes");
                            printf("\n2: Administracion de productos");
                            printf("\n\t");
                            fflush(stdin);
                        }while(scanf("%d%c", &menu, &term) != 2 || term != '\n');
                    }while(menu < 0 || menu > 2);
                    switch(menu)
                    {
                    case 1:
                        {
                        do
                        {
                            do
                            {
                                do
                                {
                                    system("cls");
                                    printf("\nIngrese la opcion del menu al que desea ingresar o ingrese 0 para salir: ");
                                    printf("\n1: Dar de alta un cliente");
                                    printf("\n2: Dar de baja un cliente");
                                    printf("\n3: Modificar un cliente existente");
                                    printf("\n4: Mostrar clientes");
                                    printf("\n5: Buscar un cliente por ID");
                                    printf("\n\t");
                                    fflush(stdin);
                                }while(scanf("%d%c", &menu, &term) != 2 || term != '\n');
                            }while(menu < 0 || menu > 5);
                            switch(menu)
                            {
                            case 1:
                                {
                                    do
                                    {
                                        do
                                        {
                                        system("cls");
                                        MostrarClientePorEstado(archivoCliente, 1);
                                        printf("\nIngrese la ID del cliente que quiere dar de alta: ");
                                        printf("\n\t");
                                        fflush(stdin);
                                        }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                    }while(verificarEstado(archivoCliente, idModificacion) != 1);
                                    validacion = cambiarEstadoCliente(archivoCliente, idModificacion);
                                    if(validacion == 1)
                                        printf("\nEl estado del usuario se cambio con exito!!");
                                    else
                                        printf("\nEl estado del usuario no se pudo cambiar");
                                    break;
                                }
                            case 2:
                                {
                                    do
                                    {
                                        do
                                        {
                                        system("cls");
                                        MostrarClientePorEstado(archivoCliente, 0);
                                        printf("\nIngrese la ID del cliente que quiere dar de baja: ");
                                        printf("\n\t");
                                        fflush(stdin);
                                        }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                    }while(verificarEstado(archivoCliente, idModificacion) != 0);
                                    validacion = cambiarEstadoCliente(archivoCliente, idModificacion);
                                    if(validacion == 1)
                                        printf("\nEl estado del usuario se cambio con exito!!");
                                    else
                                        printf("\nEl estado del usuario no se pudo cambiar");
                                    break;
                                }

                            }
                        }while(menu != 0);
                            break;//Termina el menu de administracion de clientes del ADMIN
                        }
                    }
                }
                break; //Termina el menu de admin
            }
        }//Fin caso 1
    }while(menu != 1 && menu != 2 && menu != 0);


    return 0;
}
