//Morel Alison.
#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10
#define OCUPADO 1
#define LIBRE 0

typedef  struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

//Prototipos de funciones.
int menu();//MENU!
int crearId();
eEmployee crearDatoEmpleado(int idAutomatico);

//La funcion sera int para que cuando devuelva ese retorno lo pueda usar en las validaciones y corroborar que si se cargaron empleados o al menos uno.
int main()
{
    int opciones;
    do
    {
        opciones=menu();

        switch(opciones)
        {
        case 1:
            //LLAMADA A LA FUNCION DE ALTAS.
            break;
        case 2:
            //LLAMADA A LA FUNCION DE BAJAS.
            break;
        case 3:
            //LLAMADA A LA FUNCION DE MODIFICAR.
            break;
        case 4:
            //LLAMADA A LA FUNCION DE INFORMAR Y COLOCAR SUBMENU.
            break;
        }
    }while(opciones!=5);


    return 0;
}


int menu () //MENU!
{
    int opcion;

        printf("1- Altas: \n ");/* Se debe permitir ingresar un empleado calculando automáticamente el número
                                    de Id. El resto de los campos se le pedirá al usuario*/
        printf("2- Modificar: \n"); /*Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
                                        o Salario o Sector*/
        printf("3- Baja:\n");//Se ingresará el Número de Id y se eliminará el empleado del sistema.
        printf("4- Informar: \n");//Despues hacer un submenu.

        printf("5- Terminar proceso: ");
        scanf("%d",&opcion);
        return opcion;
}

int

eEmployee crearDatoEmpleado(int idAutomatico);
{
    eEmployee empleado;
    int idEmpleado;
    idEmpleado=0;//CORREGIR

    printf("Ingresar nombre: ");
    scanf("%[^\n]",&empleado.name);
    printf("Ingresar apellido: ");
    scanf("%[^\n]",&empleado.lastName);
    printf("Ingresar salario: ");
    scanf("%f",&empleado.salary);
    printf("Ingresar sector: ");
    scanf("%d",&empleado.sector);

    empleado.isEmpty = OCUPADO;

    return empleado;
}
