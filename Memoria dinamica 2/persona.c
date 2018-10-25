#include "persona.h"
#include <stdlib.h>
#include <string.h>

ePersona* nuevaPersona()
{
    ePersona* persona;
    persona = (ePersona*)malloc(sizeof(ePersona));
    if (persona!= NULL)
    {
        persona->edad = 0;
        persona->id = 0;
        strcpy(persona->name," ");
    }

    return persona;
}

ePersona* nuevaPersonaParametros(int edad, char* nombre, int id)
{
    ePersona* persona;
    persona = nuevaPersona();
    if (persona!= NULL)
    {
        persona->edad = edad;
        persona->id = id;
        strcpy(persona->name,nombre);
    }

    return persona;
}

void mostrarPersona(ePersona* p)
{
    printf("%s---%d--%d\n",p->name,p->edad,p->id);
}

int ePersona_getEdad(ePersona* persona)
{
    int edad;
    edad = persona->edad;

    return edad;
}

int ePersona_getId(ePersona* persona)
{
    int id;
    id = persona->id;

    return id;
}

char* ePersona_getName(ePersona* persona)
{
   /* int length;
    length = strlen(persona->name);*/
    char nombre;
    strcpy(nombre,"FRAN");

    return nombre;
}
