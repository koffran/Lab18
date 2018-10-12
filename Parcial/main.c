#include <stdio.h>
#include <stdlib.h>
#include "propietarios.h"
#include "Automovil.h"
#define CANT 20

int menu();

int main()
{
    int opcion,flag=0,flag2=0,aux,i,j,indice;
    char seguir = 's',rta;

    eCliente lista_clientes[CANT];
    initeClientes(lista_clientes,CANT);

    eAuto lista_autos[CANT];
    initeAutos(lista_autos,CANT);


    while (seguir == 's')
    {
        system("cls");
        opcion = menu();

        switch (opcion)
        {
        case 1:
            system("cls");

            aux = obtenerEspacioLibre(lista_clientes,CANT);
            if (aux == -1)
            {
                printf("No hay espacio disponible");
            }
            else
            {
                altaCliente(lista_clientes,aux);
                printf("El ID es: %d\n\n",lista_clientes[aux].id_propietario);
            }
            flag = 1;
            system("pause");
            break;
        case 2:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                printeClientes(lista_clientes,CANT);

                printf("\nIngrese el ID: ");
                scanf("%d",&aux);
                modificar(lista_clientes,CANT,aux);
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                printeClientes(lista_clientes,CANT);

                printf("\nIngrese el ID: ");
                scanf("%d",&aux);

                indice = findeClienteById(lista_clientes,aux,CANT);

                for(i=0;i<CANT;i++)
                {
                    if(lista_clientes[indice].id_propietario == lista_autos[i].id_cliente)
                    {
                        retirarAuto(lista_autos,i);
                    }
                }

                removeeCliente(lista_clientes,CANT,aux);
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                sorteClientes(lista_clientes,CANT,1);
                printeClientes(lista_clientes,CANT);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                aux = obtenerEspacioLibreAuto(lista_autos,CANT);
                if (aux == -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    printeClientes(lista_clientes,CANT);
                    altaAutos(lista_autos,aux);
                    printf("El ID es: %d\n\n",lista_autos[aux].id);
                }
                flag2=1;
            }

            system("pause");
            break;
        case 6:
            system("cls");
            if (flag2 ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                printeAutos(lista_autos,CANT);

                printf("Introduzca el ID del auto a retirar: \n");
                scanf("%d",&aux);
                indice = findeAutoById(lista_autos,aux,CANT);

                for (i=0;i<CANT;i++)
                {
                    if(lista_clientes[i].isEmpty==1)
                    {
                        if(lista_clientes[i].id_propietario == lista_autos[indice].id_cliente)
                        {
                            printf("Nombre  \t patente \t marca \t valor de la estadia\n%5s\t%11s\t",lista_clientes[i].lastName,lista_autos[indice].patente);
                            imprimirMarca(lista_autos[indice].marca);
                            if(retirarAuto(lista_autos,indice)== 0)
                            {
                                printf("No se retiro el auto\n");
                            }
                            else
                            {
                                printf("Auto retirado\n");
                            }
                        }
                    }

                }

            }


            system("pause");
            break;
        case 7: //Imprimir Clientes:
            system("cls");

            system("pause");
            break;
        case 8: //Imprimir publicaciones:
            system("cls");

            system("pause");
            break;
        case 9: //Informar clientes:
            system("cls");

            system("pause");
            break;
        case 10: //Informar publicaciones:
            system("cls");
            printeAutos(lista_autos,CANT);

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
    printf("1- Alta de cliente\n2- Modificar cliente\n3- Baja de cliente\n4- Listar clientes\n5- Cargar Auto \n6- Retirar auto \n7-  \n8-  \n9-  \n10- Mostrar estacionados \n11- Hardcodeo\n12- Salir\n");
    scanf("%d",&opcion);
    return opcion;
}
