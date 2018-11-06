#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
    char last_name[20];
}ePerson;

int main()
{
    ePerson* people = (ePerson*)malloc(sizeof(ePerson*)*11);
    int aux[11],
    i = 0;
    char ac[20];
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
            r = fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",ac,b,c);
            printf(" %s %s %s \n",ac,b,c);

            strcpy((people+i)->name,b);
            strcpy((people+i)->last_name,c);
            aux[i] = atoi(ac);
            (people+i)->id = aux[i];
            i++;
        }while(!feof(pArchivo));


        printf("\nARRAY: \n\n");
        for (i=0;i<11;i++)
        {
            printf("%d  %s  %s\n",(people+i)->id ,(people+i)->name,(people+i)->last_name);
        }
        fclose(pArchivo);
    }


    return 0;
}


/*void destructor (eEmployee* empleado) //delete
{
    free(empleado);
}

ll_remove(eEmployee* lista,int indice)*/
