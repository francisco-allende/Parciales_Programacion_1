#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

/***********************************/
struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} typedef eNotebook;



struct
{
    int id;
    char nombre[20];
    int infectados;
    int recuperados;
    int muertos;
} typedef ePais;
/*******************************/



float aplicarDescuento(float precio);

int contarCaracteres(char cadenaChar[], char caracter);

int ordenarNotebooks(eNotebook notebooks[], int tam);

void actualizarRecuperados(ePais* pais, int recuperadosHoy);

void invertirCadena(char cadena[]);

void ordenarCaracteres(char cadena[]);

int main()
{
    /********************************************************************************************
    1)
    Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
    y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.*/

    float precioProducto = 100;
    float nuevoPrecioProducto;

    nuevoPrecioProducto = aplicarDescuento(precioProducto);

    printf("El precio es de %.2f. El precio con un descuento del 5 por ciento queda en un total de: %.2f \n\n", precioProducto, nuevoPrecioProducto);



    /**********************************************************************************************************
    2)
    Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
    y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */

    char cadenaChar [12] = "cronometro";
    char caracter = 'o';
    int contadorCaracter;

    contadorCaracter = contarCaracteres(cadenaChar, caracter);

    printf("Se encontro %d veces al caracter %c en la palabra %s  \n\n", contadorCaracter, caracter, cadenaChar);



    /**********************************************************************************************************
    3)
    Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
    Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.*/

    eNotebook notebooks[TAM] =
    {
        {111, "Ryzen", "Sony", 82000},
        {222, "Intel I5", "HP",60000},
        {333, "Ryzen 9", "Lenovo", 65000},
        {444, "Intel I7", "Sony", 75000},
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

    /**********************************************************************************************************
    4)
    Dada una estructura ePais cuyos campos son id (int), nombre(20 char), infectados(int), recuperados(int) y muertos(int).
    Desarrollar una funcion llamada ActualizarRecuperados que reciba el pais y los recuperados del dia y que acumule
    estos a los que ya tinene el pais.
    La funcion no devuelve nada.
    */

    ePais miPais[1] = {1, "Argentina", 100, 200, 15};
    int recuperadosHoy = 60;

    actualizarRecuperados(miPais, recuperadosHoy);

    printf("Total recuperados: %d \nTotal Infectados: %d \n\n",miPais->recuperados, miPais->infectados);

    /**********************************************************************************************************
    5)
    Crear una funcion que se llame invertirCadena que reciba una cadena de caracteres como parametro y su
    responsabilidad es invertir los caracteres de la misma. Ejemplo:
    Si le pasamos Gato lo retorna como otaG
    */

    char libro[30] = "Harry Potter";

    invertirCadena(libro);

    /**********************************************************************************************************
    6)
    Crear una funcion que se llame ordenarCaracteres qe reciba una cadena de caracteres como parametro y su responsabilidad
    es ordenar los caracteres de manera ascendente dentro de la cadena. Ejemplo:
    Si le pasamos la palabra "algoritmo" la deja como "agilmoort"
    */
    char palabra[20] = "zapatilla";
    ordenarCaracteres(palabra);


    return 0;
}
//Ejercicio nro 1
float aplicarDescuento(float precio)
{
    float descuento = 0.05;
    float nuevoPrecio;
    if(precio > 0)
    {
        descuento = (float) precio * descuento;
        nuevoPrecio = precio - descuento;
    }
    return nuevoPrecio;
}

//Ejercicio nro 2
int contarCaracteres(char cadenaChar[], char caracter)
{
    int contador = 0;
    int tam = strlen(cadenaChar);

    if(cadenaChar != NULL && caracter != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(cadenaChar[i] == caracter)
            {
                contador++;
            }
        }

    }
    return contador;

    /*La otra forma de hacerlo

    int contador = 0, i = 0;

    if(string != NULL)
    {
    	while(string[i] != '\0')
    	{
    		if(string[i] == caracter)
    		{
    			contador++;
    		}
    		i++;
    	}
    }
    return contador;


    */
}

//Ejercicio nro 3
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

//Ejercicio 4
void actualizarRecuperados(ePais* pais, int recuperadosHoy)
{
    if(pais != NULL && recuperadosHoy > -1)
    {
        pais->recuperados = pais->recuperados + recuperadosHoy;
        pais->infectados = pais->infectados - recuperadosHoy;
    }
}

//Ejercicio 5
void invertirCadena(char cadena[])
{
    char aux;
    int tam = strlen(cadena);

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            aux = cadena[i];
            cadena[i] = cadena[j];
            cadena[j] = aux;
        }
    }
    printf("%s \n\n", cadena);
}

//Ejercicio 6
void ordenarCaracteres(char cadena[])
{
    int tam = strlen(cadena);
    char aux;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {

            if(cadena[i] > cadena[j])
            {
                aux = cadena[i];
                cadena[i] = cadena[j];
                cadena[j] = aux;
            }

        }
    }
    printf("%s \n\n", cadena);
}






















