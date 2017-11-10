#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int i, aux;
    EPersona lista[CANT];
    for(i=0 ; i<CANT ; i++){
        lista[i].estado = 0;
    }

    while(seguir=='s')
    {

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion); //validar
        setbuf(stdin,NULL);

        switch(opcion)
        {
            case 1:
                aux = agregarPersona(lista);
                if(aux == 0){
                    printf("Error al cargar datos");
                }else{
                    printf("Persona agregada!");
                }
                break;
            case 2:
                aux = borrarPersona(lista);
                if(aux == 0){
                    printf("ERROR AL BORRAR.");
                }else{
                    printf("Los datos han sido borrados satisfactoriamente");
                }
                break;
            case 3:
                ordenarArray(lista);
                imprimir(lista);
                break;
            case 4:
                imprimirGrafico(lista);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
