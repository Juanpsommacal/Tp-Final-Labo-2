#include "ArregloClientes.h"

//Agrega un cliente al arreglo de Listas
int agregarCliente(stCelda arregloClientes[], stCliente cliente, int validos)
{
    arregloClientes[validos].cliente = cliente;
    validos ++;
    return validos;
}
