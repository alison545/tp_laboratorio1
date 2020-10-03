#include "FuncionesEmpleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 1000
#define FALSE -1//OCUPADO
#define TRUE 0//VACIO
#define ELIMINADO 1

int menu ()
{
    int opcion;
        printf("%80s","1- Altas \n");
        printf("%80s","2- Modificar,ingresar numero de ID \n");
        printf("%80s","3- Baja\n");
        printf("%80s","4- Informar \n");

        printf("%80s","5- Terminar proceso\n");
        scanf("%d",&opcion);
        return opcion;
}

int subMenu()
{
    int opcionSubMenu;
    printf("%80s"," 1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("%80s"," 2- Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    scanf("%d",&opcionSubMenu);

    return opcionSubMenu;
}

int cargarEmpleados(eEmployee listaEmpleados[], int cantidad,int identidad, int contador)
{
    int i;
    int retorno;
    i = buscarLibre(listaEmpleados,cantidad);
    if(i != FALSE )
    {
        listaEmpleados[i] = crearDatoEmpleado(identidad,contador);
        retorno = 1;
    }
    else
    {
        retorno =0;
    }
    return retorno;
}

int buscarLibre (eEmployee listaEmpleados[], int cantidad)
{
    int indice;
    indice = FALSE;
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

eEmployee crearDatoEmpleado(int idAutomatico, int contadorEmpleados)
{
    eEmployee empleado;
    int IdentidadEmpleado;
    IdentidadEmpleado=contadorEmpleados+1;

    empleado.id=IdentidadEmpleado;
    printf("id: %d\n",empleado.id);
    printf("Ingresar nombre:\n");
    fflush(stdin);
    scanf("%[^\n]", empleado.name);
    printf("Ingresar apellido:\n");
    fflush(stdin);
    scanf("%[^\n]", empleado.lastName);
    printf("Ingresar salario:\n");
    scanf("%f",&empleado.salary);
    printf("Ingresar sector:\n");
    scanf("%d",&empleado.sector);

    empleado.isEmpty = FALSE;

    return empleado;
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

int BuscarIdDatoNumerico(eEmployee listaEmpleados[],int cantidad)
{
    int identidad;
    int i;
    int retorno;
    printf("Ingresar Id del usuario a eliminar: ");
    scanf("%d",&identidad);

    for(i=0;i<cantidad;i++)
    {
        if((listaEmpleados[i].id)==identidad)
        {
            retorno=1;
        }
    }
    retorno=0;
    return retorno;
}

int modificarEmpleado(eEmployee listaEmpleados[], int identidad, int cantidad)
{
    int retornoDeFuncionIdentidad;
    int i;
    int opcion;
    int retornoModificacion;
    retornoDeFuncionIdentidad = BuscarIdDatoNumerico(listaEmpleados,cantidad);
    for(i=0;i<cantidad;i++)
    {
        if(retornoDeFuncionIdentidad==1)
        {
            printf("¿Que desea modificar?\n");
            printf("1-Nombre\n");
            printf("2-Apellido\n");
            printf("3-Salario\n");
            printf("4-Sector\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Modificar Nombre:");
                fflush(stdin);
                scanf("%[^\n]",listaEmpleados[i].name);
                break;
            case 2:
                printf("Modificar Apellido:");
                fflush(stdin);
                scanf("%[^\n]",listaEmpleados[i].lastName);
                break;
            case 3:
                printf("Modificar salario:");
                scanf("%f",&listaEmpleados[i].salary);
                break;
            case 4:
                printf("Modificar Sector:");
                scanf("%d",&listaEmpleados[i].sector);
                break;
            }
            retornoModificacion=1;
            break;
        }
        else
        {
           retornoModificacion=0;
        }
    }
    return retornoModificacion;
}

int eliminarEmpleado(eEmployee listaEmpleados[],int identidad, int cantidad)
{
    int identidadRecibida;
    int i;
    int retorno;
    identidadRecibida = BuscarIdDatoNumerico(listaEmpleados,cantidad);

    for(i=0;i<cantidad;i++)
    {
        if((listaEmpleados[i].isEmpty)== FALSE)
        {
           if(listaEmpleados[i].id == identidadRecibida)
            {
                listaEmpleados[i].isEmpty= ELIMINADO;
                retorno = 0;
                break;
            }
            else
            {
               retorno=1;
            }
        }
    }
    return retorno;
}

int ordenarEmpleados(eEmployee listaEmpleados[], int cantidad)
{
    int i;
    int j;
    int similitud;
    eEmployee auxiliarEmpleado;
    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;i<cantidad;j++)
        {
            similitud=strcmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName);
            if(similitud==1)
            {
                auxiliarEmpleado=listaEmpleados[i];
                listaEmpleados[i]=listaEmpleados[j];
                listaEmpleados[j]=auxiliarEmpleado;
            }
        }
    }
    return 0;
}

int mostrarUnEmpleado(eEmployee unEmpleado)
{
        printf("%d %s %s %f %d\n",unEmpleado.id,unEmpleado.name,unEmpleado.lastName,unEmpleado.salary,unEmpleado.sector);
        return 0;
}

int imprimirEmpleados(eEmployee listaEmpleados[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(listaEmpleados[i].isEmpty == FALSE)
        {
          mostrarUnEmpleado(listaEmpleados[i]);
        }
    }
    return 0;
}

int salariosTotal(eEmployee listaEmpleados[],int cantidad)
{
    int i;
    int salarioTotal;
    salarioTotal=0;
    for(i=0;i<cantidad;i++)
    {
        salarioTotal = listaEmpleados[i].salary + salarioTotal;
    }
    return salarioTotal;
}

int totalPromedioSalarios(eEmployee listaEmpleados[],int cantidad, int sumaSalario)
{

    float promedio;

    promedio= (float) sumaSalario/cantidad;
    return promedio;
}

int sacarSalarioPromedio(eEmployee listaEmpleados[], int cantidad, float promedio, int totalSalarios)
{
    int i;
    int contador;

    for(i=0;i<cantidad;i++)
    {
        if(listaEmpleados[i].salary>promedio)
        {
            contador++;
        }
    }
    printf("El total es: %d\n",totalSalarios);
    printf("El promedio es:%f\n",promedio);
    printf("Cantidad de empleados que superan el salario promedio:%d\n",contador);
     return 0;
}
