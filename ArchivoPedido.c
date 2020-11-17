#include "ArchivoPedido.h"

//Retorna la cantidad de pedidos unicos que hay en el archivo
int contarCantidadPedidos(char nombreArchivo[])
{
    FILE* archivo;
    int ultimoPedido = 0;
    stPedido pedido;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&pedido, sizeof(stPedido), 1, archivo) > 0)
        {
            //Buscamos el pedido con al ultima ID
            if(pedido.idPedido > ultimoPedido)
                ultimoPedido = pedido.idPedido;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadPedidos)", nombreArchivo);

    return ultimoPedido;
}

// Devuelve la id del pedido o retorna 0 si no hay pedido con el id de ese cliente
int VerificarIdPedidoPorCliente(char nombreArchivo[], int idCliente)
{
    FILE* archivo;
    int idPedido = 0;
    stPedido pedido;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(idPedido == 0 && fread(&pedido, sizeof(stPedido), 1, archivo) > 0)
        {
            if(pedido.idCliente == idCliente)
            {
                //Si la ID pertenece a un pedido, cambiamos el valor de idPedido
                idPedido = pedido.idPedido;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdPedidoPorCliente)", nombreArchivo);

    return idPedido;
}

//Recibe un pedido y lo guarda en el archivo
void ingresarPedidoAlArchivo(char nombreArchivo[], stPedido pedidoNuevo)
{
    FILE* archivo;
    stPedido pedido;
    archivo = fopen(nombreArchivo, "a+b");
    if(archivo != NULL)
    {
        fwrite(&pedidoNuevo, sizeof(stPedido), 1, archivo);
        fclose(archivo);
    }
    else
    {
        printf("\nError al abrir el archivo %s (ingresarProductosAlArchivo)", nombreArchivo);
    }
}

//Retorna el pedido en una lista buscandolo por la ID
nodoListaProducto* buscarPedidoPorClienteLista(char nombreArchivo[], int idPedido)
{
    char archivoProducto[20] = "Productos.bin";
    FILE* archivo;
    stPedido pedido;
    stProducto producto;
    archivo = fopen(nombreArchivo, "rb");
    nodoListaProducto* lista = inicializarLista();
    nodoListaProducto* nuevoNodo;

    if(archivo != NULL)
    {
        while(fread(&pedido, sizeof(stPedido), 1, archivo) > 0)
        {
            if(pedido.idPedido == idPedido)
            {
                producto = retornarProductoPorId(archivoProducto, pedido.idProducto);
                nuevoNodo = crearNodoLista(producto);
                lista = agregarAlPrincipio(lista, nuevoNodo);
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdPedido)", nombreArchivo);
    return lista;
}
