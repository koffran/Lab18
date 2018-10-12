#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char name[51];
    char lastName[51];
    char direccion[51];
    int isEmpty;
    int id_propietario;
    char tarjeta[51];
}eCliente;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initeClientes (eCliente*,int);

/** \brief add in a existing list of eClientes the values received as parameters
 * in the first empty position
 * \param list eCliente*
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
int addeClientes(eCliente* list, int , int , char [],char [],char[], char[] );


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void altaCliente (eCliente *, int );

/** \brief Remove a eCliente by Id (put isEmpty Flag in 1)
 *
 * \param list eCliente*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a eCliente] - (0) if Ok
 *
 */
void removeeCliente (eCliente*,int, int );

/** \brief Sort the elements in the array of eClientes, the argument order
indicate UP or DOWN order
 *
 * \param list eCliente*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sorteClientes (eCliente* , int , int );

/** \brief print the content of eClientes array
 *
 * \param list eCliente*
 * \param length int
 * \return int
 *
 */
void printeClientes (eCliente *,int );


/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeo (eCliente []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(eCliente lista[],int);

/** \brief find an eCliente by Id en returns the index position in array.
 *
 * \param list eCliente*
 * \param len int
 * \param id int
 * \return Return eCliente index position or (-1) if [Invalid length or NULL
pointer received or eCliente not found]
 *
 */
int findeClienteById(eCliente* lista, int dni,int tam);



/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list eCliente*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printeCliente(eCliente* list, int i);

/** \brief Permite modificar datos de un empleado
 *
 * \param El array
 * \param El tamaño del array
 * \param El ID del empleado a modificar
 * \return
 *
 */
void modificar (eCliente* lista, int tam, int id);



#endif // FUNCIONES_H_INCLUDED
