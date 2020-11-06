stCliente CargarCliente()
{
    char term;
    stCliente cliente;
    int flag = 0;

    do
    {
        do
        {
            printf("\nIngrese la ID del cliente (maximo 5 digitos): ");
            fflush(stdin);
            //La siguiente linea de codigo no nos permite ingresar caracteres en el scanf.
        }while((scanf("%d%c", &cliente.idCliente, &term) != 2 || term != '\n') || (cliente.idCliente <= 0 || cliente.idCliente >= 99999));
    }while(VerificarIdAstronauta(archivoAstronauta, astro.id) == 1);//Se repite hasta que la ID ingresada no corresponda a ningun otro astronauta.

    system("cls");

    printf("\nIngrese el nombre del astronauta: ");
    fflush(stdin);
    scanf("%s", astro.nombre);

    system("cls");

    printf("\nIngrese el apellido del astronauta: ");
    fflush(stdin);
    scanf("%s", astro.apellido);

    system("cls");

    printf("\nIngrese el apodo del astronauta: ");
    fflush(stdin);
    scanf("%s", astro.apodo);

    system("cls");

    do
    {
        printf("\nIngrese la edad del astronauta: ");
        fflush(stdin);
    }while((scanf("%d%c", &astro.edad, &term) != 2 || term != '\n') || (astro.edad < 18) || astro.edad > 100);

    system("cls");

    printf("\nIngrese la nacionalidad del astronauta: ");
    fflush(stdin);
    scanf("%s", astro.nacionalidad);

    system("cls");

    printf("\nIngrese la especialidad del astronauta: ");
    fflush(stdin);
    scanf("%s", astro.especialidad);

    system("cls");

    do
    {
        printf("\nIngrese las horas de vuelo totales del astronauta: ");
        fflush(stdin);
    }while((scanf("%d%c", &astro.horasVuelo, &term) != 2 || term != '\n') || astro.horasVuelo < 0);

    system("cls");

    do
    {
        printf("\nIngrese la cantidad de misiones que completo el astronauta: ");
        fflush(stdin);
    }while((scanf("%d%c", &astro.misionesRealizadas, &term) != 2 || term != '\n') || astro.misionesRealizadas < 0);

    system("cls");

    do
    {
        printf("\nIngrese la cantidad de horas en la EEI del astronauta: ");
        fflush(stdin);
    }while((scanf("%d%c", &astro.horasEstacion, &term) != 2 || term != '\n') || astro.horasEstacion < 0);

    system("cls");

    astro.estado = 1;
    astro.mision = 1;
    return astro;
}
