#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "publicaciones.h"
#include "informes.h"
#define CANT_CLIENTES 100
#define CANT_PUBLICACIONES 1000

int menu();

int main()
{
    int opcion,flag=0,aux,i,j,indice,contadorClientes=0;
    char seguir = 's',rta;

    eCliente lista_clientes [CANT_CLIENTES];
    initeClientes(lista_clientes,CANT_CLIENTES);

    ePublicacion lista_publicaciones [CANT_PUBLICACIONES];
    initePublicacions(lista_publicaciones,CANT_PUBLICACIONES);

    while (seguir == 's')
    {
        system("cls");
        opcion = menu();

        switch (opcion)
        {
        case 1: //1) Alta de cliente
            system("cls");
            aux = obtenerEspacioLibre(lista_clientes,CANT_CLIENTES);
            if (aux == -1)
            {
                printf("No hay espacio disponible");
            }
            else
            {
                altaCliente(lista_clientes,aux);
                printf("El ID es: %d\n\n",lista_clientes[aux].id);
            }
                flag = 1;
            system("pause");
            break;
        case 2: //Modificar datos de cliente
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                printeClientes(lista_clientes,CANT_CLIENTES);

                printf("\nIngrese el ID: ");
                scanf("%d",&aux);
                modificar(lista_clientes,CANT_CLIENTES,aux);
            }
            system("pause");
            break;
        case 3: //Baja de cliente:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                printeClientes(lista_clientes,CANT_CLIENTES);

                printf("\nIngrese el ID: ");
                scanf("%d",&aux);
                removeeCliente(lista_clientes,CANT_CLIENTES,aux);
            }
            system("pause");
            break;
        case 4: //Publicar:
            system("cls");
              if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                aux = obtenerEspacioLibrePub(lista_publicaciones,CANT_PUBLICACIONES);
                if (aux == -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    printeClientes(lista_clientes,CANT_CLIENTES);
                    altaPublicaciones(lista_publicaciones,aux);
                    printf("El ID es: %d\n\n",lista_publicaciones[aux].id);
                }
            }
            system("pause");
            break;
        case 5: //Pausar publicación:
            system("cls");
            printePublicacions(lista_publicaciones,CANT_PUBLICACIONES);

            printf("Introduzca el ID de la publicacion a pausar: \n");
            scanf("%d",&aux);
            indice = findePublicacionById(lista_publicaciones,aux,CANT_PUBLICACIONES);

            for (i=0;i<CANT_CLIENTES;i++)
            {
                if (lista_clientes[i].isEmpty==1)
                {
                   if(lista_publicaciones[indice].id_cliente == lista_clientes[i].id)
                    {
                        printf("Publicacion de: \n");
                        printeCliente(lista_clientes,i);
                        if(pausarPublicacion(lista_publicaciones,indice)== 0)
                        {
                            printf("No se pauso la publicacion\n");
                        }
                        else
                        {
                        printf("Publicacion pausada\n");
                        }
                    }
                }

            }
            system("pause");
            break;
        case 6: //Reanudar publicación:
            system("cls");
            printePublicacionsPausadas(lista_publicaciones,CANT_PUBLICACIONES);

            printf("Introduzca el ID de la publicacion a reanudar: \n");
            scanf("%d",&aux);
            indice = findePublicacionById(lista_publicaciones,aux,CANT_PUBLICACIONES);

            for (i=0;i<CANT_CLIENTES;i++)
            {
                if(lista_publicaciones[indice].id_cliente == lista_clientes[i].id)
                {
                    printf("Publicacion de: \n");
                    printeCliente(lista_clientes,i);
                    if(reanudarPublicacion(lista_publicaciones,indice)== 0)
                    {
                        printf("No se reanudo la publicacion\n");
                    }
                    else
                    {
                        printf("Publicacion reanudada\n");
                    }
                }
            }

            system("pause");
            break;
        case 7: //Imprimir Clientes:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                for (i=0;i<CANT_CLIENTES;i++)
                {
                    contadorClientes=0;
                    if(lista_clientes[i].isEmpty == 1)
                    {
                      printf("Nombre: %s\nCUIT: %d\nID: %d\n ",lista_clientes[i].name,lista_clientes[i].cuit,lista_clientes[i].id);


                        for(j=0;j<CANT_PUBLICACIONES;j++)
                        {
                            if(lista_publicaciones[j].id_cliente == lista_clientes[i].id && lista_publicaciones[j].isEmpty == ACTIVA)
                            {
                                contadorClientes++;
                            }
                        }
                        printf("Cantidad de publicaciones activas:%d\n\n ",contadorClientes);
                    }
                }
            }
            system("pause");
            break;
        case 8: //Imprimir publicaciones:
            system("cls");
            for(i=0;i<CANT_PUBLICACIONES;i++)
            {
                for(j=0;j<CANT_CLIENTES;j++)
                {
                    if(lista_publicaciones[i].isEmpty == ACTIVA && lista_clientes[j].isEmpty == 1)
                    {
                        if(lista_publicaciones[i].id_cliente == lista_clientes[j].id)
                        {
                          printf("ID de la publicacion: %d\nRubro: %d\nTexto: %s\nCUIT del cliente: %d\n\n",lista_publicaciones[i].id,lista_publicaciones[i].rubro,lista_publicaciones[i].texto,lista_clientes[j].cuit);
                        break;
                        }
                    }
                }
            }
            system("pause");
            break;
        case 9: //Informar clientes:
            system("cls");
             masActivos (lista_clientes,CANT_CLIENTES,lista_publicaciones,CANT_PUBLICACIONES);
             printf("\n\n");
             masPausados (lista_clientes,CANT_CLIENTES,lista_publicaciones,CANT_PUBLICACIONES);
             printf("\n\n");
             masPublicaciones (lista_clientes,CANT_CLIENTES,lista_publicaciones,CANT_PUBLICACIONES);
            system("pause");
            break;
        case 10: //Informar publicaciones:
            system("cls");


            mostrarPorRubro (lista_publicaciones,CANT_PUBLICACIONES);
            RubroConMasPublicaciones(lista_publicaciones,CANT_PUBLICACIONES);

            system("pause");
            break;
        case 11:
            hardcodeo(lista_clientes);
            flag =1;
            break;
        case 12:
            system("cls");
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("\nIngrese una opcion valida <1-12>\n");
            system("pause");
        }
    }

    return 0;
}

int menu()
{
    int opcion;
    printf("1- Alta de cliente\n2- Modificar cliente\n3- Baja de cliente\n4- Publicar\n5- Pausar publicacion\n6- Reanudar publicacion\n7- Imprimir clientes\n8- Imprimir publicaciones\n9- Informar clientes\n10- Informar publicaciones\n11- Hardcodeo\n12- Salir\n");
    scanf("%d",&opcion);
    return opcion;
}


