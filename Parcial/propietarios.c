#include "propietarios.h"
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
        if (id == lista[i].id_propietario && lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaCliente (eCliente* lista, int i)
{
    char name [51],lastName[51],direccion[51],tarjeta[17];
    int id;

    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(name);

    printf("ingrese el apellido: \n");
    fflush(stdin);
    gets(lastName);

    printf("ingrese el direccion: \n");
    fflush(stdin);
    gets(direccion);

    printf("ingrese la tarjeta: \n");
    fflush(stdin);
    gets(tarjeta);
    while(strlen(tarjeta)!= 16)
    {
        printf("ERROR!! Ingrese el numero de  tarjeta de 16 digitos: \n");
        fflush(stdin);
        gets(tarjeta);
    }

    id = i+1;

   if (addeClientes(lista,i,id,name,lastName,direccion,tarjeta)==0)
   {
       printf("Empleado cargado\n");
   }

}

int addeClientes(eCliente* list, int indice, int id, char name[],char lastName[],char direccion[], char tarjeta[])
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id_propietario = id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        strcpy(list[indice].tarjeta,tarjeta);
        strcpy(list[indice].direccion,direccion);

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
                printf("Nombre\tid\n %s\t \t %d\n",lista[indice].name,lista[indice].id_propietario);
                printf("Desea eliminarlo? <S/N>\n");
                fflush(stdin);
                rta = getche();
                rta = tolower(rta);

                if ( rta == 's')
                {
                    lista[indice].isEmpty = 0;
                    printf("\ Cliente eliminado\n\n");
                }
            }
    }
}

void printeCliente(eCliente* list, int i)
{
  if (list[i].isEmpty == 1)
  {
    printf("%s\t\t%10s\t%16s\t%d\n",list[i].lastName,list[i].name,list[i].tarjeta,list[i].id_propietario);
  }
}

void printeClientes(eCliente* list, int length)
{
    int i;
    printf("Apellido\t\tNombre\tNumero de tarjeta\tID\n");
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
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 && strcmp(lista[i].name, lista[j].name)>0)
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
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 &&strcmp(lista[i].lastName, lista[j].lastName)<0)
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
    char tarjeta[17];
    char seguir = 's';
    char confirmar;

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
                    printf("Apellido\t\tNombre\t\tNumero de tarjeta\tID\n");
                    printeCliente(lista,indice);
                    printf("\n1- Modificar numero de tarjeta\n2- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        system("cls");
                        printf("ingrese la tarjeta: \n");
                        fflush(stdin);
                        gets(tarjeta);
                        while(strlen(tarjeta)!= 16)
                        {
                            printf("ERROR!! Ingrese el numero de  tarjeta de 16 digitos: \n");
                            fflush(stdin);
                            gets(tarjeta);
                        }

                        printf("El nuevo numero es: %s\nEs correcto? <s/n>",tarjeta);
                        fflush(stdin);
                        scanf("%c",&confirmar);
                        confirmar = tolower(confirmar);
                        if (confirmar == 's')
                        {
                            strcpy(lista[indice].tarjeta,tarjeta);
                        }
                        else
                        {
                            printf("No se realizo el cambio\n");
                            fflush(stdin);
                        }
                        system("pause");
                        break;
                    case 2:
                        seguir = 'n';
                        break;
                    default:
                        printf("Ingrese una opcion valida <1-2>");
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
   strcpy(personas[0].direccion,"Direccion 1");
   strcpy(personas[0].tarjeta,"1000100010001000");
   personas[0].isEmpty = 1;
   personas[0].id_propietario = 1;


   strcpy(personas[1].name,"Paula");
   strcpy(personas[1].lastName,"Perez");
   strcpy(personas[1].direccion,"Direccion 2");
   strcpy(personas[1].tarjeta,"1001100110011001");
   personas[1].isEmpty = 1;
   personas[1].id_propietario = 2;

   strcpy(personas[2].name,"Pablo");
   strcpy(personas[2].lastName,"Gomez");
   strcpy(personas[2].direccion,"Direccion 3");
   strcpy(personas[2].tarjeta,"1002100210021002");
   personas[2].isEmpty = 1;
   personas[2].id_propietario = 3;

   strcpy(personas[3].name,"Micaela");
   strcpy(personas[3].lastName,"Gimenez");
   strcpy(personas[3].direccion,"Direccion 4");
   strcpy(personas[3].tarjeta,"1003100410051006");
   personas[3].isEmpty = 1;
   personas[3].id_propietario =4;

   strcpy(personas[4].name,"German");
   strcpy(personas[4].lastName,"Robled");
   strcpy(personas[4].direccion,"Direccion 5");
   strcpy(personas[4].tarjeta,"1000100010031004");
   personas[4].isEmpty = 1;
   personas[4].id_propietario = 5;

   strcpy(personas[5].name,"Esteban");
   strcpy(personas[5].lastName,"Rodriguez");
   strcpy(personas[5].direccion,"Direccion 6");
   strcpy(personas[5].tarjeta,"1000100000031004");
   personas[5].isEmpty = 1;
   personas[5].id_propietario = 6;

   strcpy(personas[6].name,"Cecilia");
   strcpy(personas[6].lastName,"Gonzalez");
   strcpy(personas[6].direccion,"Direccion 7");
   strcpy(personas[6].tarjeta,"1001100210031004");
   personas[6].isEmpty = 1;
   personas[6].id_propietario = 7;


}
