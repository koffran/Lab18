#include "publicaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int initePublicacions (ePublicacion* publicaciones, int tam)
{
    int i,retorno = -1;

    if (publicaciones !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            publicaciones[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibrePub(ePublicacion lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].isEmpty ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findePublicacionById(ePublicacion* lista, int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].id)
        {
            indice = i;
        }
    }
    return indice;
}

void altaPublicaciones (ePublicacion* lista, int i)
{
    char texto[65];
    int rubro, id, id_cliente;

    printf("ingrese el ID del cliente: \n");
    scanf("%d",&id_cliente);

    printf("Ingrese el rubro:\n1- Rubro 1\n2- Rubro 2\n3- rubro 3\n");
    scanf("%d",&rubro);

    printf("ingrese el texto del aviso: \n");
    fflush(stdin);
    gets(texto);

    id = i+1;

   if (addePublicacions(lista,i,id,texto,rubro,id_cliente)==0)
   {
       printf("Publicacion cargada\n");
   }

}

int addePublicacions(ePublicacion* list, int indice, int id,char texto[],int rubro,int id_cliente)
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id = id;
        strcpy(list[indice].texto,texto);
        list[indice].rubro = rubro;
        list[indice].isEmpty = 1;
        list[indice].id_cliente = id_cliente;
        returnAux = 0;
    }
    return returnAux;
}

int pausarPublicacion(ePublicacion* publicaciones,int indice)
{
    char rta;
    int retorno =0;

    printf("Desea poner esta publicacion en pausa? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        publicaciones[indice].isEmpty = PAUSADA;
        retorno = 1;
    }
    return retorno;
}

int reanudarPublicacion(ePublicacion* publicaciones,int indice)
{
    char rta;
    int retorno =0;

    printf("Desea REANUDAR esta publicacion? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        publicaciones[indice].isEmpty = ACTIVA;
        retorno = 1;
    }
    return retorno;
}

void printePublicacion(ePublicacion* list, int i)
{
    if (list[i].isEmpty == ACTIVA)
    {
        printf("ID de publicacion: %d\nID de cliente: %d\n",list[i].id,list[i].id_cliente);
        printf ("Publicacion: \n%s\n\n",list[i].texto);
    }
}

void printePublicacions(ePublicacion* list, int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printePublicacion(list,i);
    }
}

void printePublicacionsPausadas(ePublicacion* list, int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printePublicacionPausada(list,i);
    }
}
void printePublicacionPausada(ePublicacion* list, int i)
{
    if (list[i].isEmpty == PAUSADA)
    {
        printf("ID de publicacion: %d\nID de cliente: %d\n",list[i].id,list[i].id_cliente);
        printf ("Publicacion: \n%s\n\n",list[i].texto);
    }
}

int sortePublicacions (ePublicacion* lista, int tam, int order)
{
    int i,j,retorno =-1;
    ePublicacion aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty ==1 && order == 1)
                {
                    if(strcmp(lista[i].texto, lista[j].texto)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].texto, lista[j].texto)==0 && lista[i].rubro > lista[j].rubro)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                else
                {
                    if(lista[j].isEmpty ==1 && order == 0)
                {
                    if(strcmp(lista[i].texto, lista[j].texto)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].texto, lista[j].texto)==0 &&lista[i].rubro < lista[j].rubro)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                }

            }
            retorno =0;
        }
    }
    return retorno;
}

void modificarPub (ePublicacion* lista, int tam, int id)
{
    int rta;
    int indice;
    char seguir = 's';

    indice = findePublicacionById(lista,id,tam);

    if (indice == -1)
    {
         printf("No se encontro el ID ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                while (seguir == 's')
                {
                    system("cls");
                    printf("Apellido\t\tNombre\t\t\tid\t\trubro\n");
                    printePublicacion(lista,indice);
                    printf("Que dato desea modificar? \n1- Apellido\n2- Nombre\n3- rubro\n4- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        system("cls");
                        printf("Que apellido desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].texto);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Que nombre desea asignarle?\n");
                        fflush(stdin);


                        system("pause");
                        break;
                    case 3:
                         system("cls");
                        printf("Ingrese el rubro:\n");
                        scanf("%d",&lista[indice].rubro);
                        system("pause");
                        break;
                    case 4:
                        seguir = 'n';
                        break;
                    default:
                        printf("Ingrese una opcion valida <1-5>");
                        system("pause");
                    }
                }
            }
    }
}



void hardcodeoPublicaciones (ePublicacion personas[])
{
   strcpy(personas[0].texto,"Sanchez");
   personas[0].isEmpty = 1;
   personas[0].id =  1;
   personas[0].rubro =  1;

   strcpy(personas[1].texto,"Perez");
   personas[1].isEmpty = 1;
   personas[1].id = 2;
   personas[1].rubro =  2;

   strcpy(personas[2].texto,"Gomez");
   personas[2].isEmpty = 1;
   personas[2].id = 3;
   personas[2].rubro =  3;

   strcpy(personas[3].texto,"Gimenez");
   personas[3].isEmpty = 1;
   personas[3].id =4;
   personas[3].rubro =  1;

   strcpy(personas[4].texto,"Robled");
   personas[4].isEmpty = 1;
   personas[4].id = 5;
   personas[4].rubro =  1;

   strcpy(personas[5].texto,"Rodriguez");
   personas[5].isEmpty = 1;
   personas[5].id = 6;
   personas[5].rubro =  2;

   strcpy(personas[6].texto,"Gonzalez");
   personas[6].isEmpty = 1;
   personas[6].id = 7;
   personas[6].rubro =  3;

}
