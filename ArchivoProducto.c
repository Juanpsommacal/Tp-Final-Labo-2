#include "ArchivoProducto.h"

// Devuelve 1 si la id ya pertenece a otro producto
int VerificarIdProducto(char nombreArchivo[], int id)
{
    FILE* archivo;
    int existe = 0;
    stProducto producto;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                //Si la ID ya pertenece a otro producto, notificamos a cual y cambiamos el valor de "existe"
                printf("\nEsta ID pertenece a %s %s", producto.marca, producto.nombre);
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdProducto)", nombreArchivo);

    return existe;
}

//Retorna la cantidad de productos que hay en el archivo
int contarCantidadProductos(char nombreArchivo[])
{
    FILE* archivo;
    int contador = 0;
    stProducto producto;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            //Contamos cada producto que haya en el archivo
            contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadProductos)", nombreArchivo);

    return contador;
}

//Cambia el estado de un producto, devuelve 1 si se logro con exito
int cambiarEstadoProducto(char nombreArchivo[], int id)
{
    FILE* archivo;
    int flag = 0;
    stProducto producto;
    archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
                //Si eliminado vale 1, lo cambia a 0
                if(producto.eliminado == 1)
                {
                    producto.eliminado = 0;
                }
                else
                {
                    //Si eliminado vale 0, lo cambia a 1
                    producto.eliminado = 1;
                }
                fseek(archivo, -sizeof(stProducto), SEEK_CUR);
                fwrite(&producto, sizeof(stProducto), 1, archivo);
            }
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (cambiarEstadoProducto)", nombreArchivo);
    return flag;
}

//Busca un producto por su ID y lo muestra por pantalla
int mostrarProductoPorId(char nombreArchivo[], int id)
{
    FILE* archivo;
    stProducto producto;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
                mostrarProducto(producto);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarProductoPorId)", nombreArchivo);
    }
    return flag;
}

//Recibe un producto y lo guarda en el archivo
int ingresarProductoAlArchivo(char nombreArchivo[], stProducto producto)
{
    int flag = 0;
    FILE* archivo;
    archivo = fopen(nombreArchivo, "ab");
    if(archivo != NULL)
    {
        flag = 1;
        fwrite(&producto, sizeof(stProducto), 1, archivo);
        fclose(archivo);
    }
    else
    {
        printf("\nError al abrir el archivo %s (ingresarProductoAlArchivo)", nombreArchivo);
    }
    return flag;
}

//Retorna la cantidad de productos que hay en el archivo, que cumplan con el estado recibido por parametro
int contarCantidadProductosPorEstado(char nombreArchivo[], int estado)
{
    FILE* archivo;
    int contador = 0;
    stProducto producto;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            //Contamos cada producto que haya en el archivo
            if(producto.eliminado == estado)
                contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadProductos)", nombreArchivo);

    return contador;
}

//Muestra todos los productos con el mismo estado que se pase por parametro. resumido = 1 muestra resumido, si es 0 muestra toda la descripcion
void mostrarProductoPorEstado(char nombreArchivo[], int estado, int resumido)
{
    FILE* archivo;
    stProducto producto;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.eliminado == estado)
            {
                if(resumido == 1)
                    mostrarProductoResumido(producto);
                else
                    mostrarProducto(producto);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarProductoPorId)", nombreArchivo);
    }
}

//Retorna el estado del producto
int verificarEstadoProducto(char nombreArchivo[], int id)
{
    FILE* archivo;
    int estado = -1;
    stProducto producto;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                estado = producto.eliminado;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarEstadoProducto)", nombreArchivo);

    return estado;
}

//Modifica un atributo recibido por parametro de un producto
int ModificarProducto(char nombreArchivo[], int id, int eleccion)
{
    stProducto producto;
    int flag = 0;
    FILE* archivo;
    archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
                if(eleccion == 1)
                {
                    printf("\nIngrese la nueva marca del producto: ");
                    fflush(stdin);
                    printf("\n\t");
                    scanf("%s", producto.marca);
                }
                else if(eleccion == 2)
                {
                    printf("\nIngrese el nuevo nombre del producto: ");
                    fflush(stdin);
                    printf("\n\t");
                    scanf("%s", producto.nombre);
                }
                else if(eleccion == 3)
                {
                    printf("\nIngrese el nuevo precio del producto: ");
                    printf("\n\t");
                    scanf("%f", &producto.precio);
                }
                fseek(archivo, -sizeof(stProducto), SEEK_CUR);
                fwrite(&producto, sizeof(stProducto), 1, archivo);
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (ModificarProducto)", nombreArchivo);
    return flag;
}

//Busca un producto por su ID y lo retorna
stProducto retornarProductoPorId(char nombreArchivo[], int id)
{
    FILE* archivo;
    stProducto producto;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(flag == 0 && fread(&producto, sizeof(stProducto), 1, archivo) > 0)
        {
            if(producto.idProducto == id)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarEstadoProducto)", nombreArchivo);

    return producto;
}




