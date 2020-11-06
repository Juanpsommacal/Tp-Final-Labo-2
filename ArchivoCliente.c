#include "ArchivoCliente.h"

int VerificarIdAstronauta(char nombreArchivo[], int id) // Devuelve 1 si la id ya pertenece a otro astronauta
{
    FILE* archivoAstro;
    int flag = 0;
    stAstronauta astronauta;
    archivoAstro = fopen(nombreArchivo, "rb");
    if(archivoAstro != NULL)
    {
        while(fread(&astronauta, sizeof(stAstronauta), 1, archivoAstro) > 0)
        {
            if(astronauta.id == id)
            {
                printf("\nEsta ID ya pertenece a %s %s", astronauta.apellido, astronauta.nombre);
                flag = 1;
            }
        }
        fclose(archivoAstro);
    }else
        printf("\nError al abrir el archivo %s (VerificarIdAstronauta)", nombreArchivo);

    return flag;
}
