//Morel Alison.
#include <stdio.h>
#include <stdlib.h>

#include "FuncionesEmpleados.h"
#define TAMANIO 1000


int main()
{
    int opciones;
    int subMenuOpciones;
    int idEmpleado;
    idEmpleado=0;
    int identidad;
    identidad=0;
    int contadorEmpleados;
    contadorEmpleados=0;
    float promedio;
    int totalSalarios;
    eEmployee listaMisEmpleados[TAMANIO];
    do
    {
        opciones=menu();

        switch(opciones)
        {
        case 1:
           if((cargarEmpleados(listaMisEmpleados,TAMANIO,idEmpleado,contadorEmpleados))==1)
           {
               printf("Se cargo con exito.\n");
               contadorEmpleados++;
           }
           else
           {
               printf("No hay mas espacio para cargar el empleado.\n");
           }
            break;
        case 2:
            if(contadorEmpleados!=0)
            {
               if((modificarEmpleado(listaMisEmpleados,identidad,TAMANIO))==1)
                {
                    printf("Modificacion hecha!\n");
                }
                else
                {
                    printf("El numero de Id es incorrecto, intente de nuevo...\n");
                }
            }
            else
            {
                printf("Ingresar empleado por favor...\n");
            }
            imprimirEmpleados(listaMisEmpleados,TAMANIO);
            break;
        case 3:
            if(contadorEmpleados!=0)
            {
              if((eliminarEmpleado(listaMisEmpleados,identidad,TAMANIO))==0)
               {
                   printf("Se elimino con exito!.\n");
               }
               else
                {
                    printf("No existe el id, intente de nuevo...\n");
                }
            }
            break;
        case 4:
            if(contadorEmpleados!=0)
            {
               do
                {
                subMenuOpciones = subMenu ();
                    switch(subMenuOpciones)
                    {
                        case 1:
                        ordenarEmpleados(listaMisEmpleados,TAMANIO);
                        imprimirEmpleados(listaMisEmpleados,TAMANIO);
                            break;
                        case 2:
                        totalSalarios=salariosTotal(listaMisEmpleados,TAMANIO);
                        promedio=totalPromedioSalarios(listaMisEmpleados,TAMANIO,totalSalarios);
                        sacarSalarioPromedio(listaMisEmpleados,TAMANIO,promedio,totalSalarios);
                            break;
                    }
                }while(subMenuOpciones !=3);
            }
            break;
        }
    }while(opciones!=5);

    return 0;
}

