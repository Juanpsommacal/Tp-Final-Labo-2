#include "Arboles.h"


//Inicializa los valores de un arbol en NULL para el correcto funcionamiento de los demas algoritmos
nodoArbolstProducto* inicializarArbol()
{
    return NULL;
}

//Crea un nodo para el arbol de productos
nodoArbolstProducto* crearNodoArbol(stProducto producto)
{
    //Reservamos el espacio en la memoria
    nodoArbolstProducto* aux = (nodoArbolstProducto*) malloc(sizeof(nodoArbolstProducto));
    //Asignamos NULL a las ramas y le asignamos el producto al nuevo nodo
    aux->producto = producto;
    aux->izq = NULL;
    aux->der = NULL;
    //Retornamos el nodo
    return aux;
}

//Inserta un nodo en el arbol por orden de ID del producto
nodoArbolstProducto* insertarNodoArbol(nodoArbolstProducto* raiz, stProducto producto)
{
    //Si no hay raiz, la raiz ahora es el nuevo nodo
    if(raiz == NULL)
    {
        raiz = crearNodoArbol(producto);
    }
    //Si ya hay raiz, nos fijamos si la id del producto es menor o mayor que la raiz en la que estamos actualmente
    else
    {
        if(producto.idProducto < raiz->producto.idProducto)
            raiz->izq = insertarNodoArbol(raiz->izq, producto);
        else
            raiz->der = insertarNodoArbol(raiz->der, producto);
    }
    //Devolvemos la raiz
    return raiz;
}

//Muestra un nodo de un arbol si no figura como eliminado
void mostrarNodo(nodoArbolstProducto* raiz)
{
    if(raiz != NULL)
    {
        if(raiz->producto.eliminado == 0)
        {
            mostrarProducto(raiz->producto);
        }
    }

}

//Muestra el arbol en pre orden
void preOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        mostrarNodo(nodo);
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

//Muestra el arbol en post orden
void postOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        postOrden(nodo->izq);
        postOrden(nodo->der);
        mostrarNodo(nodo);
    }
}

//Muestra el arbol en in orden
void inOrden(nodoArbolstProducto * nodo)
{
    if(nodo != NULL)
    {
        inOrden(nodo->izq);
        mostrarNodo(nodo);
        inOrden(nodo->der);
    }
}

//Muestra el contenido del arbol, de 3 formas distintas
void mostrar(nodoArbolstProducto * raiz, int modoMostrar)
{
    switch(modoMostrar)
    {
        case 1 : preOrden(raiz);
            break;
        case 2 : inOrden(raiz);
            break;
        case 3 : postOrden(raiz);
            break;
    }
}

//Busca el nodo de mas izquierda del arbol
nodoArbolstProducto* buscarMasIzquierda(nodoArbolstProducto* raiz)
{
    if(raiz!= NULL)
    {
        //Si la izquierda del nodo en el que estamos en esta vuelta no es NULL, repetimos la funcion
        if(raiz->izq != NULL)
        {
            raiz = buscarMasIzquierda(raiz->izq);
        }
    }
    return raiz;
}

//Busca el nodo de mas derecha del arbol
nodoArbolstProducto* buscarMasDerecha(nodoArbolstProducto* raiz)
{
    if(raiz!= NULL)
    {
        //Si la derecha del nodo en el que estamos en esta vuelta no es NULL, repetimos la funcion
        if(raiz->der != NULL)
        {
            raiz = buscarMasDerecha(raiz->der);
        }
    }
    return raiz;
}

//Devuelve 1 si el nodoArbol es hoja, 0 si no lo es
int esHoja(nodoArbolstProducto* raiz)
{
    int flag = 0;

    if((raiz->izq == NULL) && (raiz->der == NULL))
    {
        flag = 1;
    }
    return flag;
}

//Busca un nodo en un arbol y lo retorna
nodoArbolstProducto* buscarNodoArbol(nodoArbolstProducto* raiz, int idABuscar)
{
    nodoArbolstProducto* aux = raiz;
    if(aux != NULL)
    {
        if(aux->producto.idProducto < idABuscar)
        {
            aux = buscarNodoArbol(aux->der, idABuscar);
        }
        else if(aux->producto.idProducto > idABuscar)
        {
            aux = buscarNodoArbol(aux->izq, idABuscar);
        }
    }
    return aux;
}

//Busca un producto por su ID en el arbol y lo elimina, devuelve 1 si se cambio con exito, o 0 si no se pudo cambiar
int cambiarEstadoNodoArbol(nodoArbolstProducto* raiz, int idABorrar)
{
    int flag = 0;
    nodoArbolstProducto* aux;
    if(raiz != NULL)
    {
        //Buscamos el producto que tenga la misma ID
        aux = buscarNodoArbol(raiz, idABorrar);

        //Si lo encuentra, cambiamos el estado y le asignamos 1 al flag
        if(aux != NULL)
        {
            aux->producto.eliminado = 1;
            flag = 1;
        }
    }
    //Retornamos el flag
    return flag;
}

//Carga un arbol binario desde el archivo de productos ordenados por ID
nodoArbolstProducto* cargarArbolDesdeArchivo(char nombreArchivo[])
{
    FILE* archivo;
    //Creamos una stProducto auxiliar para cargar los datos del archivo
    stProducto aux;
    nodoArbolstProducto* raiz;
    //Primero contamos la cantidad de productos que hay en el archivo para poder distribuir bien los datos en el arbol
    int cantProductos = contarCantidadProductos(nombreArchivo);
    //Dividimos la cantidad de productos por 2 para poner un numero intermedio en la raiz
    cantProductos = cantProductos / 2;

    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        //Movemos el cursor hacia la mitad del archivo
        fseek(archivo, (cantProductos * sizeof(stProducto)), SEEK_SET);
        //Pasamos del archivo al auxiliar
        fread(&aux, sizeof(stProducto), 1, archivo);
        //Ingresamos el producto en el arbol
        raiz = insertarNodoArbol(raiz, aux);
        //Volvemos al principio del archivo
        rewind(archivo);
        //Cargamos los numeros impares
        while(fread(&aux, sizeof(stProducto), 1, archivo) > 0)
        {
            //Verifica si la id del producto es impar y si no es la misma que ya esta cargada en la raiz
            if(aux.idProducto %2 == 1 && aux.idProducto != raiz->producto.idProducto)
            {
                raiz = insertarNodoArbol(raiz, aux);
            }
        }
        //Volvemos otra vez al inicio
        rewind(archivo);
        //Ahora cargamos los numeros pares
        while(fread(&aux, sizeof(stProducto), 1, archivo) > 0)
        {
            //Verifica si la id del producto es par y si no es la misma que ya esta cargada en la raiz
            if(aux.idProducto %2 == 0 && aux.idProducto != raiz->producto.idProducto)
            {
                raiz = insertarNodoArbol(raiz, aux);
            }
        }
    }
    else
        printf("\nError al abrir el archivo %s (cargarArbolDesdeArchivo)", nombreArchivo);
    return raiz;
}
