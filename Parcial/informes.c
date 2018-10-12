 #include"informes.h"

 void datosCliente(eCliente* clientes,eAuto* autos, int tam)
 {
     int id,indiceCliente,i;

        printeClientes(clientes,tam);
    printf("Ingrese el ID del cliente:\n");
    scanf("%d",&id);

     indiceCliente = findeClienteById(clientes,id,tam);

     printf("NOMBRE\tPATENTE\tMARCA\n\n");
     printf("%s\t",clientes[indiceCliente].name);

     for(i=0;i<tam;i++)
     {
         if(autos[i].isEmpty== ESTACIONADO && autos[i].id_cliente == clientes[indiceCliente].id_propietario)
         {
             printf("%s \t ",autos[i].patente);
             imprimirMarca(autos[i].marca);
             printf("\n\t");
         }
     }
 }

//Todos los datos de los propietarios cuyos autos estacionados sean de la marca AUDI.

void dueniosAudi(eCliente* clientes, eAuto* autos, int tam)
{
    int i, j;
    printf("\t\tClientes con AUDIS\n\n");
    printf("Apellido\t\tNombre\t\tNumero de tarjeta\tID\n");

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(autos[i].marca == AUDI && autos[i].isEmpty== ESTACIONADO)
            {
                if(autos[i].id_cliente == clientes[j].id_propietario)
                {
                    printeCliente(clientes,j);
                    break;
                }

            }
        }

    }
}

//12.	 autos estacionados,  datos de  sus propietarios, ordenado por patente.
void autosEstacionadosConDatos(eCliente* clientes, eAuto* autos, int tam)
{
    int i,j;

    printf("PATENTE\t\tApellido\t\tNombre\tNumero de tarjeta\tID\n\n");

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(autos[i].isEmpty == ESTACIONADO && autos[i].id_cliente == clientes[j].id_propietario)
            {
                printf("%s\t\t",autos[i].patente);
                printeCliente(clientes,j);
            }
        }
    }

}
