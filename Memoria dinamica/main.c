#include <stdio.h>
#include <stdlib.h>
#define T 5

int main()
{
    int i;
    int* vector;
    int* auxVector;

    vector = (int*)malloc(sizeof(int)*T);
    if (vector == NULL)
    {
        printf("No hay memoria");
    }
    else
    {
        printf(" ACA TENGO 10\n");
        for (i=0;i<T;i++)
        {
            *(vector+i) = i+1;
        }
        for (i=0;i<T;i++)
        {
           printf("%d\n", *(vector+i));
        }

        auxVector = realloc(vector,sizeof(int) * (T+5));
        if(auxVector != NULL)
        {
            vector = auxVector;
            for (i=T;i<T+5;i++)
            {
                *(vector+i) = i+1;
            }
            for (i=T;i<T+5;i++)
            {
                printf("%d\n", *(vector+i));
            }

            //PARA ACHICAR PODEMOS PISAR EL VECTOR

            vector = realloc(vector,sizeof(int)*3);
            printf("\n ACA TENGO 3 SOLAMENTE\n");
            for (i=0;i<3;i++)
            {
                printf("%d\n", *(vector+i));
            }

        }
        else
        {
            printf("No se encontro mas memoria");
        }
    }

    return 0;
}
