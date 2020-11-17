#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "Cliente.h"

//Retorna la cantidad de clientes que hay en el archivo
int contarCantidadClientes(char nombreArchivo[]);

// Devuelve 1 si la id ya pertenece a otro cliente
int VerificarIdCliente(char nombreArchivo[], int id);

//Cambia el estado de un cliente, devuelve 1 si se logro con exito
int cambiarEstadoCliente(char nombreArchivo[], int id);

//Busca un cliente por su ID y lo muestra por pantalla
int MostrarClientePorId(char nombreArchivo[], int id);

//Recibe un cliente y lo guarda en el archivo
int ingresarClienteAlArchivo(char nombreArchivo[], stCliente cliente);

//Verifica si el username ya existe, devuelve 1 si existe
int verificarUserName(char nombreArchivo[], char username[]);

//Verifica si el username y el password coinciden
int verificarPassword(char nombreArchivo[], char username[], char password[]);

//Retorna el rol del usuario
int verificarRol(char nombreArchivo[], char username[]);

//Recibe un estado y muestra todos los clientes con ese estado. resumido = 1 muestra resumido, si es 0 muestra toda la descripcion
void MostrarClientePorEstado(char nombreArchivo[], int estado, int resumido);

//Retorna el estado del usuario
int verificarEstado(char nombreArchivo[], int id);

//Modifica un atributo de un cliente, segun la eleccion del usuario
int ModificarCliente(char nombreArchivo[],int id, int eleccion);

//Retorna la cantidad de clientes que hay en el archivo por estado
int contarCantidadClientesPorEstado(char nombreArchivo[], int estado);

//Muestra un cliente, buscandolo por su username
void mostrarClientePorUsername(char nombreArchivo[], char username[]);

//Retorna la id de un cliente, buscandolo por su username
int retornarIDClientePorUsername(char nombreArchivo[], char username[]);

//Retorna la struct cliente buscandolo por ID
stCliente retornarStClientePorId(char nombreArchivo[], int id);

#endif // ARCHIVOCLIENTE_H_INCLUDED
