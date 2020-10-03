

typedef  struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


int menu();
int subMenu();


int cargarEmpleados(eEmployee [], int cantidad,int identidad, int contador);

int buscarLibre(eEmployee [], int cantidad);

eEmployee crearDatoEmpleado(int idAutomatico, int contadorEmpleados);

int estadoIsEmpty(eEmployee [],int cantidad);

int BuscarIdDatoNumerico(eEmployee[],int cantidad);
int modificarEmpleado(eEmployee[], int identidad, int cantidad);
int eliminarEmpleado(eEmployee [],int identidad, int cantidad);
int ordenarEmpleados(eEmployee [], int cantidad);
int mostrarUnEmpleado(eEmployee);
int imprimirEmpleados(eEmployee [],int cantidad);
int salariosTotal(eEmployee [],int cantidad);
int totalPromedioSalarios(eEmployee [],int cantidad, int sumaSalario);
int sacarSalarioPromedio(eEmployee [], int cantidad, float promedio,int sumaSalario);
