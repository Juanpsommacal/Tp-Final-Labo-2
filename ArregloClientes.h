#ifndef ARREGLOCLIENTES_H_INCLUDED
#define ARREGLOCLIENTES_H_INCLUDED
#include "Cliente.h"

typedef struct
{
    stCliente cliente;
    nodoListaProducto* listaDeProductos;
    float costoTotalDelPedido;
}stCelda;

//Agrega un cliente al arreglo de Listas
int agregarCliente(stCelda arregloClientes[], stCliente cliente, int validos);


#endif // ARREGLOCLIENTES_H_INCLUDED
