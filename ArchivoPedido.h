#ifndef ARCHIVOPEDIDO_H_INCLUDED
#define ARCHIVOPEDIDO_H_INCLUDED
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
typedef struct
{
    int idPedido;
    int idCliente;
    int idProducto;
}stPedido;

//Retorna la cantidad de pedidos unicos que hay en el archivo
int contarCantidadPedidos(char nombreArchivo[]);

// Devuelve la id del pedido o retorna 0 si no hay pedido con el id de ese cliente
int VerificarIdPedidoPorCliente(char nombreArchivo[], int id);

//Recibe un pedido y lo guarda en el archivo
void ingresarPedidoAlArchivo(char nombreArchivo[], stPedido pedidoNuevo);

//Retorna el pedido en una lista buscandolo por la ID
nodoListaProducto* buscarPedidoPorClienteLista(char nombreArchivo[], int idPedido);

#endif // ARCHIVOPEDIDO_H_INCLUDED
