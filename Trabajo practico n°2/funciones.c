#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EPersona lista[]){
    int i;
    int retorno = -1;
    for(i=0 ; i<CANT ; i++){
            if(lista[i].estado == 0){
                retorno = i;
                break;
            }
    }
    return retorno;
}


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona lista[], float dni){
    int i;
    int retorno = -1;
    for(i=0 ; i<CANT ; i++){
            if(lista[i].dni == dni){
                retorno = i;
                break;
            }
    }
    return retorno;
}

/** \brief agrega una persona a la lista
 *
 * \param lista - Es el array que contiene los datos de tipo EPersona
 * \return si hubo algun error retorna 0, si sale todo ok 1
 *
 */

int agregarPersona(EPersona lista[]){
    int edad, aux, espacioLibre;
    float dni;
    char nombre[50];

    espacioLibre = obtenerEspacioLibre(lista);
    if(espacioLibre == -1){
            printf("La lista esta llena!");
            return 0;
    }

    aux = getStringValidado("Ingrese nombre: \n", "ERROR: Solo letras", "ERROR: Ingrese a lo sumo 50 caracteres", nombre, 50);
    if(aux == 0){

            //scanf("%c", &c);
            return 0;
    }else{
        printf("Datos cargados..");
    }

    aux = getFloatValidado("Ingrese DNI: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &dni, 1, 40000000);
    if(aux == 0){
        return 0;
    }else{
        printf("Datos cargados..");
    }

    aux = buscarPorDni(lista,dni);
    if(aux != -1 && lista[aux].estado){
        printf("El dni ya existe");
        return 0;
    }

    aux = getIntValidado("Ingrese edad: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &edad, 0, 200);
    if(aux == 0){
        return 0;
    }else{
        printf("Datos cargados..");
    }

    lista[espacioLibre].dni = dni;
    lista[espacioLibre].edad = edad;
    strcpy(lista[espacioLibre].nombre, nombre);
    lista[espacioLibre].estado = 1;
    return 1;

}

/** \brief borra la persona ingresada de la lista
 *
 * \param lista - el array con los datos tipo EPersona
 * \return retorna 0 si hubo un error al borrar, 1 si todo salio ok
 *
 */


int borrarPersona(EPersona lista[]){
    int aux;
    float dniUsuario;
    aux = getFloatValidado("Ingrese DNI del usuario a borrar: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &dniUsuario, 1, 50000000);
    if(aux == 0){
        printf("Error al cargar datos");
        return 0;
    }
    aux = buscarPorDni(lista, dniUsuario);
    if(aux == -1){
        printf("El usuario no existe");
        return 0;
    }
    lista[aux].estado = 0;
    return 1;

}

/** \brief ordena el array por nombre
 *
 * \param lista - el array con los datos tipo EPersona
 * \return
 *
 */


void ordenarArray(EPersona lista[]){
    int i, j;
    EPersona aux;
    for(i=0 ; i<CANT ; i++){
        for(j=i+1 ; j < CANT ; j++){
            if(strcmp(lista[i].nombre,lista[j].nombre)){
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

/** \brief imprime por pantalla el array de personas
 *
 * \param lista - el array con los datos tipo EPersna
 * \return
 *
 */


void imprimir(EPersona lista[]){
    int i;
    printf("%-25s%-15s%-10s\n", "Nombre", "DNI", "Edad");
    for(i=0 ; i<CANT ; i++){
        if(lista[i].estado){
            printf("%-25s%-15.0f%-10d\n", lista[i].nombre, lista[i].dni, lista[i].edad);
        }
    }
}

/** \brief imprime por pantalla un grafico de las edades
 *
 * \param lista - array con datos tipo EPersona
 * \return
 *
 */


void imprimirGrafico(EPersona lista[]){
    int rangoUno, rangoDos, rangoTres;
    rangoUno = cantidadEnRango(lista, 0, 18);
    rangoDos = cantidadEnRango(lista, 19, 35);
    rangoTres = cantidadEnRango(lista, 36, 200);
    printf("\n%-6s%-7s%-6s", " <18","19-35",">35");

    while(rangoUno > 0 || rangoDos > 0 || rangoTres > 0 ){
        if(rangoUno>0){
            printf("\n%s","  *  ");
            rangoUno--;
        }else{
            printf("\n%s", "     ");
        }
        if(rangoDos>0){
            printf("%s","   *   ");
            rangoDos--;
        }else{
            printf("%s", "       ");
        }
        if(rangoTres>0){
            printf("%s","  *  ");
            rangoTres--;
        }else{
            printf("%s", "     ");
        }
    }


}

/** \brief indica cuantas personas estan en el rango de edad establecido
 *
 * \param lista - el array de datos tipo EPersona
 * \param minimaEdad - un int que indica la cota inferior del rango aceptable
 * \param maximaEdad - un int que indica la cota superior del rango aceptable
 * \return retorna la cantidad de personas encontradas dentro del rango dado
 *
 */


int cantidadEnRango(EPersona lista[], int minimaEdad, int maximaEdad){
    int i;
    int acumulador = 0;
    for(i=0 ; i<CANT ; i++){
        if(lista[i].edad>=minimaEdad && lista[i].edad<=maximaEdad && lista[i].estado){
            acumulador++;
        }
    }
    return acumulador;
}
