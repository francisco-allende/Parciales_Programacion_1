#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int edad;
    char nombre[20];
} typedef eEmpleado;

struct
{
    int id;
    float precio;
    int stock;
} typedef eRemedio;


//void cargarArray(int* vec, int tam);
//void miniAbm(int* vec, int tam);
//void mayorEdadYSuNombre(eEmpleado* emp, int tam, eEmpleado* mayorEmp);
//void findByIndex(int* arr, int tam, int* index);
void findRemedioBarato(eRemedio* remedios, int tam, eRemedio* elBarato);
void sumarStockBajarPrecio(eRemedio* remedios, int tam, eRemedio* newRem);


int main()
{


    int arrInt[5];
    /*1
    cargarArray(arrInt, 5);

    for(int i = 0; i < 5; i++)
    {
        printf("%d, ", arrInt[i]);
    }
    printf("\n\n");
    */
    /*2
    miniAbm(arrInt, 5);
    for(int i = 0; i < 5; i++)
    {
        printf("%d, ", arrInt[i]);
    }
    */
    /*
    eEmpleado emp[5];
    eEmpleado mayorEmp[1];
    mayorEdadYSuNombre(emp, 5, mayorEmp);
    printf("Empleado de mayor edad se llama %s y tiene %d anios \n",
           mayorEmp->nombre,
           mayorEmp->edad
           );
    */
    /*
    int arr[5] = {11, 25, 6, 8, 10};
    int myindex;
    findByIndex(arr, 5, &myindex);
    printf("%d \n", myindex);
    */

    eRemedio remedios[5] =
    {
        {111, 50000, 100},
        {222, 30000, 120},
        {333, 8000, 300},
        {444, 2000, 400 },
        {555, 90000, 500}
    };

    eRemedio menorPrecio[1];

    findRemedioBarato(remedios, 5, menorPrecio);
    printf("%.2f \n", menorPrecio->precio);

    eRemedio remedioActualizado[1] = {0, 0, 0};
    sumarStockBajarPrecio(remedios, 5, remedioActualizado);
    printf("new stock: %d, new price %.2f \n", remedioActualizado->stock, remedioActualizado->precio);


















    return 0;
}
/*
void cargarArray(int* vec, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i);
    }
}
*/
/*
void miniAbm(int* vec, int tam)
{
    int aux;
    int i;
    int j;

    //cargo
    for(int i = 0; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i);
    }

    //ordeno
    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
*/
/*
void mayorEdadYSuNombre(eEmpleado* emp, int tam, eEmpleado* mayorEmp)
{
    int flag = 0;

    for(int i = 0; i < tam; i++)
    {
        printf("\nIngrese la edad del empleado: ");
        scanf("%d", &emp[i].edad);
        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        scanf("%s", emp[i].nombre);
    }

    for(int i = 0; i < tam; i++)
    {
        if(!flag || emp[i].edad > mayorEmp->edad)
        {
            mayorEmp->edad = emp[i].edad;
            strcpy(mayorEmp->nombre, emp[i].nombre);
            flag = 1;
        }
    }
}
*/
/*
void findByIndex(int* arr, int tam, int* index)
{
    int nro;

    printf("Ingese nro a encontrar (11, 25, 6, 8, 10: ");
    scanf("%d", &nro);

    for(int i = 0; i < tam; i++)
    {
        if(nro == arr[i])
        {
            *index = i;
        }
    }
}
*/

void findRemedioBarato(eRemedio* remedios, int tam, eRemedio* elBarato)
{
    eRemedio aux;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(remedios[i].precio < remedios[j].precio)
            {
                aux = remedios[i];
                remedios[i] = remedios[j];
                remedios[j] = aux;
            }
        }
    }

    elBarato->precio = remedios[tam-1].precio;
}

void sumarStockBajarPrecio(eRemedio* remedios, int tam, eRemedio* newRem)
{
    int id;
    int newStock;
    float newPrice;

    printf("Ingrese el id del remedio a actualziar: ");
    scanf("%d", &id);
    newRem->id = id;

    printf("Ingrese el stock vendido: ");
    scanf("%d", &newStock);

    printf("Ingrese cuento aumento el precio: ");
    scanf("%f", &newPrice);

    for(int i = 0; i < tam; i++)
    {
        if(id == remedios[i].id)
        {
            newRem->stock = remedios[i].stock  - newStock;
            printf("%f \n", remedios[i].precio);
            newRem->precio = (float) remedios[i].precio + newPrice;
        }
    }
}























































































































































