#include <stdio.h>
#include <stdlib.h>

        //MODO BINARIO

int main()
{
    int numero = 4;
    FILE* pArchivo;
    pArchivo = fopen("ArchivoBinario.dat","wb");

    fwrite(&numero,sizeof(int),1,pArchivo);//Par.  DIRECCION DE MEMORIA TAMAÑO DEL DATO, CANTIDAD DE DATOS, pArchivo
    fclose(pArchivo);

    pArchivo = fopen("ArchivoBinario.dat","rb");
    fread(&numero,sizeof(int),1,pArchivo);

    fclose(pArchivo);
    printf("El numero es : %d",numero);

    return 0;
}
