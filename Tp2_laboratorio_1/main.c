//Morel Alison.
#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10
#define FALSE -1//OCUPADO
#define TRUE 0//VACIO

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
int subMenu();

eEmployee crearDatoEmpleado();//este es el empleado
int buscarLibre(eEmployee [], int cantidad);
int estadoIsEmpty(eEmployee [],int cantidad);//1era funcion de las que figuran en las consignas del tp.
int cargarEmpleados(eEmployee [], int cantidad);//2da funcion de las que figuran en las consignas del tp.


//------------------------------------------------MAIN---------------------------
int main()
{
    int opciones;
    int subMenuOpciones;


    int retornoCargarEmpleados;
    eEmployee listaMisEmpleados[TAMANIO];
    eEmployee miEmpleado;
    do
    {
        opciones=menu();

        switch(opciones)
        {
        case 1:
// Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario
            miEmpleado = crearDatoEmpleado();
            retornoCargarEmpleados = cargarEmpleados(listaMisEmpleados,TAMANIO);
            if(retornoCargarEmpleados !=0)
            {
                printf("No hay espacio libre :");
            }
            break;
        case 2:
// Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector


            break;
        case 3:
//Se ingresará el Número de Id y se eliminará el empleado del sistema.

            break;

        case 4:
            //LLAMADA A LA FUNCION DE SUBMENU.
            do
            {
                subMenuOpciones = subMenu ();
                switch(subMenuOpciones)
                {
                case 1:
                     printf("SUBMENU1");//LLAMADA FUNCION DE ORDENAR POR APELLIDO Y SECTOR.
                    break;
                case 2:
                    printf("submenu 2");//LLAMADA FUNCION DE --> Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
                    break;
                }
            }while(subMenuOpciones !=1 && subMenuOpciones !=2);
            break;
        }
    }while(opciones!=5);

    return 0;
}
//--------------------------------------------------TERMINA MAIN-----------------------------------------------------------

int menu () //MENU!
{
    int opcion;

        printf("1- Altas: \n ");/* Se debe permitir ingresar un empleado calculando automáticamente el número
                                    de Id. El resto de los campos se le pedirá al usuario*/
        printf("2- Modificar, ingresar numero de ID: \n"); /*Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
                                        o Salario o Sector*/
        printf("3- Baja:\n");//Se ingresará el Número de Id y se eliminará el empleado del sistema.
        printf("4- Informar: \n");//Despues hacer un submenu.

        printf("5- Terminar proceso: ");
        scanf("%d",&opcion);
        return opcion;
}

int subMenu()
{
    int opcionSubMenu;
    printf("1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.");
    printf("2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio. ");
    scanf("%d",&opcionSubMenu);

    return opcionSubMenu;
}

int buscarLibre (eEmployee listaEmpleados[], int cantidad)
{
    int indice = FALSE;
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(listaEmpleados[i].isEmpty == TRUE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int estadoIsEmpty(eEmployee listaEmpleados[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        listaEmpleados[i].isEmpty = TRUE;
    }
    return 0;
}

eEmployee crearDatoEmpleado()
{
    eEmployee empleado;
    int idEmpleado;

    idEmpleado = buscarLibre(listaEmpleados[],cantidad)+1;

    printf("Ingresar nombre: ");
    fflush(stdin);
    scanf("%[^\n]", empleado.name);
    printf("Ingresar apellido: ");
    fflush(stdin);
    scanf("%[^\n]", empleado.lastName);
    printf("Ingresar salario: ");
    scanf("%f",&empleado.salary);
    printf("Ingresar sector: ");
    scanf("%d",&empleado.sector);

    empleado.isEmpty = FALSE;

    return empleado;
}

int cargarEmpleados(eEmployee listaEmpleados[], int cantidad)
{
    int i;
    i = buscarLibre(listaEmpleados,cantidad);

    if(i != -1 )
    {
        listaEmpleados[i] = crearDatoEmpleado(idAutomatico);
    }

    return 0;
}
