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
int alta(stCelda celda[], int validos, stCliente cliente, nodoListaProducto* listaProductos)
{
    //Primero buscamos la posicion del cliente en el arreglo
    int posicion = buscarCliente(celda, cliente.idCliente, validos);
    if(posicion == -1)
    {
        validos = agregarCliente(celda,cliente,validos);
        posicion = validos -1;
    }
    //Agregamos la lista de productos
    celda[posicion].listaDeProductos = listaProductos;
    if(listaProductos != NULL)
    {
        celda[posicion].costoTotalDelPedido = contarTotalPedido(listaProductos);
    }
    else
    {
        celda[posicion].costoTotalDelPedido = 0;
    }

    return validos;
}

//Muestra el arreglo
void mostrarArreglo (stCelda celda [],int validos)
{
    int i = 0;
    for(i = 0; i<validos; i++)
    {
        printf("\tId Cliente : %d \n\n",celda[i].cliente.idCliente);
        printf("Nombre Cliente : %s \n",celda[i].cliente.nombre);
        printf("Apellido Cliente : %s \n",celda[i].cliente.apellido);
        printf("UserName Cliente : %s \n\n",celda[i].cliente.userName);
        printf("\t>>>Lista de productos<<< \n");
        printf("\nCosto total del pedido: %.2f\n", celda[i].costoTotalDelPedido);
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


