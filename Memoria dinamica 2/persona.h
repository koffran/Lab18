typedef struct
{
    int edad;
    int id;
    char name[30];
}ePersona;

ePersona* nuevaPersona();
ePersona* nuevaPersonaParametros(int , char* , int );

int ePersona_getEdad(ePersona*);
int ePersona_getId(ePersona* );
char* ePersona_getName(ePersona* );

void mostrarPersona(ePersona* );
