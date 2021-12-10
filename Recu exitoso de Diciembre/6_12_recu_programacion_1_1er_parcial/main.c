#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5


struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} typedef eNotebook;

int ordenarNotebooks(eNotebook notebooks[], int tam);
int calcularIVA(float precioBruto, float* valorImpuesto);
int subibaja(char cadena[]);

int main()
{
    /*** PARCIAL FRANCISCO ALLENDE DIVISION A PROGRAMACION 1, RECUPERATORIO PRIMER PARCIAL. FECHA 6/12/2021***/

    /*
    1)
    Crear una función llamada calcularIVA que reciba como primer parámetro el precio bruto de un producto y como segundo parámetro
    la dirección de memoria de una variable donde debe escribir el valor del impuesto(el IVA es 21%).
    La función retorna 1 si salió todo bien o 0 si hubo algún error. Realizar la llamada desde main.
    */
    float valImp;
    float precio;

    printf("Ingrese el precio en bruto del producto: ");
    scanf("%f", &precio);

    if(calcularIVA(precio, &valImp))
    {
        printf("Operacion realizada con exito, Valor impuesto %.2f\n", valImp);
        printf("Precio + IVA = %.2f\n\n", precio+valImp);
    }
    else
    {
        printf("Algo fallo en la operacion\n");
    }
    printf("\n\n");

    /*
    2. Crear una función que se llame subibaja que reciba una cadena de caracteres
    y que los caracteres en minúscula los pase a mayúscula y los que están en mayúscula los pase a minúscula
    retorna 1 si esta todo bien o 0 si hubo algún error.
    */
    char texto[] = "Hola Mundo!!\n";
    if (subibaja(texto))
    {
        printf("Todo Correcto.  Texto: %s\n", texto);
    }
    else
    {
        printf("Se presento Error\n");
    }


    /*
    3)
    Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
    Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.*/
    eNotebook notebooks[TAM] =
    {
        {111, "Ryzen", "Sony", 82000},
        {222, "Intel I5", "HP",60000},
        {333, "Ryzen 9", "Lenovo", 65000},
        {444, "Intel I7", "Dell", 75000},
        {555, "Ryzen 5", "Sony", 90000},
    };
    if(ordenarNotebooks(notebooks, TAM))
    {
        for(int i = 0; i < TAM; i++)
        {
            printf("%d, %s, %s, $ %.2f \n\n",  notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
        }
    }
    else
    {
        printf("No se pudo ordenar el array\n\n");
    }


    return 0;
}
//1)
int calcularIVA(float precioBruto, float *valorImpuesto)
{
    int todoOk = 0;

    if(valorImpuesto != NULL && precioBruto > 0)
    {
        *valorImpuesto = precioBruto * 0.21;
        todoOk = 1;
    }

    return todoOk;
}

//2)
int subibaja(char cadena[])
{
    int todoOk = 0;

    if(cadena != NULL)
    {
        int i = 0;
        while (cadena[i])
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = toupper(cadena[i]);
            }
            else if (cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                cadena[i] = tolower(cadena[i]);
            }
            i++;
        }
        todoOk = 1;
    }
    return todoOk;
}


//3)
int ordenarNotebooks(eNotebook notebooks[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;

    if(notebooks != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(
                    stricmp(notebooks[i].marca, notebooks[j].marca) > 0 ||
                    (stricmp(notebooks[i].marca, notebooks[j].marca) == 0 &&
                     (notebooks[i].precio < notebooks[j].precio))
                )
                {
                    auxNotebook = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxNotebook;
                }
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


































































































