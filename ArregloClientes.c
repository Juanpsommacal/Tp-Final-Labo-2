#include "ArregloClientes.h"

//Busca un cliente en el Arreglo y retorna su posicion
int buscarCliente(stCelda celda[],int idCliente[],int validos)
{
    int posicion = -1;
    int i = 0;
    while((i<validos)&&(posicion == -1))
    {
        if(celda[i].cliente.idCliente == idCliente)
        {
            posicion = i;
        }
        i++;
    }
    return posicion;
}

//Agrega un cliente al arreglo, retorna los validos
int agregarCliente(stCelda celda[],stCliente cliente,int validos)
{
    celda[validos].listaDeProductos = NULL;
    celda[validos].cliente = cliente;

    validos++;

    return validos;
}

//LLama a agregarCliente y le agrega la lista de productos
int alta (stCelda celda[],int validos,stCliente cliente,stProducto producto)
{
    nodoListaProducto * nuevoNodo = crearNodoLista(producto);
    int posicion = buscarCliente(celda,cliente.idCliente,validos);
    if(posicion == -1)
    {
        validos = agregarCliente(celda,cliente,validos);
        posicion = validos -1;

    }

    stCelda unaCelda = celda[posicion];

    nodoListaProducto * unaListaDeProducto = unaCelda.listaDeProductos;

    unaListaDeProducto = agregarAlPrincipio(unaListaDeProducto,nuevoNodo);

    unaCelda.listaDeProductos = unaListaDeProducto;

    celda[posicion] = unaCelda;

    return validos;
}

//Muestra el arreglo
void mostrarArreglo (stCelda celda [],int validos)
{
    int i = 0;
    for(i = 0; i<validos;i++)
    {
        printf(" Id Cliente : %d \n",celda[i].cliente.idCliente);
        printf(" Nombre Cliente : %s \n",celda[i].cliente.nombre);
        printf(" Apellido Cliente : %s \n",celda[i].cliente.apellido);
        printf(" UserName Cliente : %s \n",celda[i].cliente.userName);
        printf(">>>Lista de productos<<< \n");
        mostrarLista(celda[i].listaDeProductos);
        printf("-----------------------------\n");

    }
}

//Borra las listas de producto del arreglo
void limpiarArregloListas (stCelda celda[20],int validos)
{
    int i = 0;
    while (i<validos)
    {
        celda[i].listaDeProductos = borrarNodo(celda[i].listaDeProductos);
        i++;
    }
}

//Prueba
int ingresarDatos (stCelda celda[20],int dimension)
{
    stCliente cliente;
    stProducto producto;
    char seguir = 's';
    int validos = 0;
    while ((seguir == 's') && validos < dimension)
    {
        cliente.idCliente = 1;
        strcpy(cliente.nombre,"pepe");
        strcpy(cliente.apellido,"gomez");
        strcpy(cliente.userName,"pepito");
        strcpy(cliente.password,"123");
        strcpy(cliente.mail,"dasasddsa");
        strcpy(cliente.domicilio,"dasadsdas");
        cliente.rol = 0;
        cliente.genero = 'm';
        cliente.eliminado = 0;
        producto.idProducto = 10;
        strcpy(producto.nombre,"caca");
        strcpy(producto.marca,"nike");
        producto.precio = 200;

        producto.eliminado = 0;

        validos = alta(celda,validos,cliente,producto);

        printf("Ingrese s para continuar cargando\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    return validos;
}


