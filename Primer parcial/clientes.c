#include "clientes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int initeClientes (eCliente* clientes, int tam)
{
    int i,retorno = -1;

    if (clientes !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            clientes[i].isEmpty = 0;
            clientes[i].publicaciones=0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibre(eCliente lista[],int tam)
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

int findeClienteById(eCliente* lista, int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].id && lista[i].isEmpty == 1)
        {
            indice = i;
        }
    }
    return indice;
}

void altaCliente (eCliente* lista, int i)
{
    char name [51],lastName[51];
    int cuit, id;

    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(name);

    printf("ingrese el apellido: \n");
    fflush(stdin);
    gets(lastName);

    printf("Ingrese el cuit:\n");
    scanf("%d",&cuit);

    id = i+1;

   if (addeClientes(lista,i,id,name,lastName,cuit)==0)
   {
       printf("Empleado cargado\n");
   }

}

int addeClientes(eCliente* list, int indice, int id, char name[],char lastName[],int cuit)
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id = id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].cuit = cuit;
        list[indice].isEmpty = 1;
        returnAux = 0;
    }
    return returnAux;
}

void removeeCliente (eCliente* lista, int len,int id)
{
    char rta;
    int indice;

    indice = findeClienteById(lista,id,len);

    if (indice == -1)
    {
         printf("No se encontro el ID ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                printf("Nombre\tid\n %s\t \t %d\n",lista[indice].name,lista[indice].id);
                printf("Desea eliminarlo? <S/N>\n");
                fflush(stdin);
                rta = getche();
                rta = tolower(rta);

                if ( rta == 's')
                {
                    lista[indice].isEmpty = 0;
                    printf("\Cliente eliminado\n\n");
                }
            }
    }
}

void printeCliente(eCliente* list, int i)
{
  if (list[i].isEmpty == 1)
  {
    printf("%s\t\t%10s\t\t%10d\t\t%7d\t%d\n",list[i].lastName,list[i].name,list[i].id,list[i].cuit,list[i].publicaciones);
  }
}

void printeClientes(eCliente* list, int length)
{
    int i;
    printf("Apellido\t\tNombre\t\t\tid\t\tcuit\tCantidad de publicaciones\n");
    for (i=0; i<length; i++)
    {
        printeCliente(list,i);
    }
}


int sorteClientes (eCliente* lista, int tam, int order)
{
    int i,j,retorno =-1;
    eCliente aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty ==1 && order == 1)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].cuit > lista[j].cuit)
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
                    if(strcmp(lista[i].lastName, lista[j].lastName)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 &&lista[i].cuit < lista[j].cuit)
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

void modificar (eCliente* lista, int tam, int id)
{
    int rta;
    int indice;
    char seguir = 's';

    indice = findeClienteById(lista,id,tam);

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
                    printf("Apellido\t\tNombre\t\t\tid\t\tcuit\n");
                    printeCliente(lista,indice);
                    printf("Que dato desea modificar? \n1- Apellido\n2- Nombre\n3- cuit\n4- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        system("cls");
                        printf("Que apellido desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].lastName);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Que nombre desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].name);

                        system("pause");
                        break;
                    case 3:
                         system("cls");
                        printf("Ingrese el cuit:\n");
                        scanf("%d",&lista[indice].cuit);
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



void hardcodeo (eCliente personas[])
{
   strcpy(personas[0].name,"Juan");
   strcpy(personas[0].lastName,"Sanchez");
   personas[0].isEmpty = 1;
   personas[0].id =  1;
   personas[0].cuit =  1;

   strcpy(personas[1].name,"Paula");
   strcpy(personas[1].lastName,"Perez");
   personas[1].isEmpty = 1;
   personas[1].id = 2;
   personas[1].cuit =  2;

   strcpy(personas[2].name,"Pablo");
   strcpy(personas[2].lastName,"Gomez");
   personas[2].isEmpty = 1;
   personas[2].id = 3;
   personas[2].cuit =  3;

   strcpy(personas[3].name,"Micaela");
   strcpy(personas[3].lastName,"Gimenez");
   personas[3].isEmpty = 1;
   personas[3].id =4;
   personas[3].cuit =  4;

   strcpy(personas[4].name,"German");
   strcpy(personas[4].lastName,"Robled");
   personas[4].isEmpty = 1;
   personas[4].id = 5;
   personas[4].cuit =  5;

   strcpy(personas[5].name,"Esteban");
   strcpy(personas[5].lastName,"Rodriguez");
   personas[5].isEmpty = 1;
   personas[5].id = 6;
   personas[5].cuit =  6;

   strcpy(personas[6].name,"Cecilia");
   strcpy(personas[6].lastName,"Gonzalez");
   personas[6].isEmpty = 1;
   personas[6].id = 7;
   personas[6].cuit =  7;

}
