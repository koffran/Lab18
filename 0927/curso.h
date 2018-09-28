
typedef struct
{
    int id;
    char nombre [30];
    int duracion;
    char profesor [30];
}eCurso;

void inicializarCursos(eCurso*);
void mostrarCurso (eCurso);
void mostrarTodosLosCursos (eCurso*,int);
