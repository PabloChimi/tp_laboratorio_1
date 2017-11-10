#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "utn.h"

/** \brief Agrega una pelicula al archivo bin.dat
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada
 * \return retorna 0 si hubo algun problema de validacion, reserva de memoria, con el archivo o si el titulo de la pelicula ya existe, retorna 1 si salio todo ok
 *
 */

int agregarPelicula(EMovie *movie){
    int aux, longString;
    int intAux;
    char charAux[LONGMOVIE], charAuxLargo[LONGMOVIE*3];
    FILE* pArch;

    pArch = fopen("./bin.dat" , "ab+");
    if( pArch == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
            return 0;
    }

    getString("Ingrese titulo de la pelicula\n", charAux);
    longString = strlen(charAux);
    if(longString == 0 || longString > LONGMOVIE){
        printf("Error: Maximo de %d caracteres\n", LONGMOVIE);
        exit(1);
        return 0;
    }

    rewind(pArch);
    while(!feof(pArch)){
        fread(movie,sizeof(EMovie),1,pArch);
        if(strcmp(charAux , movie->titulo) == 0)
        {
            printf("La pelicula ya existe\n");
            exit(1);
            return 0;
        }
    }
    strcpy(movie->titulo, charAux);
    printf("Datos cargados..\n");

    aux = getStringValidado("Ingrese el genero de la pelicula\n", "ERROR: Solo letras\n", "ERROR: maximo caracteres excedidos", charAux, LONGMOVIE);
    if(aux == 0){
        printf("Error al cargar los datos..\n");
        exit(1);
        return 0;
    }
    strcpy(movie->genero, charAux);
    printf("Datos cargados..\n");

    aux = getIntValidado("Ingrese la duracion de la pelicula\n", "ERROR: Solo numeros\n", "ERROR: Duracion demasiado larga\n", &intAux, 1, 600);
    if(aux == 0){
        printf("Error al cargar los datos..\n");
        exit(1);
        return 0;
    }
    movie->duracion = intAux;
    printf("Datos cargados..\n");

    getString("Ingrese descripcion de la pelicula\n", charAuxLargo);
    if(strlen(charAuxLargo) == 0 || strlen(charAuxLargo) > (LONGMOVIE*3)){
        printf("Error: Maximo de %d caracteres\n", LONGMOVIE*3);
        exit(1);
        return 0;
    }
    strcpy(movie->descripcion, charAuxLargo);
    printf("Datos cargados..\n");

    aux = getIntValidado("Ingrese el puntaje de la pelicula\n", "ERROR: Solo numeros\n", "ERROR: nota entre 1 y 10\n", &intAux, 1, 10);
    if(aux == 0){
        printf("Error al cargar los datos..\n");
        exit(1);
        return 0;
    }
    movie->puntaje = intAux;
    printf("Datos cargados..\n");

    getString("Ingrese link a la imagen\n", charAuxLargo);
    if(strlen(charAuxLargo) == 0 || strlen(charAuxLargo) > (LONGMOVIE*3)){
        printf("Error: Maximo de %d caracteres\n", LONGMOVIE*3);
        exit(1);
        return 0;
    }
    strcpy(movie->linkImagen, charAuxLargo);
    printf("Datos cargados..\n");
    fwrite(movie ,sizeof(EMovie) ,1 ,pArch);
    fclose(pArch);
    return 1;

}

/** \brief borra la pelicula diferenciadola por su nombre del archivo
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada
 * \return retorna 0 si hubo algun problema de validacion, reserva de memoria, con el archivo o si la pelicula no existe, retorna 1 si salio todo ok
 *
 */


int borrarPelicula(EMovie *movie){
    char opcion;
    char peliculaIngresada[LONGMOVIE];
    FILE* pArch;
    FILE* archivoNuevo;

    pArch = fopen("./bin.dat" , "rb");
    if( pArch == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
            return 0;
    }

    getString("Ingrese nombre de la pelicula a eliminar\n", peliculaIngresada);
    if(strlen(peliculaIngresada) == 0 || strlen(peliculaIngresada) > (LONGMOVIE*3)){
        printf("Error: Maximo de %d caracteres\n", LONGMOVIE*3);
        exit(1);
        return 0;
    }

    rewind(pArch);
    while(!feof(pArch))
    {
        fread(movie, sizeof(EMovie), 1 ,pArch);
        if(strcmp(movie->titulo, peliculaIngresada)==0)
        {
            printMovie(movie);
            break;
        }else{
            if(feof(pArch)){
                    printf("No se encuentra la pelicula\n");
                    exit(1);
                    return 0;
            }
        }
    }

    opcion = getChar("¿Desea eliminar la pelicula? Ingrese s para confirmar:  ");
    if(opcion=='s'){

        archivoNuevo = fopen("./archivoNuevo.dat","wb");
        if (archivoNuevo==NULL){
            printf("Error interno al crear nuevo archivo");
            exit(1);
        }

        rewind(pArch);
        while(!feof(pArch))
        {
            fread(movie,sizeof(EMovie),1,pArch);

            if(!feof(pArch))
            {
                if(strcmp(movie->titulo, peliculaIngresada)!=0){
                    setbuf(stdin, NULL);
                    fwrite(movie ,sizeof(EMovie) ,1 ,archivoNuevo);
                }
            }

        }


        printf("\nSe ha borrado la pelicula\n");

        fclose(pArch);
        fclose(archivoNuevo);
        remove("bin.dat");
        rename("archivoNuevo.dat","bin.dat");
    }
    return 1;
}

/** \brief modifica la pelicula diferenciandola por su nombre del archivo
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada
 * \return retorna 0 si hubo algun problema de validacion, reserva de memoria, con el archivo o si la pelicula ingresada no existe, retorna 1 si salio todo ok
 *
 */


void modificaPelicula(EMovie *movie){
    int aux, longString;
    int bandera = 0;
    char modifica, charAux[LONGMOVIE];
    int opcion;
    FILE* pArch;

    pArch = fopen("./bin.dat" , "ab+");
    if( pArch == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
    }

    getString("Ingrese titulo de la pelicula a modificar\n", charAux);
    longString = strlen(charAux);
    if(longString == 0 || longString > LONGMOVIE){
        printf("Error: Maximo de %d caracteres\n", LONGMOVIE);
        return;
    }

    rewind(pArch);
    while(!feof(pArch)){
        fread(movie,sizeof(EMovie),1,pArch);
        if(strcmp(charAux , movie->titulo) == 0)
        {
            printf("Pelicula encontrada!\n");
            bandera = 1;
        }
    }
    if(bandera == 0){
        printf("No se ha encontrado la pelicula\n");
        exit(1);
        return;
    }
    bandera = 0;
    modifica = getChar("¿Desea modificar la pelicula? Ingrese s para confirmar:  ");
    if(modifica=='s'){
        aux = getIntValidado("\n Elija el campoa  modificar\n 1-Titulo \n 2-Genero \n 3-Duracion \n 4-Descripcion \n 5-Puntaje \n 6-Link de imagen \n", "ERROR: Solo numeros\n", "ERROR: Opcion entre 1 y 6\n", &opcion, 1, 6);
                if(aux == 0){
                printf("Error al cargar los datos..\n");
                return;
                }

        switch(opcion){
            case 1:{
                getString("Ingrese el nuevo titulo de la pelicula\n", movie->titulo);     //Me estaria faltando ver que el titulo ingresado no este en la lista del archivo.
                if(strlen(movie->titulo) == 0 || strlen(movie->titulo) > LONGMOVIE){
                    printf("Error: Maximo de %d caracteres\n", LONGMOVIE);
                    bandera = 1;
                }

                break;
            }
            case 2:{
                aux = getStringValidado("Ingrese el genero nuevo de la pelicula\n", "ERROR: Solo letras\n", "ERROR: maximo caracteres excedidos", movie->genero, LONGMOVIE);
                if(aux == 0){
                    printf("Error al cargar los datos..\n");
                    bandera = 1;
                }
                break;
            }
            case 3:{
                aux = getIntValidado("Ingrese la nueva duracion de la pelicula\n", "ERROR: Solo numeros\n", "ERROR: Duracion demasiado larga\n", &movie->duracion, 1, 600);
                if(aux == 0){
                    printf("Error al cargar los datos..\n");
                    bandera = 1;
                }
                break;
            }
            case 4:{
                getString("Ingrese la nueva descripcion de la pelicula\n", movie->descripcion);
                if(strlen(movie->descripcion) == 0 || strlen(movie->descripcion) > (LONGMOVIE*3)){
                    printf("Error: Maximo de %d caracteres\n", LONGMOVIE*3);
                    bandera = 1;
                }
                break;
            }
            case 5:{
                aux = getIntValidado("Ingrese el nuevo puntaje de la pelicula\n", "ERROR: Solo numeros\n", "ERROR: nota entre 1 y 10\n", &movie->puntaje, 1, 10);
                if(aux == 0){
                    printf("Error al cargar los datos..\n");
                    bandera = 1;
                }
                break;
            }
            case 6:{
                getString("Ingrese el nuevo link a la imagen\n", movie->linkImagen);
                if(strlen(movie->linkImagen) == 0 || strlen(movie->linkImagen) > (LONGMOVIE*3)){
                    printf("Error: Maximo de %d caracteres\n", LONGMOVIE*3);
                    bandera = 1;
                }
                break;
            }
        }
        if(bandera==1){
            printf("Error en la validacion de datos");
        }else{
        fseek(pArch,(-1)*sizeof(EMovie),SEEK_CUR);
        setbuf(stdin, NULL);
        fwrite(movie ,sizeof(EMovie) ,1 ,pArch);
        printf("\nPelicula actualizada\n");
        fclose(pArch);
        }
    }

}

/** \brief genera un archivo html con el listado de peliculas
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada
 * \return
 *
 */


void generarPagina(EMovie *movie){
    FILE* pArch;
    FILE *pHtml;
    char cadena1[200];
    char cadena2[50];
    char cadena3[50];
    char cadena4[25];
    char cadena5[25];
    char cadena6[25];
    char cadena7[25];

    sprintf(cadena1,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
    sprintf(cadena2,"alt=''></a><h3><a href='#'>");
    sprintf(cadena3,"</a></h3><ul><li>Género: ");
    sprintf(cadena4,"</li><li>Puntaje: ");
    sprintf(cadena5,"</li><li>Duración: ");
    sprintf(cadena6,"</li></ul><p>");
    sprintf(cadena7,"</p></article>");

    pArch = fopen("./bin.dat" , "rb");
    if( pArch == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
    }

    pHtml = fopen("./pelis.html" , "w");
    if( pHtml == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
    }

    if( pHtml == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit(1);
    }
    else
    {
        rewind(pArch);
        while( !feof(pArch) ){

            fread(movie, sizeof(EMovie) ,1 ,pArch);
            if(!feof(pArch)){
                fprintf(pHtml, cadena1);
                fprintf(pHtml, movie->linkImagen);
                fprintf(pHtml, cadena2);
                fprintf(pHtml, movie->titulo);
                fprintf(pHtml, cadena3);
                fprintf(pHtml, movie->genero);
                fprintf(pHtml, cadena4);
                fprintf(pHtml, "%d", movie->puntaje);
                fprintf(pHtml, cadena5);
                fprintf(pHtml, "%d", movie->duracion);
                fprintf(pHtml, cadena6);
                fprintf(pHtml, movie->descripcion);
                fprintf(pHtml, cadena7);
            }
        }
        printf("\nArchivo generado\n");
    }
    fclose(pHtml);
    fclose(pArch);
}

/** \brief imprime por pantalla la pelicula ingresada
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada, el cual se imprimirá por pantalla
 * \return
 *
 */

void printMovie(EMovie *movie){
    printf("\nTitulo: %s \tDuracion: %d min.\tGenero: %s.\tPuntaje: %d .\nDescripcion: %s.\n%s\n\n",movie->titulo, movie->duracion, movie->genero, movie->puntaje, movie->descripcion, movie->linkImagen);

}

/** \brief imprime todas las peliculas del archivo bin.dat
 *
 * \param movie - un puntero del tipo EMovie con memoria reservada
 * \return
 *
 */

void printMovies(EMovie *movie){
    FILE* bin;
    int cant;
    bin = fopen("./bin.dat" , "rb");
    if( bin == NULL ){

            printf("El archivo no puede ser abierto\n");
            exit(1);
    }

    rewind(bin);

    while(!feof(bin)){
        cant = fread(movie,sizeof(EMovie), 1, bin);

        if(cant!=1){
            if(feof(bin)){
                break;
            }else{
                printf("No leyo el ultimo registro\n");
                break;
            }
        }
        //if(movie->codigo != 0)
        printMovie(movie);
    }
    fclose(bin);
}

