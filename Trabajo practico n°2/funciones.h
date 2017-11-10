#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    float dni;

}EPersona;


int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], float dni);

int agregarPersona(EPersona lista[]);

int borrarPersona(EPersona lista[]);

void ordenarArray(EPersona lista[]);

void imprimir(EPersona lista[]);

void imprimirGrafico(EPersona lista[]);

int cantidadEnRango(EPersona lista[], int minimaEdad, int maximaEdad);

#endif // FUNCIONES_H_INCLUDED
