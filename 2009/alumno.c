#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
int cargarAlumnoEnListado  (eAlumno listado [], int tam)
{
    int indice;
    int encontro =0;

    indice = buscarEspacio(listado,tam);

    if (indice != -1)
    {
        listado[indice] = cargarAlumno(); // PIDE LOS DATOS
        listado[indice].estado = OCUPADO;
        encontro =1;
    }
    return encontro;
}

int buscarEspacio (eAlumno listado [], int tam)
{
    int indice = -1;
    int i;
    for (i=0;i<tam;i++)
    {
        if (listado[i].estado == VACIO)
        {
            indice = i;
            break;
        }

    }
    return indice;

}

eAlumno cargarAlumno ()
{
    eAlumno miAlumno;

    printf ("Ingrese el legajo: ");
    scanf ("%d", &miAlumno.legajo);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets (miAlumno.nombre);

    printf ("Ingrese su direccion: ");
    fflush(stdin);
    gets (miAlumno.direccion);
}


int borrarAlumno (eAlumno listado[],int tam) //1.PEDIR LEG 2.BUSCO LEG. SI NO EXISTE AVISO. SI EXISTE 3.CAMBIO ESTADO A BORRADO
{
    int legajo;
    int i;
    int encontro=0;

    printf ("ingrese el legajo: "):
    scanf ("%d", &legajo);

    for (i=0;i<tam;i++)
    {
        if (legajo == listado[i].legajo && listado[i].estado == OCUPADO)
        {
            listado[i].estado = BORRADO;
            encontro = 1 ;
            break;
        }
    }
    return encontro;
}
