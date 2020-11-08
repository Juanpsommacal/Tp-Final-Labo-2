#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Cliente.h"



int main()
{

    stProducto aux;
    aux.eliminado = 0;
    aux.idProducto = 123;
    aux.precio = 100;

    stProducto caca;
    caca.eliminado = 0;
    caca.idProducto = 234;
    caca.precio = 200;

    nodoArbolstProducto* raiz = inicializarArbol();
    raiz = insertarNodoArbol(raiz, aux);
    raiz = insertarNodoArbol(raiz, caca);

    mostrar(raiz, 1);
    printf("\n////////////////////////////////////////////////");
    cambiarEstadoNodoArbol(raiz, 123);

    mostrar(raiz, 1);



    return 0;
}
