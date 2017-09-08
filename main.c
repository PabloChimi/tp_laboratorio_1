#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{

    char seguir='s';
    int opcion=0;
    double a=0;
    double b=0;
    double result;
    char c;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",a);
        printf("2- Ingresar 2do operando (B=%f)\n",b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones \n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        system("clear");

        switch(opcion)
        {
            case 1:
                printf("Ingrese 1er operando: ");
                scanf("%lf",&a);

                system("clear");
                break;
            case 2:
                printf("Ingrese 2do operando: ");
                scanf("%lf",&b);

                system("clear");
                break;
            case 3:
                result = suma(a,b);
                printf("La suma es: %f \n",result);

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 4:
                result = resta(a,b);
                printf("La resta es: %f \n",result);

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 5:
                result = division(a,b);
                printf("La division es: %f \n",result);

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 6:
                result = cociente(a,b);
                printf("El cociente es: %f \n",result);

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 7:
                result = factorial(a);
                if(result == 0){
                    printf("ERROR: Factorial solo aplicable al dominio N U {0} \n");
                }else{
                    printf("El factorial es: %f \n",result);
                }

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 8:
                result = suma(a,b);
                printf("La suma es: %f \n",result);

                result = resta(a,b);
                printf("La resta es: %f \n",result);

                result = division(a,b);
                printf("La division es: %f \n",result);

                result = cociente(a,b);
                printf("El cociente es: %f \n",result);

                result = factorial(a);
                if(result == 0){
                    printf("ERROR: Factorial solo aplicable al dominio N U {0} \n");
                }else{
                    printf("El factorial es: %f \n",result);
                }

                printf("\nPresione enter para continuar...");
                setbuf(stdin,NULL);
                scanf("%c",&c);
                system("clear");
                break;
            case 9:
                seguir = 'n';
                break;
        }

}
return 0;

}
