#include "curso.h"

//SIGUIENTES TRES FUNCIONES, BASICAS PARA TODA ENTIDAD. HARDCODEO, MOSTRAR, MOSTRAROTDO
void inicializarCursos(eCurso* cursos)
{
    int id[3] = {1,2,3};
    char nombre [3][30] = {"PHP","C#","VB"};
    int duracion[3]={3,5,6};
    char profesor [3][30]={"Christian","Octavio","Maxi"};

    int i;
    for(i=0;i<3;i++)
    {
        cursos[i].id = id[i];
        cursos[i].duracion = duracion[i];
        strcpy(cursos[i].nombre,nombre[i]);
        strcpy(cursos[i].profesor,profesor[i]);
    }
}

void mostrarCurso (eCurso curso)
{
    printf ("%s----%s----%d\n",curso.nombre,curso.profesor,curso.duracion);
}


void mostrarTodosLosCursos (eCurso* cursos,int tam)
{
    int i;
     printf("\n-----CURSOS-----\n");
    for (i=0; i<tam; i++)
    {
        mostrarCurso(cursos[i]);
    }
}
