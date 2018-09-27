typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion [50];
    int idCurso;
    int estado;
}eAlumno;

void mostrarTodosLosAlumnos (eAlumno* ,int );
void mostrarAlumno (eAlumno );
void inicializarAlumnosConDatos (eAlumno[], int );
void inicializarEstado (eAlumno* ,int );
