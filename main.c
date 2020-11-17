#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArregloClientes.h"
#include "time.h"



int main()
{
    //Todas las variables que vamos a utilizar
    char archivoCliente[20] = "Clientes.bin";
    char archivoProducto[20] = "Productos.bin";
    char archivoPedido[20] = "Pedidos.bin";
    int menu = 0, validacion = 1, validos = 0, contador = 1, idAleatoria, cantidadProductos, rolUsuario, idModificacion, eleccion, menuAdmin, menuCliente, validacionPedido, cantidadClientes;
    char term = '\n', acepto;
    stPedido pedidoMenu;
    stCliente clienteMenu;
    stCliente clienteADL;
    stCliente clienteModificacion;
    stProducto productoMenu;
    nodoListaProducto* listaProductos = inicializarLista();
    nodoListaProducto* nuevoProducto = inicializarLista();
    nodoArbolstProducto* arbolProductos;
    nodoArbolstProducto* aux;

    ///Para comenzar con el programa
    //Contamos la cantidad de clientes que hay en el archivo
    cantidadClientes = contarCantidadClientes(archivoCliente);
    //Reservamos el espacio en la memoria para el arreglo de listas
    stCelda* ArregloDL = (stCelda*)malloc(cantidadClientes * sizeof(stCelda));
    do
    {
        do
        {
            do
            {
                ///Menu principal, para logearse o crear una nueva cuenta
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
        case 1:///Iniciar sesion
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

                ///Cargamos el ADL
                while(contador <= cantidadClientes)
                {
                    //Buscamos la struct de cliente en el archivo
                    clienteADL = retornarStClientePorId(archivoCliente, contador);
                    //Buscamos si el cliente tiene un pedido en el archivo o no
                    validacionPedido = VerificarIdPedidoPorCliente(archivoPedido, contador);
                    if(validacionPedido != 0)
                    {
                        //Sacamos la lista de pedidos del archivo
                        listaProductos = buscarPedidoPorClienteLista(archivoPedido, validacionPedido);
                    }
                    //Cargamos todo en el arreglo
                    validos = alta(ArregloDL, validos, clienteADL, listaProductos);
                    //Aumentamos el contador
                    contador ++;
                    //Repetimos todo hasta que no haya mas clientes por cargar
                }
                //Dividimos el menu en 2 partes. Si rol es 1, va al menu de admin, sino al de cliente
                rolUsuario = verificarRol(archivoCliente, clienteMenu.userName);
                if(rolUsuario == 1)
                {
                    do
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
                                printf("\n3: Ver clientes y pedidos");
                                printf("\n\t");
                                fflush(stdin);
                            }while(scanf("%d%c", &menu, &term) != 2 || term != '\n');
                        }while(menu < 0 || menu > 3);
                        switch(menu)
                        {
                        case 1:///Administracion de clientes
                            {
                            do
                            {
                                do
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nIngrese la opcion del menu al que desea ingresar o ingrese 0 volver al menu anterior: ");
                                        printf("\n1: Dar de alta un cliente");
                                        printf("\n2: Dar de baja un cliente");
                                        printf("\n3: Modificar un cliente existente");
                                        printf("\n4: Mostrar clientes");
                                        printf("\n5: Buscar un cliente por ID");
                                        printf("\n6: Convertir un usuario en administrador");
                                        printf("\n\t");
                                        fflush(stdin);
                                    }while(scanf("%d%c", &menuAdmin, &term) != 2 || term != '\n');
                                }while(menuAdmin < 0 || menuAdmin > 6);
                                switch(menuAdmin)
                                {
                                case 1:///Dar de alta un cliente
                                    {
                                        if(contarCantidadClientesPorEstado(archivoCliente, 1) > 0)
                                        {
                                            do
                                            {
                                                do
                                                {
                                                system("cls");
                                                MostrarClientePorEstado(archivoCliente, 1, 1);
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
                                        }
                                        else
                                            printf("\nNo hay ningun usuario para dar de alta.");
                                        printf("\n");
                                        system("pause");
                                        break;
                                    }
                                case 2:///Dar de baja un cliente
                                    {
                                        do
                                        {
                                            do
                                            {
                                            system("cls");
                                            MostrarClientePorEstado(archivoCliente, 0, 1);
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
                                        printf("\n");
                                        system("pause");
                                        break;
                                    }
                                case 3:///Modificar un cliente existente
                                    {
                                        do
                                        {
                                            do
                                            {
                                                system("cls");
                                                MostrarClientePorEstado(archivoCliente, 0, 1);
                                                printf("\nIngrese la ID del cliente que quiere modificar: ");
                                                printf("\n\t");
                                                fflush(stdin);
                                            }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                        }while(verificarEstado(archivoCliente, idModificacion) != 0);
                                        do
                                        {
                                            do
                                            {
                                                system("cls");
                                                printf("\n\tUsuario a modificar: ");
                                                printf("\n");
                                                MostrarClientePorId(archivoCliente, idModificacion);
                                                printf("\nIngrese el numero del atributo que desea modificar: ");
                                                printf("\n1: Nombre ");
                                                printf("\n2: Apellido");
                                                printf("\n3: Domicilio");
                                                printf("\n4: Genero");
                                                printf("\n5: Mail");
                                                printf("\n6: Username");
                                                printf("\n7: Password");
                                            }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                        }while(eleccion < 1 || eleccion > 7);
                                        validacion = ModificarCliente(archivoCliente, idModificacion, eleccion);
                                        if(validacion == 1)
                                            printf("\nEl estado del usuario se cambio con exito!!");
                                        else
                                            printf("\nEl estado del usuario no se pudo cambiar");
                                        printf("\n");
                                        system("pause");
                                        break;
                                    }
                                case 4:///Mostrar clientes
                                    {
                                        do
                                        {
                                            do
                                            {
                                                system("cls");
                                                printf("\nIngrese el modo de ver los clientes o presione 0 para volver al menu anterior: ");
                                                printf("\n1: Ver clientes activos");
                                                printf("\n2: Ver clientes eliminados");
                                                printf("\n3: Ver todos los clientes");
                                                printf("\n\t");
                                                fflush(stdin);
                                            }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                        }while(eleccion < 0 || eleccion > 3);
                                        switch(eleccion)
                                        {
                                        case 1://Ver clientes activos
                                            {
                                                do
                                                {
                                                    do
                                                    {
                                                        system("cls");
                                                        printf("\nElija el modo de ver los clientes activos: ");
                                                        printf("\n1: Vista completa");
                                                        printf("\n2: Vista resumida");
                                                        printf("\n\t");
                                                    }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                }while(eleccion < 1 || eleccion > 2);
                                                if(eleccion == 1)
                                                    MostrarClientePorEstado(archivoCliente, 0, 0);
                                                else if(eleccion == 2)
                                                    MostrarClientePorEstado(archivoCliente, 0, 1);
                                                printf("\n");
                                                system("Pause");
                                                break;
                                            }
                                        case 2://Ver clientes eliminados
                                            {
                                                do
                                                {
                                                    do
                                                    {
                                                        system("cls");
                                                        printf("\nElija el modo de ver los clientes eliminados: ");
                                                        printf("\n1: Vista completa");
                                                        printf("\n2: Vista resumida");
                                                        printf("\n\t");
                                                    }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                }while(eleccion < 1 || eleccion > 2);
                                                if(eleccion == 1)
                                                    MostrarClientePorEstado(archivoCliente, 1, 0);
                                                else if(eleccion == 2)
                                                    MostrarClientePorEstado(archivoCliente, 1, 1);
                                                printf("\n");
                                                system("Pause");
                                                break;
                                            }
                                        case 3://Ver todos los clientes
                                            {
                                                do
                                                {
                                                    do
                                                    {
                                                        system("cls");
                                                        printf("\nElija el modo de ver todos los clientes: ");
                                                        printf("\n1: Vista completa");
                                                        printf("\n2: Vista resumida");
                                                        printf("\n\t");
                                                    }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                }while(eleccion < 1 || eleccion > 2);
                                                if(eleccion == 1)
                                                {
                                                    MostrarClientePorEstado(archivoCliente, 1, 0);
                                                    MostrarClientePorEstado(archivoCliente, 0, 0);
                                                }
                                                else if(eleccion == 2)
                                                {
                                                    MostrarClientePorEstado(archivoCliente, 1, 1);
                                                    MostrarClientePorEstado(archivoCliente, 0, 1);
                                                }
                                                printf("\n");
                                                system("Pause");
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                case 5:///Buscar cliente por ID
                                    {
                                        do
                                        {
                                            do
                                            {
                                                system("cls");
                                                printf("\nIngrese la ID del cliente que quiere mostrar o ingrese 0 para volver atras");
                                                MostrarClientePorEstado(archivoCliente, 0, 1);
                                                MostrarClientePorEstado(archivoCliente, 1, 1);
                                                printf("\n\t");
                                                fflush(stdin);
                                            }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                        }while(VerificarIdCliente(archivoCliente, idModificacion) == 0);
                                        system("cls");
                                        MostrarClientePorId(archivoCliente, idModificacion);
                                        printf("\n");
                                        system("pause");
                                        break;
                                    }
                                case 6:///Convertir un usuario en administrador
                                    {
                                        do
                                        {
                                            do
                                            {
                                                system("cls");
                                                MostrarClientePorEstado(archivoCliente, 0, 1);
                                                printf("\nIngrese la ID del cliente que quiere convertir en administrador: ");
                                                printf("\n\t");
                                                fflush(stdin);
                                            }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                        }while(verificarEstado(archivoCliente, idModificacion) != 0);

                                        system("cls");
                                        printf("\n\tUsuario a modificar: ");
                                        printf("\n");
                                        MostrarClientePorId(archivoCliente, idModificacion);
                                        printf("\n");
                                        printf("\n\t ESTA SEGURO QUE DESEA REALIZAR ESTA ACCION? UNA VEZ REALIZADO, NO SE PUEDE DESHACER s/n");
                                        fflush(stdin);
                                        scanf("%c", &acepto);
                                        if(acepto == 's')
                                        {
                                            validacion = ModificarCliente(archivoCliente, idModificacion, 8);
                                            if(validacion == 1)
                                                printf("\nEl estado del usuario se cambio con exito!!");
                                            else
                                                printf("\nEl estado del usuario no se pudo cambiar");
                                        }
                                        else
                                            printf("\nAccion abortada");
                                        printf("\n");
                                        system("pause");
                                        break;
                                    }
                                }//Switch administrador clientes
                            }while(menuAdmin != 0);//Termina el menu de administracion de clientes del ADMIN
                            break;
                            }
                        case 2:///Administracion de productos
                            {
                                do
                                {
                                    do
                                    {
                                        do
                                        {
                                            system("cls");
                                            printf("\nIngrese la opcion del menu al que desea ingresar o ingrese 0 volver al menu anterior: ");
                                            printf("\n1: Crear un nuevo producto");
                                            printf("\n2: Dar de alta un producto");
                                            printf("\n3: Dar de baja un producto");
                                            printf("\n4: Modificar un producto existente");
                                            printf("\n5: Mostrar productos");
                                            printf("\n6: Buscar un producto por ID");
                                            printf("\n\t");
                                            fflush(stdin);
                                        }while(scanf("%d%c", &menuAdmin, &term) != 2 || term != '\n');
                                    }while(menuAdmin < 0 || menuAdmin > 6);
                                    switch(menuAdmin)
                                    {
                                    case 1:///Crear un nuevo producto
                                        {
                                            productoMenu = cargarProducto();
                                            validacion = ingresarProductoAlArchivo(archivoProducto, productoMenu);
                                            if(validacion == 1)
                                                printf("\nEl producto se creo con exito");
                                            else
                                                printf("\nEl producto no se pudo crear");
                                            printf("\n");
                                            system("pause");
                                            break;
                                        }
                                    case 2:///Dar de alta un producto
                                        {
                                            if(contarCantidadProductosPorEstado(archivoProducto, 1) > 0)
                                            {
                                                do
                                                {
                                                    do
                                                    {
                                                    system("cls");
                                                    mostrarProductoPorEstado(archivoProducto, 1, 1);
                                                    printf("\nIngrese la ID del producto que quiere dar de alta: ");
                                                    printf("\n\t");
                                                    fflush(stdin);
                                                    }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                                }while(verificarEstadoProducto(archivoProducto, idModificacion) != 1);
                                                validacion = cambiarEstadoProducto(archivoProducto, idModificacion);
                                                if(validacion == 1)
                                                    printf("\nEl estado del producto se cambio con exito!!");
                                                else
                                                    printf("\nEl estado del producto no se pudo cambiar");
                                            }
                                            else
                                                printf("\nNo hay ningun producto para dar de alta.");
                                            printf("\n");
                                            system("pause");
                                            break;
                                        }
                                    case 3:///Dar de baja un producto
                                        {
                                            if(contarCantidadProductosPorEstado(archivoProducto, 0) > 0)
                                            {
                                                do
                                                {
                                                    do
                                                    {
                                                    system("cls");
                                                    mostrarProductoPorEstado(archivoProducto, 0, 1);
                                                    printf("\nIngrese la ID del producto que quiere dar de baja: ");
                                                    printf("\n\t");
                                                    fflush(stdin);
                                                    }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                                }while(verificarEstadoProducto(archivoProducto, idModificacion) != 0);
                                                validacion = cambiarEstadoProducto(archivoProducto, idModificacion);
                                                if(validacion == 1)
                                                    printf("\nEl estado del producto se cambio con exito!!");
                                                else
                                                    printf("\nEl estado del producto no se pudo cambiar");
                                            }
                                            else
                                                printf("\nNo hay ningun producto para dar de baja.");
                                            printf("\n");
                                            system("pause");
                                            break;
                                        }
                                    case 4:///Modificar producto
                                        {
                                            do
                                            {
                                                do
                                                {
                                                    system("cls");
                                                    mostrarProductoPorEstado(archivoProducto, 0, 1);
                                                    printf("\nIngrese la ID del producto que quiere modificar: ");
                                                    printf("\n\t");
                                                    fflush(stdin);
                                                }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                            }while(verificarEstadoProducto(archivoProducto, idModificacion) != 0);
                                            do
                                            {
                                                do
                                                {
                                                    system("cls");
                                                    printf("\n\tProducto a modificar: ");
                                                    printf("\n");
                                                    mostrarProductoPorId(archivoProducto, idModificacion);
                                                    printf("\nIngrese el numero del atributo que desea modificar: ");
                                                    printf("\n1: Marca ");
                                                    printf("\n2: Nombre");
                                                    printf("\n3: Precio");
                                                    printf("\n\t");
                                                }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                            }while(eleccion < 1 || eleccion > 3);
                                            validacion = ModificarProducto(archivoProducto, idModificacion, eleccion);
                                            if(validacion == 1)
                                                printf("\nEl estado del producto se cambio con exito!!");
                                            else if(validacion == 0)
                                                printf("\nEl estado del producto no se pudo cambiar");
                                            printf("\n");
                                            system("pause");
                                            break;
                                        }
                                    case 5:///Ver productos
                                        {
                                            do
                                            {
                                                do
                                                {
                                                    system("cls");
                                                    printf("\nIngrese el modo de ver los productos o presione 0 para volver al menu anterior: ");
                                                    printf("\n1: Ver producos activos");
                                                    printf("\n2: Ver productos eliminados");
                                                    printf("\n3: Ver todos los productos");
                                                    printf("\n\t");
                                                    fflush(stdin);
                                                }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                            }while(eleccion < 0 || eleccion > 3);
                                            switch(eleccion)
                                            {
                                            case 1://Ver productos activos
                                                {
                                                    do
                                                    {
                                                        do
                                                        {
                                                            system("cls");
                                                            printf("\nElija el modo de ver los productos activos: ");
                                                            printf("\n1: Vista completa");
                                                            printf("\n2: Vista resumida");
                                                            printf("\n\t");
                                                        }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                    }while(eleccion < 1 || eleccion > 2);
                                                    if(eleccion == 1)
                                                        mostrarProductoPorEstado(archivoProducto, 0, 0);
                                                    else if(eleccion == 2)
                                                        mostrarProductoPorEstado(archivoProducto, 0, 1);
                                                    printf("\n");
                                                    system("Pause");
                                                    break;
                                                }
                                            case 2:///Ver productos eliminados
                                                {
                                                    do
                                                    {
                                                        do
                                                        {
                                                            system("cls");
                                                            printf("\nElija el modo de ver los productos eliminados: ");
                                                            printf("\n1: Vista completa");
                                                            printf("\n2: Vista resumida");
                                                            printf("\n\t");
                                                        }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                    }while(eleccion < 1 || eleccion > 2);
                                                    if(eleccion == 1)
                                                        mostrarProductoPorEstado(archivoProducto, 1, 0);
                                                    else if(eleccion == 2)
                                                        mostrarProductoPorEstado(archivoProducto, 1, 1);
                                                    printf("\n");
                                                    system("Pause");
                                                    break;
                                                }
                                            case 3:///Ver todos los productos
                                                {
                                                    do
                                                    {
                                                        do
                                                        {
                                                            system("cls");
                                                            printf("\nElija el modo de ver todos los productos: ");
                                                            printf("\n1: Vista completa");
                                                            printf("\n2: Vista resumida");
                                                            printf("\n\t");
                                                        }while(scanf("%d%c", &eleccion, &term) != 2 || term != '\n');
                                                    }while(eleccion < 1 || eleccion > 2);
                                                    if(eleccion == 1)
                                                    {
                                                        mostrarProductoPorEstado(archivoProducto, 1, 0);
                                                        mostrarProductoPorEstado(archivoProducto, 0, 0);
                                                    }
                                                    else if(eleccion == 2)
                                                    {
                                                        mostrarProductoPorEstado(archivoProducto, 1, 1);
                                                        mostrarProductoPorEstado(archivoProducto, 0, 1);
                                                    }
                                                    printf("\n");
                                                    system("Pause");
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    case 6:///Mostrar un producto por ID
                                        {
                                            do
                                            {
                                                do
                                                {
                                                    system("cls");
                                                    printf("\nIngrese la ID del producto que quiere mostrar");
                                                    mostrarProductoPorEstado(archivoProducto, 0, 1);
                                                    mostrarProductoPorEstado(archivoProducto, 1, 1);
                                                    printf("\n\t");
                                                    fflush(stdin);
                                                }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                            }while(VerificarIdProducto(archivoProducto, idModificacion) == 0);
                                            system("cls");
                                            mostrarProductoPorId(archivoProducto, idModificacion);
                                            printf("\n");
                                            system("pause");
                                            break;
                                        }
                                    }
                                }while(menuAdmin != 0);//Termina el menu de administracion de productos del ADMIN
                                break;
                            }
                        case 3:///Ver clientes y pedidos
                            {
                                system("cls");
                                mostrarArreglo(ArregloDL, validos);
                                printf("\n");
                                system("pause");
                                break;
                            }
                        }
                    }while(menu != 0);
                }
                else if(rolUsuario == 0)
                {
                    //Si el usuario que entra es un cliente, se pasan los productos del archivo al arbol
                    arbolProductos = cargarArbolDesdeArchivo(archivoProducto);
                    //Verificamos si el cliente ya tiene un pedido guardado en el archivo
                    idModificacion = retornarIDClientePorUsername(archivoCliente, clienteMenu.userName);
                    pedidoMenu.idCliente = idModificacion;
                    validacionPedido = VerificarIdPedidoPorCliente(archivoPedido, idModificacion);
                    //Guardamos la posicion del arreglo (es 1 menos que la ID)
                    int posicionADL = idModificacion -1;
                    if(validacionPedido != 0)
                    {
                        //Sacamos la lista de pedidos del archivo
                        listaProductos = buscarPedidoPorClienteLista(archivoPedido, validacionPedido);
                        pedidoMenu.idPedido = validacionPedido;
                    }
                    else //Si el cliente no tiene un pedido guardado en el archivo de pedidos
                    {
                        //Le asignamos la ID del pedido a la estructura Pedido
                        pedidoMenu.idPedido = contarCantidadPedidos(archivoPedido) + 1;
                        //Le asignamos la Id de cliente a la estructura Pedido
                        pedidoMenu.idCliente = idModificacion;
                        //Inicializamos la lista de productos
                        listaProductos = inicializarLista();
                    }
                    do
                    {
                        do
                        {
                            do
                            {
                                system("cls");
                                printf("\tBienvenido %s", clienteMenu.userName);
                                printf("\nIngrese la opcion del menu al que desea ingresar o ingrese 0 para salir: ");
                                printf("\n1: Ver mi perfil");
                                printf("\n2: Mostrar mi Pedido");
                                printf("\n3: Agregar productos al carrito");
                                printf("\n4: Mostrar Productos recomendados");
                                printf("\n\t");
                                fflush(stdin);
                            }while(scanf("%d%c", &menu, &term) != 2 || term != '\n');
                        }while(menu < 0 || menu > 4);
                        switch(menu)
                        {
                        case 1:///Ver mi perfil
                            {
                                system("cls");
                                printf("\n\tInformacion de mi perfil: ");
                                mostrarClientePorUsername(archivoCliente, clienteMenu.userName);
                                printf("\n");
                                system("pause");
                                break;
                            }
                        case 2:///Mostrar mi pedido
                            {
                                system("cls");
                                printf("\tCosto total del pedido: %.2f", contarTotalPedido(ArregloDL[posicionADL].listaDeProductos));
                                mostrarLista(ArregloDL[posicionADL].listaDeProductos);
                                printf("\n");
                                system("pause");
                                break;
                            }
                        case 3:///Agregar productos al carrito
                            {
                                do
                                {
                                    do
                                    {
                                        system("cls");
                                        mostrar(arbolProductos, 1);
                                        printf("\nIngrese la ID del producto que desea agregar al carrito: ");
                                        printf("\n\t");
                                    }while(scanf("%d%c", &idModificacion, &term) != 2 || term != '\n');
                                }while(VerificarIdProducto(archivoProducto, idModificacion) != 1);
                                //buscamos el producto en el arbol y lo retornamos
                                aux = buscarNodoArbol(arbolProductos, idModificacion);
                                productoMenu = aux->producto;
                                //Creamos un nodoLista con el producto
                                nuevoProducto = crearNodoLista(productoMenu);
                                //Lo insertamos en la lista
                                ArregloDL[posicionADL].listaDeProductos = agregarAlPrincipio(ArregloDL[posicionADL].listaDeProductos, nuevoProducto);
                                pedidoMenu.idProducto = idModificacion;
                                printf("\nEl producto se agrego al carrito con exito!");
                                //Guardamos el pedido en el archivo
                                ingresarPedidoAlArchivo(archivoPedido, pedidoMenu);
                                printf("\n");
                                system("pause");
                                break;
                            }
                        case 4:///Mostrar productos recomendados
                            {
                                system("cls");
                                do
                                {
                                    do
                                    {
                                        srand(time(NULL));
                                        cantidadProductos = numeroDeProductos(arbolProductos, &cantidadProductos);
                                        idAleatoria = rand() % cantidadProductos+1;
                                        validacion = verificarEstadoProducto(archivoProducto, idAleatoria);
                                    }while(idAleatoria == 0 || validacion == 1);
                                }while(buscarProductoEnLista(ArregloDL[posicionADL].listaDeProductos, idAleatoria) == 1);
                                //buscamos el producto en el arbol y lo retornamos
                                aux = buscarNodoArbol(arbolProductos, idAleatoria);
                                printf("\n");
                                mostrarProducto(aux->producto);
                                printf("\n");
                                printf("\n\tDesea agregar este producto al carrito? s/n ");
                                fflush(stdin);
                                scanf("%c", &acepto);
                                if(acepto == 's' || acepto == 'S')
                                {
                                    productoMenu = aux->producto;
                                    //Creamos un nodoLista con el producto
                                    nuevoProducto = crearNodoLista(productoMenu);
                                    //Lo insertamos en la lista
                                    ArregloDL[posicionADL].listaDeProductos = agregarAlPrincipio(ArregloDL[posicionADL].listaDeProductos, nuevoProducto);
                                    pedidoMenu.idProducto = idAleatoria;
                                    printf("\nEl producto se agrego al carrito con exito!");
                                    //Guardamos el pedido en el archivo
                                    ingresarPedidoAlArchivo(archivoPedido, pedidoMenu);
                                }
                                printf("\n");
                                system("pause");
                                break;
                            }
                        }
                    }while(menu != 0);
                }
                break;
            }//Fin de cuenta ya existente
        case 2:///Crear una cuenta nueva
            {
                clienteMenu = CargarCliente();
                validacion = ingresarClienteAlArchivo(archivoCliente, clienteMenu);
                system("cls");
                if(validacion == 1)
                    printf("\tSu cuenta se creo con exito!");
                else if(validacion == 0)
                    printf("\tSu cuenta no se pudo crear");
                printf("\n");
                system("pause");
                break;
            }
        }
    }while(menu != 0);

    return 0;
}
