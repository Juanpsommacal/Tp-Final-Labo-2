#include "Listas.h"


//Inicializa los valores de la lista en NULL para el correcto funcionamiento del resto de los algoritmos
nodoListaProducto* inicializarLista()
{
    return NULL;
}

//Crea un nodo para la lista de productos
nodoListaProducto* crearNodoLista(stProducto producto)
{
    //Reservamos el espacio en memoria para la lista
    nodoListaProducto* aux = (nodoListaProducto*) malloc(sizeof(nodoListaProducto));
    //Asignamos los valores correspondientes
    aux->producto = producto;
    aux->siguiente = NULL;
    //Retornamos la lista
    return aux;
}

//Agrega un nuevo nodo al principio de la lista
nodoListaProducto* agregarAlPrincipio(nodoListaProducto* lista, nodoListaProducto* nuevoNodo)
{
    //Si no hay lista, nuevo nodo es la nueva lista
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        //Si ya hay lista, enganchamos nuevoNodo con la lista actual
        nuevoNodo->siguiente = lista;
        //Ahora que nuevoNodo apunta a la lista, hacemos que nuevoNodo sea la nueva lista
        lista = nuevoNodo;
    }
    return lista;
}

//Busca el ultimo nodo de la lista
nodoListaProducto* buscarUltimoNodo(nodoListaProducto* lista)
{
    //Creamos una copia de la lista
    nodoListaProducto* aux = lista;

    //Primero nos fijamos si hay lista
    if(lista != NULL)
    {
        //Mientras el siguiente de la lista actual no sea NULL, nos movemos al siguiente
        while(aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
    }
    //Retornamos el ultimo de la lista
    return aux;
}

//Agrega un nuevo nodo al final de la lista
nodoListaProducto* agregarAlFinal(nodoListaProducto* lista, nodoListaProducto* nuevoNodo)
{
    //Si no hay lista, nuevoNodo es la lista
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        //Creamos un nuevo nodo para guardar el retorno de la funcion buscarUltimoNodo
        nodoListaProducto* ultimoNodo = buscarUltimoNodo(lista);
        //Hacemos el enganche
        ultimoNodo->siguiente = nuevoNodo;
    }
    return lista;
}

//Agrega un nuevo nodo a la lista, por orden de producto alfabetico
nodoListaProducto* agregarEnOrdenPorNombreDeProducto(nodoListaProducto* lista, nodoListaProducto* nuevoNodo)
{
    //Si no hay lista, nuevoNodo es la lista
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        //Si el nombre del producto de nuevoNodo es menor a el primero de la lista, lo agregamos al principio
        if((strcmp(nuevoNodo->producto.nombre, lista->producto.nombre) < 0))
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        //Sino, buscamos la posicion donde habria que insertarlo
        else
        {
            //Creamos dos auxiliares para esto, uno que va a recorrer la lista y el otro que va a ir un paso atras
            nodoListaProducto* anterior = lista;
            nodoListaProducto* seguidora = lista->siguiente;
            //Mientras que seguidora no sea NULL y el nombre del producto sea mayor al que queremos insertar recorremos la lista
            while((seguidora != NULL) && (strcmp(nuevoNodo->producto.nombre, lista->producto.nombre) > 0))
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            //Ahora que ya encontramos el lugar, insertamos el nuevo nodo y hacemos los enganches
            nuevoNodo->siguiente = seguidora;
            anterior->siguiente = nuevoNodo;
        }
    }
    return lista;
}

//Muestra la lista
void mostrarLista(nodoListaProducto* lista)
{
    while(lista != NULL)
    {
        mostrarProducto(lista->producto);
        lista = lista->siguiente;
    }
}

//Borra un nodo, buscandolo por su ID
nodoListaProducto* borrarNodoPorIdProducto(nodoListaProducto* lista, int idABorrar)
{
    //Creamos 2 auxiliares para encontrar el nodo que tenemos que eliminar
    nodoListaProducto* anterior;
    nodoListaProducto* seguidora;
    //Nos fijamos si hay lista
    if(lista != NULL)
    {
        //Nos fijamos si el primero de la lista es el que hay que borrar
        if(lista->producto.idProducto == idABorrar)
        {
            //Copiamos la lista en un auxiliar y lo liberamos
            nodoListaProducto* aux = lista;
            //Avanzamos 1 posicion en la lista
            lista = lista->siguiente;
            free(aux);
        }
        //Sino, buscamos la posicion
        else
        {
            seguidora = lista;
            //Mientras seguidora sea distinta de NULL y no hayamos encontrado el dato, seguimos avanzando posiciones
            while((seguidora != NULL) && (seguidora->producto.idProducto != idABorrar))
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            //Ya tenemos en la variable anterior la direccion de memoria del nodo anterior al que queremos borrar
            //Y en la variable seguidora tenemos el nodo que queremos borrar
            if(seguidora != NULL)
            {
                //Nos salteamos el nodo que queremos borrar
                anterior->siguiente = seguidora->siguiente;
                //Borramos el nodo
                free(seguidora);
            }
        }
    }
    return lista;
}

//Borra un nodo, sirve para borrar toda la lista
nodoListaProducto * borrarNodo(nodoListaProducto * lista)
{
    nodoListaProducto * aux;
    if(lista!=NULL)
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}
