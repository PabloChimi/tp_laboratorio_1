#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje){
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje){
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje){
    char aux;
    printf("%s",mensaje);
    setbuf(stdin,NULL);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    setbuf(stdin,NULL);
    scanf ("%[^\n]s", input);
}

/**
 * \brief Se fija si el valor recibido es solo numerico
 * \param dato es el array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esSoloNumerico(char dato[]){
   int i=0;

   while(dato[i] != '\0'){

       if (i == 0 && dato[i] == '-'){
           i++;
           continue;
       }

       if(dato[i] < '0' || dato[i] > '9'){
           return 0;
       }

       i++;
   }
   return 1;
}

/**
 * \brief Se fija si el valor recibido es del tipo flotante y solo numerico (Salvo el punto)
 * \param dato es el array con la cadena que vamos a analizar
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char dato[]){
   int i=0;
   int puntos=0;

   while(dato[i] != '\0'){

       if (i == 0 && dato[i] == '-'){
           i++;
           continue;
       }

       if (dato[i] == '.' && puntos == 0){
           puntos++;
           i++;
           continue;
       }

       if(dato[i] < '0' || dato[i] > '9'){
           return 0;
       }

       i++;
   }
   return 1;
}


/**
 * \brief Se fija si el valor recibido solo posee letras
 * \param dato es el array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' (espacios en blanco) y letras y 0 si no lo es
 *
 */

int esSoloLetras(char dato[]){
   int i=0;

   while(dato[i] != '\0'){
       if((dato[i] != ' ') && (dato[i] < 'a' || dato[i] > 'z') && (dato[i] < 'A' || dato[i] > 'Z')){
           return 0;
       }
           i++;
   }
   return 1;
}


/**
 * \brief Se fija si el valor recibido solo posee letras y numeros
 * \param dato es el array con la cadena a ser analizada
 * \return 1 si contiene solo espacios, letras y números, y 0 si no lo es
 *
 */
int soloLetrasYNumeros(char dato[]){
   int i=0;

   while(dato[i] != '\0'){
       if((dato[i] != ' ') && (dato[i] < 'a' || dato[i] > 'z') && (dato[i] < 'A' || dato[i] > 'Z') && (dato[i] < '0' || dato[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char mensaje[],char input[]){
    char aux[256];
    getString(mensaje,aux);

    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMensajeTipo Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMensajeRango Es el mensaje a ser mostrado en caso de irse del rango de valores
 * \param cotaInferior Es el limite inferior aceptado
 * \param cotaSuperior Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getIntValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeRango[], int* input,int cotaInferior, int cotaSuperior){
    char auxStr[256];
    int auxInt;

    if (!getStringNumeros(mensaje,auxStr)){
        printf ("%s",errorMensajeTipo);
        return 0;
    }

    auxInt = atoi(auxStr);

    if(auxInt < cotaInferior || auxInt > cotaSuperior){
        printf ("%s",errorMensajeRango);
        return 0;
    }

    *input = auxInt;
    return -1;
}



/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMensajeTipo Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMensajeRango Es el mensaje a ser mostrado en caso de irse del rango de valores
 * \param cotaInferior Es el limite inferior aceptado
 * \param cotaSuperior Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \return 0 si consiguio el Numero -1 si no
 *
 */

int getFloatValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeRango[], float* input,float cotaInferior, float cotaSuperior){
    char auxStr[256];
    float auxInt;

    if (!getStringNumerosFlotantes(mensaje,auxStr)){
        printf ("%s",errorMensajeTipo);
        return 0;
    }

    auxInt = atof(auxStr);
    if(auxInt < cotaInferior || auxInt > cotaSuperior){
        printf ("%s", errorMensajeRango);
        return 0;
    }

    *input = auxInt;
    return -1;

}

/**
 * \brief Solicita un string
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMensajeTipo Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMensajeLargo Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param largoMaximo Longitud maxima del texto ingresado
 * \return 0 si consiguio el String -1 si no
 *
 */
int getStringValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeLargo[],char input[], int largoMaximo){
    char buffer[1024];

    if (!getStringLetras(mensaje, buffer))
    {
        printf ("%s",errorMensajeTipo);
        return 0;
    }

    if(strlen(buffer) >= largoMaximo)
    {
        printf ("%s",errorMensajeLargo);
        return 0;
    }

    strcpy(input,buffer);
    return -1;
}
