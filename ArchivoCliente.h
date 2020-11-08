#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "Cliente.h"

//Retorna la cantidad de clientes que hay en el archivo
int contarCantidadClientes(char nombreArchivo[]);

// Devuelve 1 si la id ya pertenece a otro cliente
int VerificarIdCliente(char nombreArchivo[], int id);


#endif // ARCHIVOCLIENTE_H_INCLUDED
