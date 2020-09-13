#include <stdio.h>
#include <stdlib.h>
#include "AlisonMorel.h"
int main()
{
    int contador=0;
    int opcion;
    float numero1;
    float numero2;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoPrimerFactorial;
    int resultadoSegundoFactorial;
    int banderaPrimerNumero=0;
    int banderaSegundoNumero=0;

    int banderaFactorial=0;
    do
    {
        printf("  Calculadora 2.0  \n");
        printf(" *Menu* \n");
        if(contador==0)
        {
            printf(" 1.Ingreso del primer operando (A=x): \n");
            printf(" 2.Ingreso del segundo operando (B=y): \n");
        }
        else
        { if(contador==1)
            {
                printf(" 1.Ingreso del primer operando (A=%f): \n", numero1);
                printf(" 2.Ingreso del segundo operando (B=y): \n");
            }
            else
            {
                printf(" 1.Ingreso del primer operando (A=%f): \n", numero1);
                printf(" 2.Ingreso del primer operando (B=%f): \n",numero2);
            }
        }
        printf(" 3.Calcular todas las operaciones: \n");
        printf(" a) Calcular la suma (A+B). \n");
        printf(" b) Calcular la resta (A-B). \n");
        printf(" c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B) \n");
        printf(" e) Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados: \n");
        printf(" 5.Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                if(banderaPrimerNumero==0)
                {
                    printf("Ingresar primer numero (A=x):");
                    scanf("%f", &numero1);
                    banderaPrimerNumero=1;
                }
                break;
            case 2:
                if(banderaSegundoNumero==0)
                {
                    printf("Ingresar segundo numero (B=y):");
                    scanf("%f", &numero2);
                    banderaSegundoNumero=1;
                }
                break;
            case 3://hacer todos los calculos
                if(banderaPrimerNumero==1 && banderaSegundoNumero==1)
                {
                    resultadoSuma=suma(numero1,numero2);//llamada de la funcion
                    resultadoResta=resta(numero1,numero2);
                    resultadoDivision=division(numero1,numero2);
                    resultadoMultiplicacion=multiplicacion(numero1,numero2);
                    resultadoPrimerFactorial=sacarPrimerFactorial(numero1);
                    resultadoSegundoFactorial=sacarSegundoFactorial(numero2);
                    printf(" Haciendo los calculos, espere por favor... \n");
                    }
                    else
                    {
                        printf("Ingrese numero correspondiente, A o B\n");
                    }
                break;
            case 4://solo mostrar.
                printf("A. El resultado de (A+B) es: %f \n", resultadoSuma);
                printf("B. El resultado de (A-B) es: %f \n", resultadoResta);
                printf("C. El resultado de (A/B) es: %f \n", resultadoDivision);
                printf("D. El resultado de (A*B) es: %f \n", resultadoMultiplicacion);
                printf("E. El factorial de A es: %d y El factorial de B es: %d \n", resultadoPrimerFactorial,resultadoSegundoFactorial);
                break;
            case 5:
                printf(" Gracias por usar el programa!!. ");

                break;
        }
        contador++;
    }while(opcion!=5);
    return 0;

}
