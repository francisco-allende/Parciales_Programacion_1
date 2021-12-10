#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int base;
    int altura;
    int perimetro;
    float area;
} typedef eTriangulo;

void highAndLow(char cadena[]);
int findDifferentNumber(int arrNum[], int tam);
int findNeedle(char junkAndNeedle[][20], int tam);
void calcularPromedio(int arrNums[], int tam);
int sacarCuadrado(int num);
void menorACero(int arr[], int tam);
void calcularTriangulo(base, altura);
void calcularTriangulo(eTriangulo* triangulo, int base, int altura);
void arrComun(int arrA[], int arrB[]);
void arrComunStrings(char arrStirng1[][20], char arrStirng2[][20], int tam);
void findVocales(char word[], int tam);
void findVocalesContador(char word[], int tam);
void findPairs();
void sumarMultiplos(int num);
void findMayorInArray(int vec[]);
void sortDecreciente(int vec[]);
void newVecSorted(int vecA[], int vecB[], int tam);
void legajoEdadYSalarioPromedio(int vecL[], int vecE[], int vecS[], int tam);
void sortVecWithPositivesAndNegatives(int vec[], int tam);
void abm();


int main()
{
    /*
        high_and_low("1 2 3 4 5")  // return "5 1"
        high_and_low("1 2 -3 4 5") // return "5 -3"
        high_and_low("1 9 3 4 -5") //return "9 -5"
    */
    char serieA[20] = "1 2 3 4 5";
    char serieB[20] = "1 2 0 4 5";
    char serieC[20] = "1 9 2 4 5";

    highAndLow(serieA);
    highAndLow(serieB);
    highAndLow(serieC);

    /*
    return different number of the array
    */

    int arrNumA[6] = {17, 17, 17, 3, 17, 17};
    int arrNumB[3] = {1, 1, 2};
    int differentA;
    int differentAB;

    differentA = findDifferentNumber(arrNumA, 6);
    differentAB = findDifferentNumber(arrNumB, 3);
    printf("Numero diferente del array: %d \n", differentA);
    printf("Numero diferente del array: %d \n", differentAB);

    /*
    Find the needle in an array full of junk. Return the index where the needle was found
    */

    char junkAndNeedle[7][20] = {"waste", "junk", "trash", "randomJunk", "moreJunk", "needle", "randomJunk"};
    int indexNeedle;

    indexNeedle = findNeedle(junkAndNeedle, 7);
    printf("Needle found in index %d \n", indexNeedle);

    /*
    Calcular promedio en array
    */
    int arrNums[5] = {1, 4, 8, 10, 2};
    calcularPromedio(arrNums, 5);

    /*
    Calcular el cuadrado de un numero
    */

    int randomNumber = 10;
    int cuadrado = sacarCuadrado(randomNumber);
    printf("%d al cuadrado es %d \n", randomNumber, cuadrado);

    /*
    Mayor a cero
    */
    int arrMayorCero[10] = {-1, -2, -3, 4, 5,6, -7, -8,-9, 10};
    menorACero(arrMayorCero, 10);

    /*
    Calcular perimtero y area triangulo
    */

    eTriangulo triangulo[1]= {50, 80, 0, 0};
    int base = 50;
    int altura = 80;
    calcularTriangulo(triangulo, base, altura);
    printf("El perimetro del triangulo es de %d y el area es de %.2f cm\n", triangulo->perimetro, triangulo->area);

    /*
    Generar nuevo array con cosas en comun
    */
    int arrA[5] = {1, 0, 2, 9, 20};
    int arrB[5] = {3, 4, 1, 0, 20};
    arrComun(arrA, arrB);

    /*
    Lo mismo con strings
    char arrStirng1[5][20] = {"fran", "daniel", "franco", "javier", "miranda"};
    char arrStirng2[5][20] = {"alex", "fran", "miranda", "jose", "mariana"};
    arrComunStrings(arrStirng1, arrStirng2, 5);
    */

    /*
    Encontrar vocales
    Hacerlo con el contador dinamico
    */
    char word[30] = "Murcielago rosa";
    findVocales(word, 30);
    findVocalesContador(word, 30);

    /* find par numbers from 0 to 100*/
    findPairs();

    /*sumar multiplos*/
    int numMultiplo = 3;
    sumarMultiplos(numMultiplo);

    /*mayor de un vector*, orden decreciente*/
    int arrNumMayor[5] = {1, 6, 20, 10, 5};
    findMayorInArray(arrNumMayor);
    sortDecreciente(arrNumMayor);

    /*new vector and sorted from high to low*/
    int vecA[5] = {12, 24, 5, 0, -3};
    int vecB[5] = {18, -4, 10, 80, -16};
    newVecSorted(vecA, vecB, 5);


    int vecL[5] = {0, 1, 2, 3, 4};
    int vecE[5] = {20, 31, 42, 23, 34};
    int vecS[5] = {220, 1050, 420, 300, 445};
    legajoEdadYSalarioPromedio(vecL, vecE, vecS, 5);

    sortVecWithPositivesAndNegatives(vecB, 5);

    abm();


    return 0;
}

//No lo pude hacer con numeros negativos por el simbolo del menos. Es un sort normal.
//al acomodar ascedente, me deja el mas grande adelante, el ams chico atras.
void highAndLow(char cadena[])
{

    char aux;
    int tam = strlen(cadena);

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(cadena[i] < cadena[j])
            {
                aux = cadena[i];
                cadena[i] = cadena[j];
                cadena[j] = aux;
            }
        }
    }

    char first = cadena[0];
    char last = cadena[4];

    printf("%c %c \n", first, last);
}

//mi cirterio es que si el numero del indice i es distinto al anterior, entonces entro al if
//para que no me tome el anterior al primer numero (osea, indice -1 comparado con 0) arranco a iterar desde el indice 1
//enotnces el primer if al q puede entrar pegunta si indice 1 es disitnto de 0
//Solo hay uno distinto. El que viene sera distinto al anterior aunqeu no sea realmente el diferente. Meto break xq ya lo encontre



int findDifferentNumber(int arrNum[], int tam)
{
    int diff;

    for(int i = 1; i < tam; i++)
    {
        if(arrNum[i] != arrNum[i-1])
        {
            diff = arrNum[i];
            break;
        }
    }

    return diff;
}

//for comun y corriente usando strcmp
int findNeedle(char junkAndNeedle[][20], int tam)
{
    int index;
    int esNeedle;

    for(int i = 0; i < tam; i++)
    {
        esNeedle = strcmp(junkAndNeedle[i], "needle");
        if(!esNeedle)
        {
            index = i;
            break;
        }
    }


    return index;
}

void calcularPromedio(int arrNums[], int tam)
{
    int promedio;
    int acumulador = 0;

    for(int i = 0; i < tam; i++)
    {
        acumulador =
            acumulador + arrNums[i];
    }

    promedio = acumulador / tam;

    printf("El proemdio es %d \n", promedio);
}

int sacarCuadrado(int num)
{
    return num * num;
}

void menorACero(int arr[], int tam)
{
    int contNeg = 0;
    int contNat = 0;


    for(int i = 0; i < tam; i++)
    {
        if(arr[i] < 0)
        {
            contNeg++;
        }
        else
        {
            contNat++;
        }
    }

    printf("Hay %d nros menores a cero y %d mayores a cero\n", contNeg, contNat);
}


void calcularTriangulo(eTriangulo* triangulo, int base, int altura)
{
    triangulo->base = base;
    triangulo->altura = altura;
    triangulo->perimetro = base + (altura * 2);
    triangulo->area = (float) (base * altura) / 2;
}

void arrComun(int arrA[], int arrB[])
{
    int aux[5];

    printf("Nuevo array\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(arrA[i] == arrB[j])
            {
                aux[i] = arrA[i];
                printf("%d \n", aux[i]);
            }
            else
            {
                aux[i] = -1;
            }
        }
    }
}
/*
void arrComunStrings(char arrStirng1[][20], char arrStirng2[][20], int tam)
{
    char aux[5];

    printf("Nuevo array strings\n");
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(!strcmp(arrStirng1[i], arrStirng1[j]))
            {
                strcpy(aux[i], arrStirng1[i]);
                printf("%s \n", aux[i]);
            }
            else
            {
                strcpy(aux[i], "nn");
            }
        }
    }
}
*/

void findVocales(char word[], int tam)
{
    int contA = 0;
    int contE = 0;
    int contI = 0;
    int contO = 0;
    int contU = 0;

    for(int i = 0; i < tam; i++)
    {
        switch(word[i])
        {
        case 'a':
            contA++;
            break;

        case 'e':
            contE++;
            break;

        case 'i':
            contI++;
            break;

        case 'o':
            contO++;
            break;

        case 'u':
            contU++;
            break;
        }
    }
    printf("Se encontraron %d a, %d e, %d i, %d o, %d u \n", contA, contE, contI, contO, contU);
}

void findVocalesContador(char word[], int tam)
{
    char contArr[30] = {0};
    int contA = 0;
    int contE = 0;
    int contI = 0;
    int contO = 0;
    int contU = 0;

    for(int i = 0; i < tam; i++)
    {
        switch(word[i])
        {
        case 'a':
            contArr[i] = 'a';
            break;

        case 'e':
            contArr[i] = 'e';
            break;

        case 'i':
            contArr[i]= 'i';
            break;

        case 'o':
            contArr[i]= 'o';
            break;

        case 'u':
            contArr[i]= 'u';
            break;
        }
    }

    for(int i = 0; i < tam; i++)
    {
        if(contArr[i] == 'a')
        {
            contA++;
        }
        if(contArr[i] == 'e')
        {
            contE++;
        }
        if(contArr[i] == 'i')
        {
            contI++;
        }
        if(contArr[i] == 'o')
        {
            contO++;
        }
        if(contArr[i] == 'u')
        {
            contU++;
        }
    }

    printf("Se encontraron %d a, %d e, %d i, %d o, %d u \n", contA, contE, contI, contO, contU);
}

void findPairs()
{
    int contPairs = 0;

    for(int i = 1; i < 101; i++)
    {
        if(i % 2 == 0)
        {
            contPairs++;
        }
    }

    printf("There are %d pair numbers between 0 and 100 \n", contPairs);
}


void sumarMultiplos(int num)
{

    int acumulador = 1;

    for(int i = 0; i < 10; i++)
    {
        acumulador = num * acumulador;
    }
    printf("3 * 3 10 veces es %d\n", acumulador);


}

void findMayorInArray(int vec[])
{
    int mayor;
    int mayorIndex;
    int bandera = 0;

    for(int i = 0; i < 5; i++)
    {
        if(!bandera || vec[i] > mayor)
        {
            mayor = vec[i];
            mayorIndex = i;
            bandera = 1;
        }
    }
    printf("El numero mayor es %d y se encunetra en el indice %d \n", mayor, mayorIndex);
}

void sortDecreciente(int vec[])
{
    int aux;
    int tam = 5;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vec[i] < vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(int i = 0; i < tam; i++)
    {
        printf("%d, ", vec[i]);
    }
    printf("\n\n");
}

void newVecSorted(int vecA[], int vecB[], int tam)
{
    int vecC[tam];
    int aux;

    //sumo
    for(int i = 0; i < tam; i++)
    {
        vecC[i] = vecA[i] + vecB[i];
    }

    //ordeno
    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vecC[i] < vecC[j])
            {
                aux = vecC[i];
                vecC[i] = vecC[j];
                vecC[j] = aux;
            }
        }
    }

    //muestro
    for(int i = 0; i < tam; i++)
    {
        printf("%d, ", vecC[i]);
    }
    printf("\n\n");

}

void legajoEdadYSalarioPromedio(int vecL[], int vecE[], int vecS[], int tam)
{

    int acumulaEdades = 0;
    int acumulaSalarios = 0;
    int promedioE;
    int promedioS;

    for(int i = 0; i < tam; i++)
    {
        acumulaEdades = acumulaEdades + vecE[i];
        acumulaSalarios = acumulaSalarios + vecS[i];
    }

    promedioE = acumulaEdades / tam;
    promedioS = acumulaSalarios / tam;

    for(int i = 0; i < tam; i++)
    {
        if(vecE[i] > promedioE)
        {
            printf("Edad por encima del promedio de %d con legajo %d \n", vecE[i], vecL[i]);
        }
        if(vecS[i] > promedioS)
        {
            printf("Salario por encima del promedio de %d con legajo %d \n", vecS[i], vecL[i]);
        }
    }
}

void sortVecWithPositivesAndNegatives(int vec[], int tam)
{
    int aux;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vec[i] < 0 && vec[j] < 0)
            {
                if(vec[i] > vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
            else
            {
                if(vec[i] < vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }

    for(int i = 0; i < tam; i++)
    {
        printf("%d, ", vec[i]);
    }
    printf("\n\n");


}

void abm()
{
    int tam = 4;
    int vec[tam];
    int aux;

    for(int i = 0; i < tam; i++)
    {
        printf("Cargue un numero: ");
        scanf("%d", &vec[i]);
    }
    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
                if(vec[i] > vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
        }
    }
    printf("\n mini abm \n");
    for(int i = 0; i < tam; i++)
    {
        printf("%d, ", vec[i]);
    }
}






























































































































