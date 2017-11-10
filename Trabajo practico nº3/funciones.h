#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define LONGMOVIE 10

typedef struct{
    char titulo[LONGMOVIE];
    char genero[LONGMOVIE];
    int duracion;
    char descripcion[(LONGMOVIE * 3)];
    int puntaje;
    char linkImagen[LONGMOVIE*3];
}EMovie;


int agregarPelicula(EMovie *movie);
int borrarPelicula(EMovie *movie);
void modificaPelicula(EMovie *movie);

void generarPagina(EMovie lista[]);

void printMovie(EMovie *movie);
void printMovies(EMovie *movie);

#endif // FUNCIONES_H_INCLUDED
