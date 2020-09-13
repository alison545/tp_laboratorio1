#include "AlisonMorel.h"

//DESARROLLO
float suma(float operando1, float operando2 )//Funcion suma.Desarrollo de la funcion.
{
    float total;
    total= (float)operando1 + operando2;
    return total;
}

float resta(float operando1, float operando2)
{
    float total;
    total=(float)operando1-operando2;
    return total;
}

float division(float operando1, float operando2)
{
    float total;
    total= (float)operando1/operando2;
    return total;
}
float multiplicacion(float operando1,float operando2)
{
    float total;
    total=(float)operando1*operando2;
    return total;
}

int sacarPrimerFactorial(int operando1)
{
    int resultado;
    if(operando1==1)
    {
        return 1;
    }
    else
    {
        resultado=operando1*sacarPrimerFactorial(operando1-1);
    }
    return resultado;
}

int sacarSegundoFactorial(int operando2)
{
    int resultado;
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
