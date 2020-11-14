#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char domicilio[30];
    char genero; //F femenino, M masculino, O otro
    int rol; // 0: Cliente; 1: Admin
    int eliminado; // 0: Activo; 1: Eliminado
}stCliente;

//Muestra un cliente
void mostrarCliente(stCliente cliente);

//Muestra solo el username y la id de un cliente
void mostrarClienteResumido(stCliente cliente);

//Agrega un nuevo cliente al sistema
stCliente CargarCliente();

#endif // CLIENTE_H_INCLUDED
