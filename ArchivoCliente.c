#include "ArchivoCliente.h"

//Retorna la cantidad de clientes que hay en el archivo
int contarCantidadClientes(char nombreArchivo[])
{
    FILE* archivo;
    int contador = 0;
    stCliente cliente;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            //Contamos cada cliente que haya en el archivo
            contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadClientes)", nombreArchivo);

    return contador;
}

// Devuelve 1 si la id ya pertenece a otro cliente
int VerificarIdCliente(char nombreArchivo[], int id)
{
    FILE* archivo;
    int existe = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                //Si la ID ya pertenece a otro cliente, notificamos a quien y cambiamos el valor de "existe"
                printf("\nEsta ID pertenece a %s %s", cliente.apellido, cliente.nombre);
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return existe;
}

//Cambia el estado de un cliente, devuelve 1 si se logro con exito
int cambiarEstadoCliente(char nombreArchivo[], int id)
{
    FILE* archivo;
    int flag = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;
                //Si eliminado vale 1, lo cambia a 0
                if(cliente.eliminado == 1)
                {
                    cliente.eliminado = 0;
                }
                else if(cliente.eliminado == 0)
                {
                    //Si eliminado vale 0, lo cambia a 1
                    cliente.eliminado = 1;
                }
                fseek(archivo, -sizeof(stCliente), SEEK_CUR);
                fwrite(&cliente, sizeof(stCliente), 1, archivo);
            }
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (cambiarEstadoCliente)", nombreArchivo);
    return flag;
}

//Busca un cliente por su ID y lo muestra por pantalla
int MostrarClientePorId(char nombreArchivo[], int id)
{
    FILE* archivo;
    stCliente cliente;
    int flag = 0;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;
                mostrarCliente(cliente);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarClientePorId)", nombreArchivo);
    }
    return flag;
}

//Recibe un cliente y lo guarda en el archivo
int ingresarClienteAlArchivo(char nombreArchivo[], stCliente cliente)
{
    FILE* archivo;
    int flag = 0;
    archivo = fopen(nombreArchivo, "ab");
    if(archivo != NULL)
    {
        fwrite(&cliente, sizeof(stCliente), 1, archivo);
        fclose(archivo);
        flag = 1;
    }
    else
    {
        printf("\nError al abrir el archivo %s (ingresarClienteAlArchivo)", nombreArchivo);
    }
    return flag;
}

//Verifica si el username ya existe, devuelve 1 si existe
int verificarUserName(char nombreArchivo[], char username[])
{
    FILE* archivo;
    int existe = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(cliente.userName, username) == 0)
            {
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return existe;
}

//Verifica si el username y el password coinciden
int verificarPassword(char nombreArchivo[], char username[], char password[])
{
    FILE* archivo;
    int existe = 0;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if((strcmp(cliente.userName, username) == 0) && (strcmp(cliente.password, password) == 0))
            {
                existe = 1;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return existe;
}

//Retorna el rol del usuario
int verificarRol(char nombreArchivo[], char username[])
{
    FILE* archivo;
    int rol = -1;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(cliente.userName, username) == 0)
            {
                rol = cliente.rol;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return rol;
}

//Recibe un estado y muestra todos los clientes con ese estado. resumido = 1 muestra resumido, si es 0 muestra toda la descripcion
void MostrarClientePorEstado(char nombreArchivo[], int estado, int resumido)
{
    FILE* archivo;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.eliminado == estado)
            {
                if(resumido == 1)
                    mostrarClienteResumido(cliente);
                else
                    mostrarCliente(cliente);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarClientePorId)", nombreArchivo);
    }
}

//Retorna el estado del usuario
int verificarEstado(char nombreArchivo[], int id)
{
    FILE* archivo;
    int estado = -1;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                estado = cliente.eliminado;
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdCliente)", nombreArchivo);

    return estado;
}

//Modifica un atributo de un cliente, segun la eleccion del usuario
int ModificarCliente(char nombreArchivo[],int id, int eleccion)
{
    int validacion = 0, flag = 0;
    stCliente cliente;
    FILE* archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;

                if(eleccion == 1)
                {
                    printf("\nIngrese el nuevo nombre del cliente: ");
                    fflush(stdin);
                    scanf("%s", cliente.nombre);
                }
                else if(eleccion == 2)
                {
                    printf("\nIngrese el nuevo apellido del cliente: ");
                    fflush(stdin);
                    scanf("%s", cliente.apellido);
                }
                else if(eleccion == 3)
                {
                    printf("\nIngrese el nuevo domicilio del cliente: ");
                    fflush(stdin);
                    scanf("%s", cliente.domicilio);
                }
                else if(eleccion == 4)
                {
                    do
                    {
                        printf("\nIngrese el nuevo genero del cliente m, f, o: ");
                        fflush(stdin);
                        scanf("%c", &cliente.genero);
                    }while(cliente.genero != 'm' && cliente.genero != 'f' && cliente.genero != 'o');
                }
                else if(eleccion == 5)
                {
                    printf("\nIngrese el nuevo mail del cliente: ");
                    fflush(stdin);
                    scanf("%s", cliente.mail);
                }
                else if(eleccion == 6)
                {
                    do
                    {
                        printf("\nIngrese el nuevo username del cliente o admin: ");
                        fflush(stdin);
                        if(validacion == 1)
                            printf("\nEse username ya existe");
                        scanf("%s", cliente.userName);
                        validacion = verificarUserName(nombreArchivo, cliente.userName);
                    }while(validacion == 1);
                }
                else if(eleccion == 7)
                {
                    printf("\nIngrese la nueva password del cliente: ");
                    fflush(stdin);
                    scanf("%s", cliente.password);
                }
                else if(eleccion == 8)
                {
                    cliente.rol = 1;
                }
                fseek(archivo, -sizeof(stCliente), SEEK_CUR);
                fwrite(&cliente, sizeof(stCliente), 1, archivo);
            }
        }
        fclose(archivo);
    }else
        printf("\nError al abrir el archivo %s (ModificarCliente)", nombreArchivo);
    return flag;
}

//Retorna la cantidad de clientes que hay en el archivo por estado
int contarCantidadClientesPorEstado(char nombreArchivo[], int estado)
{
    FILE* archivo;
    int contador = 0;
    stCliente cliente;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            //Contamos cada cliente que cumpla con el estado que se pide por parametro
            if(cliente.eliminado == estado)
                contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadClientes)", nombreArchivo);

    return contador;
}

//Muestra un cliente, buscandolo por su username
void mostrarClientePorUsername(char nombreArchivo[], char username[])
{
    FILE* archivo;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(cliente.userName, username) == 0)
            {
                mostrarCliente(cliente);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarClientePorUsername)", nombreArchivo);
    }

}

//Retorna la id de un cliente, buscandolo por su username
int retornarIDClientePorUsername(char nombreArchivo[], char username[])
{
    int flag = 0;
    FILE* archivo;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(cliente.userName, username) == 0)
            {
                flag = cliente.idCliente;
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (MostrarClientePorUsername)", nombreArchivo);
    }
    return flag;
}

//Retorna la struct cliente buscandolo por ID
stCliente retornarStClientePorId(char nombreArchivo[], int id)
{
    int flag = 0;
    FILE* archivo;
    stCliente cliente;
    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        while(flag == 0 && fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if(cliente.idCliente == id)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s (retornarStClientePorId)", nombreArchivo);
    }
    return cliente;
}

