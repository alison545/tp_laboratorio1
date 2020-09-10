#include <stdio.h>
#include <stdlib.h>

int suma(int operando1, int operando2);//primera funcion.
int resta(int operando1, int operando2);

int main()
{
    int opcion;
    int operando1;
    int operando2;
    int resultadoSuma;
    //int resultadoResta;

    do
    {
        printf(" *Menu* \n");
        printf("1.Ingreso del primer operando : \n");
        printf("2.Ingreso del segundo operando: \n");
        printf("3.Calcular todas las operaciones: \n");
        printf("4.Informar resultados: \n");
        printf("5.Salir\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                printf("Ingresar primer numero:");
                scanf("%d", &operando1);
                break;
            case 2:
                printf("Ingresar segundo numero:");
                scanf("%d", &operando2);
                break;
            case 3:
                resultadoSuma=suma(operando1,operando2);
                break;
            case 4:
                printf("a. El resultado de la suma es: %d ", resultadoSuma);
                break;
            case 5:
                printf("Gracias por usar el programa.");
                printf("fUNCIONA.");

                break;
        }
    }while(opcion!=5);
    return 0;
}

int suma(int operando1, int operando2 )
{
    int total;
    total= operando1 + operando2;
    return total;
}
