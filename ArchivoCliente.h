#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "Cliente.h"

//Retorna la cantidad de clientes que hay en el archivo
int contarCantidadClientes(char nombreArchivo[]);

// Devuelve 1 si la id ya pertenece a otro cliente
int VerificarIdCliente(char nombreArchivo[], int id);

//Cambia el estado de un cliente, devuelve 1 si se logro con exito
int cambiarEstadoCliente(char nombreArchivo[], int id);

//Busca un cliente por su ID y lo muestra por pantalla
int MostrarClientePorId(char nombreArchivo[], int id);


#endif // ARCHIVOCLIENTE_H_INCLUDED
