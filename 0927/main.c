#include <stdio.h>
#include <stdlib.h>
#define A 100
#define OCUPADO 1
#include "alumnos.h"
#include "curso.h"

int main()
{
    eAlumno listaAlumnos[A];
    inicializarEstado(listaAlumnos,A);
    int opcion,flag,aux,i,j;

    eCurso misCursos[3];
    inicializarCursos(misCursos);
   // mostrarTodosLosCursos(misCursos,3);

    inicializarAlumnosConDatos(listaAlumnos,A);
  //  mostrarTodosLosAlumnos(listaAlumnos,A);

//MOSTRAR ALUMNO CON CURSO
    for (i=0;i<A;i++) // por cada alumno
    {
        if (listaAlumnos[i].estado == OCUPADO)
        {
            printf ("%d---%s---%.2f---",   listaAlumnos[i].legajo,
                                        listaAlumnos[i].nombre,
                                        listaAlumnos[i].promedio);
            for (j=0;j<3;j++)
            {
                if(listaAlumnos[i].idCurso == misCursos[j].id)
                {
                    printf("%s\n",misCursos[j].nombre);
                    break;
                }
            }
        }
    }

    return 0;
}
