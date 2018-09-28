#include <stdio.h>
#include <stdlib.h>
#define A 100
#define OCUPADO 1
#define PHP 1
#define CS 2
#define VB 3
#include "alumnos.h"
#include "curso.h"

int main()
{
    eAlumno listaAlumnos[A];
    inicializarEstado(listaAlumnos,A);
    int opcion,flag,aux,i,j;
    char seguir = 's';

    eCurso misCursos[3];
    inicializarCursos(misCursos);
    // mostrarTodosLosCursos(misCursos,3);

    inicializarAlumnosConDatos(listaAlumnos,A);
    //  mostrarTodosLosAlumnos(listaAlumnos,A);

    while (seguir=='s')
    {
        system("cls");

        printf("Seleccione: \n 1_ Mostrar todos los alumnos.\n 2_ Mostrar los alumnos que cursan PHP.\n 3_ Mostrar cada curso con sus alumnos\n 4_ Salir\n");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            for (i=0; i<A; i++) // por cada alumno
            {
                if (listaAlumnos[i].estado == OCUPADO)
                {
                    printf ("%d---%s---%.2f---",listaAlumnos[i].legajo,
                                                listaAlumnos[i].nombre,
                                                listaAlumnos[i].promedio);
                    for (j=0; j<3; j++)
                    {
                        if(listaAlumnos[i].idCurso == misCursos[j].id)
                        {
                            printf("%s\n",misCursos[j].nombre);
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            system("cls");
            for (i=0; i<A; i++) // por cada alumno
            {
                if (listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].idCurso == PHP )
                {
                    printf ("%d---%s---%.2f---",listaAlumnos[i].legajo,
                                                listaAlumnos[i].nombre,
                                                listaAlumnos[i].promedio);
                    for (j=0; j<3; j++)
                    {
                        if(listaAlumnos[i].idCurso == misCursos[j].id)
                        {
                            printf("%s\n\n",misCursos[j].nombre);
                            break;
                        }
                    }
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n----ALUMNOS DE PHP----\n\n");
            for (i=0; i<A; i++) // por cada alumno
            {
                if (listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].idCurso == PHP )
                {
                    printf ("%d---%s---%.2f---\n",listaAlumnos[i].legajo,
                                                listaAlumnos[i].nombre,
                                                listaAlumnos[i].promedio);
                }
            }

            printf("\n----ALUMNOS DE C#----\n\n");
            for (i=0; i<A; i++) // por cada alumno
            {
                if (listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].idCurso == CS )
                {
                    printf ("%d---%s---%.2f---\n",listaAlumnos[i].legajo,
                                                listaAlumnos[i].nombre,
                                                listaAlumnos[i].promedio);
                }
            }

            printf("\n----ALUMNOS DE VB----\n\n");
            for (i=0; i<A; i++) // por cada alumno
            {
                if (listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].idCurso == VB )
                {
                    printf ("%d---%s---%.2f---\n",listaAlumnos[i].legajo,
                                                listaAlumnos[i].nombre,
                                                listaAlumnos[i].promedio);
                }
            }


            system("pause");
            break;
        case 4:
            seguir= 'n';
            break;
        default:
            printf("Seleccione una opcion correcta <1-4>");
        }
    }



    return 0;
}
