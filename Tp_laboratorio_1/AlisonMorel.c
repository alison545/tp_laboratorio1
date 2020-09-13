#include "AlisonMorel.h"

//DESARROLLO
float suma(float operando1, float operando2 )//Funcion suma.Desarrollo de la funcion.
{
    float total;
    total= (float)operando1 + operando2;
    return total;
}//SUMA

float resta(float operando1, float operando2)
{
    float total;
    total=(float)operando1-operando2;
    return total;
}//RESTA

float division(float operando1, float operando2)//DIVISION
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
}//MULTIPLICACION

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
        resultado=operando1*sacarPrimerFactorial(operando1-1);//FACTORIAL - operando 1
    }
    return resultado;
}

int sacarSegundoFactorial(int operando2)//FACTORIAL - operando 2
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
