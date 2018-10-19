#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int entero;
    char caracter;
}eDato;

eDato* constructor();
void mostrarDato(eDato* );

int main()
{
    eDato* d;

    d = cargarDatos();
    if (d == NULL)
    {
        printf("No hay espacio");
    }
    else
    {
      mostrarDato(d);
    }


    return 0;
}

eDato* constructor()//NO MUESTRO MENSAJES DENTRO DEL CONSTRUCTOR. USO EL RETURN
{
    eDato* pDato;
    pDato = (eDato*)malloc(sizeof(eDato));
    if(pDato != NULL)
    {
        pDato->entero = 2;
        pDato->caracter = 'A';
    }

    return pDato;
}

void mostrarDato(eDato* pDato)
{
    printf("%d--%c",pDato->entero,pDato->caracter);
}


