#ifndef ARREGLOCLIENTES_H_INCLUDED
#define ARREGLOCLIENTES_H_INCLUDED
#include <stdio.h>
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"

typedef struct
{
    stCliente cliente;
    nodoListaProducto* listaDeProductos;
    float costoTotalDelPedido;
}stCelda;

//Busca un cliente en el Arreglo y retorna su posicion
int buscarCliente(stCelda celda[],int idCliente[],int validos);

//Agrega un cliente al arreglo, retorna los validos
int agregarCliente(stCelda celda[],stCliente cliente,int validos);

//LLama a agregarCliente y le agrega la lista de productos
int alta (stCelda celda[],int validos,stCliente cliente,stProducto producto);

//Muestra el arreglo
void mostrarArreglo (stCelda celda [20],int validos);

//Borra las listas de producto del arreglo
void limpiarArregloListas (stCelda celda[20],int validos);

//Prueba
int ingresarDatos (stCelda celda[],int dimension);


#endif // ARREGLOCLIENTES_H_INCLUDED
