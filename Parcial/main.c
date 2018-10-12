#include <stdio.h>
#include <stdlib.h>
#include "propietarios.h"
#include "Automovil.h"
#include "informes.h"
#define CANT 20

int menu();


int main()
{
    int opcion,opcion2,flag=0,flag2=0,aux,aux2,i,j,indice;
    char seguir = 's',seguir2 = 's',rta;
    float auxFloat,acumulador =0;

    eCliente lista_clientes[CANT];
    initeClientes(lista_clientes,CANT);
    hardcodeo(lista_clientes);
    flag2 = 1;

    eAuto lista_autos[CANT];
    initeAutos(lista_autos,CANT);
    hardcodeoAutos(lista_autos);
    flag=1;

    eAuto lista_No_Estacionados[CANT];
    initeAutos(lista_No_Estacionados,CANT);


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
                    if(lista_clientes[indice].id_propietario == lista_autos[i].id_cliente&& lista_autos[i].isEmpty == ESTACIONADO)
                    {
                        printf("Tiene auto/s a retirar. Desea retirarlos?<s/n>\n");
                        retirarAuto(lista_autos,i);
                        aux2 = obtenerEspacioLibreAuto(lista_No_Estacionados,CANT);
                        lista_No_Estacionados[aux2].id = lista_autos[i].id;
                        lista_No_Estacionados[aux2].id_cliente = lista_autos[i].id_cliente;
                        lista_No_Estacionados[aux2].marca = lista_autos[i].marca;
                        lista_No_Estacionados[aux2].isEmpty = lista_autos[i].isEmpty;
                        strcpy(lista_autos[i].patente,lista_No_Estacionados[aux2].patente);
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
                            printf("Nombre  \t patente \t marca \t\n%5s\t%11s\t",lista_clientes[i].lastName,lista_autos[indice].patente);
                            imprimirMarca(lista_autos[indice].marca);
                            printf("\n\nDesea Retirar este auto? <S/N>\n");
                            if(retirarAuto(lista_autos,indice)== 0)
                            {
                                printf("No se retiro el auto\n");
                            }
                            else
                            {
                                printf("Auto retirado\n");

                                aux = obtenerEspacioLibreAuto(lista_No_Estacionados,CANT);
                                lista_No_Estacionados[aux].id = lista_autos[i].id;
                                lista_No_Estacionados[aux].id_cliente = lista_autos[i].id_cliente;
                                lista_No_Estacionados[aux].marca = lista_autos[i].marca;
                                lista_No_Estacionados[aux].isEmpty = lista_autos[i].isEmpty;
                                strcpy(lista_autos[i].patente,lista_No_Estacionados[aux].patente);
                            }
                        }
                    }
                }

            }
            system("pause");
            break;
        case 7:
            system("cls");
            printeAutos(lista_autos,CANT);

            system("pause");
            break;
        case 8:
            system("cls");
            auxFloat = recaudacionTotal(lista_No_Estacionados,CANT);
            printf("La recaudacion total es: %.2f\n", auxFloat);

            system("pause");
            break;
        case 9:
            system("cls");
            while(seguir2 == 's')
            {
                fflush(stdin);
                system("cls");
                opcion2 = menuMarcas();
                switch(opcion2)
                {
                case 1:
                    system("cls");
                    auxFloat = recaudacionPorMarca(lista_No_Estacionados,CANT,opcion2);
                    printf("La recaudacion total por ALPHA ROMEO es: %.2f\n",auxFloat);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    auxFloat = recaudacionPorMarca(lista_No_Estacionados,CANT,opcion2);
                    printf("La recaudacion total por FERRARI es: %.2f\n",auxFloat);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    auxFloat = recaudacionPorMarca(lista_No_Estacionados,CANT,opcion2);
                    printf("La recaudacion total por AUDI es: %.2f\n",auxFloat);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    auxFloat = recaudacionPorMarca(lista_No_Estacionados,CANT,opcion2);
                    printf("La recaudacion total por OTROS es: %.2f\n",auxFloat);
                    system("pause");
                    break;
                case 5:
                    seguir2='n';
                    break;
                }
            }

            system("pause");
            break;
        case 10:
            system("cls");
            datosCliente(lista_clientes,lista_autos, CANT);


            system("pause");
            break;
        case 11:
            system("cls");
            dueniosAudi(lista_clientes, lista_autos, CANT );
            system ("pause");
            break;
        case 12:
            system("cls");
            printf("Patentes en orden ascendente(1) o descendente(0)?\n");
            scanf("%d",&aux);
            sorteAutos(lista_autos, CANT,aux);
            autosEstacionadosConDatos(lista_clientes, lista_autos, CANT);
            system("pause");
            break;

        case 13:
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
    printf("1- Alta de cliente\n2- Modificar cliente\n3- Baja de cliente\n4- Listar clientes\n5- Cargar Auto \n6- Retirar auto \n7- Mostrar estacionados \n8- Recaudacion total \n9- Recaudacion por marca \n10- Cliente con sus autos \n11- Clientes con AUDI \n12 - Autos ordenados\n13- Salir\n");
    scanf("%d",&opcion);
    return opcion;
}


