#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED
#define PAUSADA -1
#define ACTIVA 1
typedef struct {
    char texto[65];
    int id_cliente;
    int rubro;
    int isEmpty;
    int id;
}ePublicacion;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initePublicacions (ePublicacion*,int);

/** \brief add in a existing list of ePublicacions the values received as parameters
 * in the first empty position
 * \param list ePublicacion*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param cuit int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addePublicacions(ePublicacion* list, int , int ,char [],int, int);


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void altaPublicaciones (ePublicacion *, int );

/** \brief Remove a ePublicacion by Id (put isEmpty Flag in 1)
 *
 * \param list ePublicacion*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a ePublicacion] - (0) if Ok
 *
 */
int pausarPublicacion (ePublicacion*,int);

/** \brief Sort the elements in the array of ePublicacions, the argument order
indicate UP or DOWN order
 *
 * \param list ePublicacion*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortePublicacions (ePublicacion* , int , int );

/** \brief print the content of ePublicacions array
 *
 * \param list ePublicacion*
 * \param length int
 * \return int
 *
 */
void printePublicacions (ePublicacion *,int );


/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeoPublicaciones (ePublicacion []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibrePub(ePublicacion lista[],int);

/** \brief find an ePublicacion by Id en returns the index position in array.
 *
 * \param list ePublicacion*
 * \param len int
 * \param id int
 * \return Return ePublicacion index position or (-1) if [Invalid length or NULL
pointer received or ePublicacion not found]
 *
 */
int findePublicacionById(ePublicacion* lista, int dni,int tam);



/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list ePublicacion*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printePublicacion(ePublicacion* list, int i);

/** \brief Permite modificar datos de un empleado
 *
 * \param El array
 * \param El tamaño del array
 * \param El ID del empleado a modificar
 * \return
 *
 */
void modificarPub (ePublicacion* lista, int tam, int id);

void printePublicacionPausada(ePublicacion* list, int i);
void printePublicacionsPausadas(ePublicacion* list, int length);

int reanudarPublicacion(ePublicacion* publicaciones,int indice);

#endif // FUNCIONES_H_INCLUDED
