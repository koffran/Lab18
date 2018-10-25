#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>

//Encapsulamiento: Un objeto oculta al mundo exterior como hace para llevar a cabo un funcionamiento

int main()
{
    char name[30];
    ePersona* persona;
    persona = nuevaPersonaParametros(26,"Franco",1);

    mostrarPersona(persona);

    ePersona_setEdad(persona, 30 );
    ePersona_setName(persona,"MICAELA");
    strcpy(name,ePersona_getName(persona));

    printf("La edad es: %d\n",ePersona_getEdad(persona));
    printf("El id es: %d\n",ePersona_getId(persona));
    printf("El nombre es: %s\n",name);

    return 0;
}
