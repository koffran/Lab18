#include "Automovil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int initeAutos (eAuto* lista, int tam)
{
    int i,retorno = -1;

    if (lista !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            lista[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibreAuto(eAuto lista[],int tam)
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

int findeAutoById(eAuto* lista, int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaAutos (eAuto* lista, int i)
{
    char patente[7];
    int id_cliente, marca,id;

    printf("ingrese el ID del cliente: \n");
    scanf("%d",&id_cliente);

    printf("Ingrese la marca:\n1- ALPHA ROMEO\n2- FERRARI\n3- AUDI\n4- OTRO\n");
    scanf("%d",&marca);

    printf("ingrese la patente: \n");
    fflush(stdin);
    gets(patente);
    while(strlen(patente)!= 6)
    {
        printf("ERROR!! Ingrese la patente de 6 caracteres: \n");
        fflush(stdin);
        gets(patente);
    }

    id = i+1;

   if (addeAutos(lista,i,id,patente,marca,id_cliente)==0)
   {
       printf("Publicacion cargada\n");
   }

}

int addeAutos(eAuto* list, int indice, int id,char patente[],int marca,int id_cliente)
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id = id;
        strcpy(list[indice].patente,patente);
        list[indice].marca = marca;
        list[indice].isEmpty = ESTACIONADO;
        list[indice].id_cliente = id_cliente;
        returnAux = 0;
    }
    return returnAux;
}

int estacionarAuto(eAuto* lista,int indice)
{
    char rta;
    int retorno =0;

    printf("Desea estacionar este auto? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        lista[indice].isEmpty = ESTACIONADO;
        retorno = 1;
    }
    return retorno;
}

int retirarAuto (eAuto* lista,int indice)
{
    char rta;
    int retorno =0;
    float estadia;

   // printf("\n\nDesea Retirar este auto? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        lista[indice].isEmpty = NO_ESTACIONADO;
        retorno = 1;

        estadia = calcularEstadia(lista,indice);
        printf("VALOR DE LA ESTADIA : %.2f\n",estadia);
    }

    return retorno;
}

void imprimirMarca(int marca)
{

    switch(marca)
    {
    case 1:
        printf("ALPHA ROMEO");
        break;
    case 2:
        printf("FERRARI");
        break;
    case 3:
        printf("AUDI");
        break;
    case 4:
        printf("OTRO");
        break;
    }
}

float calcularEstadia(eAuto* lista,int indice)
{
    float retorno;
    int horas, aux;

    horas = 10;
    aux =lista[indice].marca;
    switch(aux)
    {
    case 1:
        retorno = horas * 150;
        break;
    case 2:
        retorno = horas * 175;
        break;
    case 3:
        retorno = horas * 200;
        break;
    case 4:
        retorno = horas * 250;
        break;
    }
    //printf("Horas totales de estacionamiento: %d",horas);
    return retorno;
}

void printeAuto(eAuto* list, int i)
{
    if (list[i].isEmpty == ESTACIONADO)
    {
        printf("%d\t\t\t%d\t\t%16s\t\n",list[i].id,list[i].id_cliente,list[i].patente);
    }
}

void printeAutos(eAuto* list, int length)
{
    int i;
    printf("ID DE AUTO\t\tID DE CLIENTE\t\tPATENTE\n");
    for (i=0; i<length; i++)
    {
        printeAuto(list,i);
    }
}

void printeAutosRetirados(eAuto* list, int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printf("ID DE AUTO\t\tID DE CLIENTE\t\tPATENTE\n");
        printeAutoRetirado(list,i);
    }
}
void printeAutoRetirado(eAuto* list, int i)
{
    if (list[i].isEmpty == NO_ESTACIONADO)
    {
       printf("%d\t\t%d\t\t%16s\t\n",list[i].id,list[i].id_cliente,list[i].patente);
    }
}

void hardcodeoAutos (eAuto autos[])
{
   strcpy(autos[0].patente,"car001");
   autos[0].isEmpty = 1;
   autos[0].id_cliente = 1;
   autos[0].id =1;
   autos[0].marca = 1;

   strcpy(autos[1].patente,"car002");
   autos[1].isEmpty = 1;
   autos[1].id_cliente = 2;
   autos[1].id =2;
   autos[1].marca = 2;

   strcpy(autos[2].patente,"car003");
   autos[2].isEmpty = 1;
   autos[2].id_cliente = 3;
   autos[2].id =3;
   autos[2].marca = 4;

   strcpy(autos[3].patente,"car004");
   autos[3].isEmpty = 1;
   autos[3].id_cliente = 4;
   autos[3].id =4;
   autos[3].marca = 3;

}

float recaudacionTotal(eAuto* lista_No_Estacionados,int tam)
{
    int i;
    float acumulador=0,auxFloat =0;
    for(i=0;i<tam;i++)
    {
        if(lista_No_Estacionados[i].isEmpty== NO_ESTACIONADO)
        {
            auxFloat = calcularEstadia(lista_No_Estacionados,i);
            acumulador += auxFloat;
        }
    }
    return acumulador;
}

float recaudacionPorMarca(eAuto* lista_No_Estacionados,int tam,int marca)
{
    int i;
    float acumulador=0,auxFloat =0;
    for(i=0;i<tam;i++)
    {
        if(lista_No_Estacionados[i].isEmpty== NO_ESTACIONADO && lista_No_Estacionados[i].marca == marca )
        {
            auxFloat = calcularEstadia(lista_No_Estacionados,i);
            acumulador += auxFloat;
        }
    }
    return acumulador;
}

int menuMarcas()
{
    int opcion;
   printf("De que marca desea la recaudacion total?\n\n1- ALPHA ROMEO\n2- FERRARI\n3- AUDI\n4- OTRO\n5- Salir");
    scanf("%d",&opcion);
    return opcion;
}

int sorteAutos(eAuto* lista, int tam, int order)
{
    int i,j,retorno =-1;
    eAuto aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty ==1 && order == 1)
                {
                    if(strcmp(lista[i].patente, lista[j].patente)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
                else
                {
                    if(lista[j].isEmpty ==1 && order == 0)
                {
                    if(strcmp(lista[i].patente, lista[j].patente)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
                }

            }
            retorno =0;
        }
    }
    return retorno;
}
