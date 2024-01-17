/********************************
 * Autores:
 *   - Marc Ferrer Fernández
 *   - Daniel Giralt Pascual
 *   - Francisco Hermosa Adame
 *******************************/
#include "directorios.h"


/**
 * Main del programa.
 */
int main(int argc, char **argv)
{
    char *camino, *ruta;
    int permisos, error;
    
    if (argc != 4)
    {
        fprintf(stderr, RED"Sintaxis: ./mi_chmod <disco> <permisos> </ruta>\n"RESET);
        return FALLO;
    }

    permisos = atoi(argv[2]);
    if (permisos<0 || permisos>7)
    {
        fprintf(stderr, RED"ERROR: La entrada de '<permisos>' no es válida (0-7)\n"RESET);
        return FALLO;
    }
    ruta = argv[3];
    
    camino = argv[1];
    if (bmount(camino) == FALLO)
    {
        fprintf(stderr, RED"ERROR EN ./mi_chmod\n"RESET);
        return FALLO;
    }

    if ((error = mi_chmod(ruta, permisos)) < 0)
    {
        mostrar_error_buscar_entrada(error);
        if (error == FALLO)
        {
            fprintf(stderr, RED"ERROR EN ./mi_chmod\n"RESET);
            return FALLO;
        }
    }

    if (bumount() == FALLO)
    {
        fprintf(stderr, RED"ERROR EN ./mi_chmod\n"RESET);
        return FALLO;
    }
    return EXITO;
}
