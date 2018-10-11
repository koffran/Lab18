#include "informes.h"

/*Informar clientes:
a) Cliente con más avisos activos.
b) Cliente con más avisos pausados.
c) Cliente con más avisos*/

int masActivos (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones)
{
    int max = 0,contadorClientes;
    int i, j, flag =0;
    int indiceMayor;

    for (i=0; i<tam_clientes; i++)
    {
        contadorClientes=0;
        if(clientes[i].isEmpty == 1)
        {
            for(j=0; j<tam_publicaciones; j++)
            {
                if(publicaciones[j].id_cliente == clientes[i].id && publicaciones[j].isEmpty == ACTIVA)
                {
                    contadorClientes++;
                    if(flag == 0)
                    {
                        indiceMayor = i;
                        max = contadorClientes;
                        flag =1;
                    }
                    else
                    {
                        if(contadorClientes> max)
                        {
                            max = contadorClientes;
                            indiceMayor=i;
                        }
                    }
                }
            }

        }
    }
    printf("El cliente con mayor cantidad de publicaciones activas es el id: %d con %d publicaciones",clientes[indiceMayor].id,max);
}

int masPausados (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones)
{
    int max = 0,contadorClientes;
    int i, j, flag =0;
    int indiceMayor;

    for (i=0; i<tam_clientes; i++)
    {
        contadorClientes=0;
        if(clientes[i].isEmpty == 1)
        {
            for(j=0; j<tam_publicaciones; j++)
            {
                if(publicaciones[j].id_cliente == clientes[i].id && publicaciones[j].isEmpty == -1)
                {
                    contadorClientes++;
                    if(flag == 0)
                    {
                        indiceMayor = i;
                        max = contadorClientes;
                        flag =1;
                    }
                    else
                    {
                        if(contadorClientes> max)
                        {
                            max = contadorClientes;
                            indiceMayor=i;
                        }
                    }
                }
            }

        }
    }
    printf("El cliente con mayor cantidad de publicaciones pausadas es el id: %d con %d publicaciones",clientes[indiceMayor].id,max);
}

int masPublicaciones (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones)
{
    int max = 0,contadorClientes;
    int i, j, flag =0;
    int indiceMayor;

    for (i=0; i<tam_clientes; i++)
    {
        contadorClientes=0;
        if(clientes[i].isEmpty == 1)
        {
            for(j=0; j<tam_publicaciones; j++)
            {
                if(publicaciones[j].id_cliente == clientes[i].id)
                {
                    contadorClientes++;
                    if(flag == 0)
                    {
                        indiceMayor = i;
                        max = contadorClientes;
                        flag =1;
                    }
                    else
                    {
                        if(contadorClientes> max)
                        {
                            max = contadorClientes;
                            indiceMayor=i;
                        }
                    }
                }
            }

        }
    }
    printf("El cliente con mayor cantidad de publicaciones  es el id: %d con %d publicaciones",clientes[indiceMayor].id,max);
}






void mostrarPorRubro (ePublicacion* publicaciones, int tam_publicaciones)
{
    int i,contador=0,aux;
    printf("Que rubro desea ingresar?\n1- Rubro 1\nRubro 2\nRubro 3\n");
    scanf("%d",&aux);

    switch(aux)
    {
    case 1:
        system("cls");
        for (i=0; i<tam_publicaciones; i++)
        {
            if(publicaciones[i].isEmpty == 1 && publicaciones[i].rubro == 1)
            {
                contador++;
            }
        }
        printf("Rubro 1 tiene %d publicaciones activas\n",contador);
        system("pause");
        break;
    case 2:
        system("cls");
        for (i=0; i<tam_publicaciones; i++)
        {
            if(publicaciones[i].isEmpty == 1 && publicaciones[i].rubro == 2)
            {
                contador++;
            }
        }
        printf("Rubro 1 tiene %d publicaciones activas\n",contador);
        system("pause");
        break;
    case 3:
        system("cls");
        for (i=0; i<tam_publicaciones; i++)
        {
            if(publicaciones[i].isEmpty == 1 && publicaciones[i].rubro == 3)
            {
                contador++;
            }
        }
        printf("Rubro 1 tiene %d publicaciones activas\n",contador);
        system("pause");
        break;
    }
}

/*10) Informar publicaciones:

b) Rubro con más publicaciones activas.
c) Rubro con menos publicaciones activas.
*/
void RubroConMasPublicaciones (ePublicacion* publicaciones,int tam_publicaciones)
{
    int contador1=0,contador2=0,contador3=0;
    int i, flag =0;
    int min,max;

    for (i=0; i<tam_publicaciones; i++)
    {
        if(publicaciones[i].isEmpty == 1)
        {
            if(publicaciones[i].rubro == 1 )
            {
                contador1++;
            }
            else
            {
                if(publicaciones[i].rubro == 2)
                {
                    contador2++;
                }
                else
                {
                    if(publicaciones[i].rubro == 3)
                    {
                        contador3++;
                    }
                }
            }
        }
        }

    if(contador1 > contador2 && contador1 > contador3)
    {
        printf("El rubro con mas publicaciones activas es el rubro 1\n");
    }
    else
    {
        if(contador2> contador1 && contador2 > contador3)
        {
            printf("El rubro con mas publicaciones activas es el rubro 2\n");
        }
        else
        {
                if(contador3 > contador2 && contador3 > contador1)
            {
                printf("El rubro con mas publicaciones activas es el rubro 1\n");
            }
        }
    }

}
