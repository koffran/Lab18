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

    printf("\n\nDesea Retirar este auto? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        lista[indice].isEmpty = NO_ESTACIONADO;
        retorno = 1;

     //   estadia = calcularEstadia(lista,indice);
     //   printf("VALOR DE LA ESTADIA : %.2f\n",estadia);
    }

    return retorno;
}

void imprimirMarca(int marca)
{
    char retorno[12];
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

/*float calcularEstadia(eAuto* lista,int indice)
{
    float retorno;
    int horas, aux;

    horas = calcularHoras();
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
    printf("Debe %d Horas",horas);
    return retorno;
}*/

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
       printf("%d\t\t%d\t\t%16s\t%s\n",list[i].id,list[i].id_cliente,list[i].patente);
    }
}
