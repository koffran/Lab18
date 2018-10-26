#include <stdio.h>
#include <stdlib.h>

/*  ARCHIVOS DE TEXTO.
    ESTRUCTURA FILE
*/
int main()
{
   /* FILE* pArchivo; //NO ES NECESARIO USAR MALLOC. FOPEN HACE TODO
    pArchivo = fopen("Texto.txt","w");  //Va al archivo y lo abre, devuelve la direccion de memoria. DOS STRINGS PATH , MODO.
                                        //DIRECCION DEL ARCHIVO Y EL MODO DE APERTURA (R/W)
                                        //Si no pongo ruta exacta,busco en el directorio del programa.
    fprintf(pArchivo,"HOLA\n");       //PARA ESCRIBIR TEXTO EN EL ARCHIVO
    fprintf(pArchivo,"Chau");                                                        //RECIBE EL ARCHIVO y una CADENA
                                                            //LE PODEMOS PASAR TRES PARAMETROS PARA CONCATENAR STRING CON UNA VARIABLE
    fclose(pArchivo); */   //CIERRA PARA QUE LO PUEDA USAR OTRA APP

    FILE* pArchivo;
    char p1[20];
    char p2[20];
    pArchivo = fopen("Texto.txt","r");



    fgets(p1,20,pArchivo);      // LEE UNA SOLA LINEA
    puts(p1);
    fgets(p2,20,pArchivo);      //ME PERMITE IR AL ARCHIVO Y LEER UNA CADENA. RECIBE 3 PARAM
    puts(p2);                   //Variable destino, tamaño y el archivo

    fclose(pArchivo);

    return 0;
}
