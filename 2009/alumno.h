#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
typedef struct
{
    int legajo;
    char nombre[50];
    char direccion[50];
    int estado;
}eAlumno;

eAlumno cargarAlumno ();

int buscarEspacio (eAlumno[],int);

/** \brief Da de alta un alumno en listado
 *
 * \param el listado
 * \param el tamaño del listado
 * \return int  0 [si no encontro espacio]
                1 [Si encontro espacio]
 *
 */
int cargarAlumnoEnListado (eAlumno listado [], int tam); // ES UNA FUNCION DE CONTROL, LLAMA A OTRAS.

void mostrarListado (eAlumno[],int tam);
void inicializarAlumnos (eAlumno[],int,int);

int borrarAlumno (eAlumno[],int);
