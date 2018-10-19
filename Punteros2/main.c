#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int entero;
    char caracter;
}eDato;

eDato* cargarDatos();
//eDato* cargarArray(eDato*,int);
void mostrarDato(eDato* );

int main()
{
    eDato* pDato;

    pDato = cargarDatos();
    mostrarDato(pDato);

    return 0;
}

/*funcion retorna puntero a estructura.
Adentro lo creamos y cargams con datos.*/

eDato* cargarDatos()
{
    eDato dato;
    eDato* pDato;
    pDato = &dato;

    pDato->entero = 2;
    pDato->caracter = 'A';

    return pDato;
}

void mostrarDato(eDato* pDato)
{
    printf("%d--%c",pDato->entero,pDato->caracter);
}

/*eDato* cargarArray(eDato* array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        cargarDatos((array+i),tam);
    }
}

eDato* mostrarArray(eDato* array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       mostrarDato((array+i),tam);
    }
}*/
