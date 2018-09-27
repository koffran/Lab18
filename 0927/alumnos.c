#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include "alumnos.h"

void inicializarEstado (eAlumno* lista,int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        lista[i].estado = 0;
    }
}

void inicializarAlumnosConDatos (eAlumno listado [], int tam)
{
    int legajo [5] = {1,2,3,4,5};
    char nombre [5][50] = {"Juan","Maria","Pepe","Claudia","Sebastian"};
    float promedio [5] ={8.5,5,6.5,3.5,7};
    char direccion [5][50] = {"Direccion1","Direccion2","Direccion3","Direccion4","Direccion5"};
    int curso[5] = {1,2,1,3,2,};

    int i;
    for (i=0;i<5;i++)
    {
        listado[i].idCurso = curso[i];
        listado[i].legajo = legajo[i];
        listado[i].promedio = promedio[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].direccion,direccion[i]);
        listado[i].estado = 1;
    }

}

void mostrarAlumno (eAlumno alumnoParametro)
{
    if (alumnoParametro.estado == 1)
    {
        printf("%s---%d---%d\n",alumnoParametro.nombre,alumnoParametro.legajo,alumnoParametro.idCurso);
    }

}
void mostrarTodosLosAlumnos (eAlumno* alumnos,int tam)
{
    int i;
    printf("\n-----ALUMNOS-----\n");
    for (i=0; i<tam; i++)
    {
        mostrarAlumno(alumnos[i]);
    }
}
