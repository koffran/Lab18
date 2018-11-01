#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
    char surName[20];
}ePerson;

ePerson* nuevaPersona();

int main()
{
    ePerson* persona;
    persona = nuevaPersona();

    int a;
    char b[20];
    char c[20];
    int r;
    FILE* pArchivo;
    pArchivo = fopen("MOCK_DATA.csv","rb");
    if(pArchivo == NULL)
    {
        printf("EL archivo no existe");
    }
    else
    {
        do
        {
            r = fscanf(pArchivo,"%d,%[^,],%[^,]\n",&a,b,c);
            if(r==3)
            {
            printf(" %d %s %s \n",a,b,c);
            }

        }while(!feof(pArchivo));

    //    fread(&persona,sizeof(char),1,pArchivo);

        fclose(pArchivo);

       // printf("El int es : %d\nEl float es : %s\nEl char es : %s\n",persona->id,persona->name,persona->surName);
    }

    return 0;
}

ePerson* nuevaPersona()
{
    ePerson* persona;
    persona = (ePerson*)malloc(sizeof(ePerson));
    if (persona!= NULL)
    {
        persona->id = 0;
        strcpy(persona->name," ");
        strcpy(persona->surName," ");
    }
    return persona;
}
/*void destructor (eEmployee* empleado) //delete
{
    free(empleado);
}

ll_remove(eEmployee* lista,int indice)*/
