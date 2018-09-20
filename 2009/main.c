#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#define TAM 20

int main()
{
    char seguir='s';
    int opcion=0,aux,dni;
    eAlumno lista[T];

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Hardcodeo\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                if (cargarAlumnoEnListado(lista,T))
                {
                    printf ("Datos cargados con exito\n");
                }
                else
                {
                    printf("No existe espacio disponible\n");
                }

                system("pause");
                break;
            case 2:
                system("cls");
                if (!borrarAlumno(lista,T))
                {
                    printf("Dato no encontrado");
                }

                system("pause");
                break;
            case 3:
                system("cls");

                system("pause");
                break;
            case 4:
                system("cls");

                system("pause");
                break;
            case 5:
                system("Pause");
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida <1-5>\n");
                system("Pause");
        }
    }

    return 0;
}
