#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    EMovie* movie;
    movie = (EMovie*)malloc(sizeof(EMovie));
    /*FILE* pArchi;

    initBinFile(pArchi, "bin.dat" , "rb");
    fclose(pArchi);
*/

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
        {
            if(agregarPelicula(movie)==1)
            {
                printf("\nLa pelicula fue agregada con exito!\n\n");
                system("pause");
                break;
            }
            else
            {
                printf("La pelicula no pudo ser agregada\n\n");
                system("pause");
                break;
            }
        }
        case 2:
        {
            printMovies(movie);
            borrarPelicula(movie);
            system("pause");
            break;
        }
        case 3:
        {
            printMovies(movie);
            modificaPelicula(movie);
            system("pause");
            break;
        }
        case 4:
        {
           generarPagina(movie);
           system("pause");
           break;
        }
        case 5:
        {
            seguir = 'n';
            exit(1);
            break;
        }
        }
    }
    return 0;
}
