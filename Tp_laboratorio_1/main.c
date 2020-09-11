#include <stdio.h>
#include <stdlib.h>

int suma(int operando1, int operando2);//primera funcion.Declaracion.
//TIPO NOMBRE FUNCION (TIPO_VARIABLE,....)
int resta(int operando1, int operando2);
float division(float operando1, float operando2);
int multiplicacion(int operando1, int operando2);
int sacarPrimerFactorial(int operando1);
int sacarSegundoFactorial(int operando2);

//int menu()

int main()
{
    int opcion;
    int numero1;
    int numero2;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoPrimerFactorial;
    int resultadoSegundoFactorial;
   // int resultadoSegundoFactorial;
    //int resultadoResta;

    do
    {
        printf(" Calculadora 2.0 \n");
        printf(" *Menu* \n");
        printf(" 1.Ingreso del primer operando (A=x): \n");
        printf(" 2.Ingreso del segundo operando (B=y) : \n");
        printf(" 3.Calcular todas las operaciones: \n");
        printf(" 4.Informar resultados: \n");
        printf(" 5.Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresar primer numero (A=x):");
                scanf("%d", &numero1);
                break;
            case 2:
                printf("Ingresar segundo numero (B=y):");
                scanf("%d", &numero2);
                break;
            case 3://hacer todos los calculos
                resultadoSuma=suma(numero1,numero2);//llamada de la funcion
                resultadoResta=resta(numero1,numero2);
                resultadoDivision=division(numero1,numero2);
                resultadoMultiplicacion=multiplicacion(numero1,numero2);
                resultadoPrimerFactorial=sacarPrimerFactorial(numero1);
                resultadoSegundoFactorial=sacarSegundoFactorial(numero2);
                printf("Haciendo calculos...");
                break;
            case 4://solo mostrar.
                printf("A. El resultado de (A+B) es: %d \n", resultadoSuma);
                printf("B. El resultado de (A-B) es: %d \n", resultadoResta);
                if(resultadoDivision==0)
                {
                    printf("No es posible dividir por 0 \n");
                }
                else
                {
                    printf("C. El resultado de (A/B) es: %f \n", resultadoDivision);
                }
                printf("D. El resultado de (A*B) es: %d \n", resultadoMultiplicacion);
                printf("E. El factorial de A es: %d y El factorial de B es: %d \n", resultadoPrimerFactorial,resultadoSegundoFactorial);
                break;//("y El factorial de B es: %d \n", resultadoSegundoFactorial);
            case 5:
                printf(" Gracias por usar el programa. ");
                //printf("fUNCIONA.");
                break;
        }
    }while(opcion!=5);
    return 0;
}

int suma(int operando1, int operando2 )//Funcion suma.Desarrollo de la funcion.
{
    int total;
    total= operando1 + operando2;
    return total;
}

int resta(int operando1, int operando2)
{
    int total;
    total=operando1-operando2;
    return total;
}

float division(float operando1, float operando2)
{
    float total;

    if(operando2==0)
    {
        total=0;
    }
    total= (float)operando1/operando2;
    return total;
}

int multiplicacion(int operando1,int operando2)
{
    int total;
    total=operando1*operando2;
    return total;
}

int sacarPrimerFactorial(int operando1)
{
    int resultado;
    //int i;
    if(operando1==1)
    {
        return 1;
    }
    else
    {
        resultado=operando1*sacarPrimerFactorial(operando1-1);//operando 1
    }
    return resultado;
}

int sacarSegundoFactorial(int operando2)//operando 2
{
    int resultado;
    //int i;
    if(operando2==1)
    {
        return 1;
    }
    else
    {
        resultado=operando2*sacarSegundoFactorial(operando2-1);
    }
    return resultado;
}
