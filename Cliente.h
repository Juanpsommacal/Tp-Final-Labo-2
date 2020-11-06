#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Listas.h"
#include "Arboles.h"

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char domicilio[30];
    char genero;
    int rol; // 0: Cliente; 1: Admin
    int eliminado; // 0: Activo; 1: Eliminado
}stCliente;



#endif // CLIENTE_H_INCLUDED
