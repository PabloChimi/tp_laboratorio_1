#include <stdio.h>
#include <stdlib.h>

/** \brief Suma dos números y devuelve el resultado.
 *
 * \param a : El primer número a sumar.
 * \param b : El segundo número a sumar.
 * \return La suma de ambos números.
 *
 */

double suma(double a, double b){
    double result;

    result = a + b;
    return result;
}

/** \brief Resta dos numeros
 *
 * \param a : El número se le restará
 * \param b : El número que va a restar.
 * \return La resta del primer parametro por el segundo.
 *
 */


double resta(double a, double b){
    double result;

    result = a - b;
    return result;
}

/** \brief Multiplica dos números.
 *
 * \param a : El primer número a multiplicar.
 * \param b : El segundo número a multiplicar.
 * \return El cociente de ambos números.
 *
 */


double cociente(double a, double b){
    double result;

    result = a * b;
    return result;
}

/** \brief La división de dos numeros.
 *
 * \param a : El numerador de la divisón.
 * \param b : El denominador de la división.
 * \return retorna la división de a por b (Nota: si el denominador es 0, devuelve 0 pero con un mensaje de error por consola, para no confundir el caso que el numerador es 0)
 *
 */


double division(double a, double b){
    double result;

    if(b!=0){
        result = a / b;
    }else{
        result = 0;
        printf("ERROR: No se puede dividir por cero. \n");
    }
    return result;
}

/** \brief Realiza el factorial de un número.
 *
 * \param a : El número al cual se le va a calcular el factorial
 * \return Devuelve el factorial de la parte entera del número ingresado. En caso de que el numero sea menor que 0, devuelve 0 en señal de error.
 *
 */


double factorial(double a){
    double i;
    double result = 1;

    if(a<0){
        result = 0;
    }
    for(i=1;i<=a;i++){
            result = result * i;
    }
    return result;
}
