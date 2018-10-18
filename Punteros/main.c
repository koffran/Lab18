#include <stdio.h>
#include <stdlib.h>

/*void cargar(int*,int);
void mostrar(int*,int);*/

typedef struct
{
    int entero;
    char caracter;
}eDato;

int main()
{
    //int array[5];
    //  cargar(array, 5); //PASA LA DIREC DE MEMORIA
   // mostrar(array,5);

    /*eDato miDato = {1,'B'};
    eDato* pDato;
    pDato = &miDato;

    pDato = &miDato; //NO COLGAR CON EL AMPERSAND
    printf("%d--%c\n",(*pDato).entero,(*pDato).caracter);
    printf("%d--%c\n",pDato->entero,pDato->caracter);*/

    int i;
   eDato miDato[] = {{1,'B'},{1,'C'}};
    eDato* pDato;

    pDato = miDato;

    for (i=0;i<2;i++)
    {
       // printf("%d--%c\n",(*(pDato+i)).entero,(*(pDato+i)).caracter);//Primero busca la memoria, despues devuelve el dato y despus ingresa al campo.
        printf("%d--%c\n",(pDato+i)->entero,(pDato+i)->caracter);
    }
    return 0;
}

/*void cargar(int* pArray,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",pArray+i); //Recorre el array con aritmetica de punteros
    }
}

void mostrar(int* pArray,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Numero en memoria: %d\n",*(pArray+i));
    }
}*/
