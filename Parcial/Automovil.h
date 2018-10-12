#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED
#define ESTACIONADO 1
#define NO_ESTACIONADO 2
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4
typedef struct {
    char patente[7];
    int id_cliente;
    int marca;
    int isEmpty;
    int id;
}eAuto;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initeAutos (eAuto*,int);

/** \brief add in a existing list of eAutos the values received as parameters
 * in the first empty position
 * \param list eAuto*
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
int addeAutos(eAuto* list, int , int ,char [],int, int);


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void altaAutos (eAuto *, int );

/** \brief Remove a eAuto by Id (put isEmpty Flag in 1)
 *
 * \param list eAuto*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a eAuto] - (0) if Ok
 *
 */
int estacionarAuto (eAuto*,int);


/** \brief print the content of eAutos array
 *
 * \param list eAuto*
 * \param length int
 * \return int
 *
 */
void printeAutos (eAuto *,int );

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibreAuto(eAuto lista[],int);

/** \brief find an eAuto by Id en returns the index position in array.
 *
 * \param list eAuto*
 * \param len int
 * \param id int
 * \return Return eAuto index position or (-1) if [Invalid length or NULL
pointer received or eAuto not found]
 *
 */
int findeAutoById(eAuto* lista, int dni,int tam);



/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list eAuto*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printeAuto(eAuto* list, int i);

/** \brief Imprime por pantalla un auto retirado
 *
 * \param list eAuto* el array
 * \param i int El indice del auto deseado
 * \return void
 *
 */
void printeAutoRetirado(eAuto* list, int i);

/** \brief Imprime todos los autos de un array
 *
 * \param list eAuto* el array a imprimir
 * \param length int el tamaño del array
 * \return void
 *
 */
void printeAutosRetirados(eAuto* list, int length);

/** \brief Retira un auto del estacionamiento pasando su estado a NO ESTACIONADO
 *
 * \param  eAuto* el array
 * \param indice int el indice del auto a retirar
 * \return int Retorna  0 si hay algun error
 *                      1 Si se retira correctamente
 */
int retirarAuto(eAuto* ,int indice);

/** \brief Recibe un numero y muestra la marca correcta en texto
 *
 * \param marca int La marca, en numero
 * \return void
 *
 */
void imprimirMarca(int marca);

/** \brief Calcula el valor de la estadia
 *
 * \param lista eAuto* El array donde  buscar
 * \param indice int El indice para el que se quiere calcular
 * \return float El monto final
 *
 */
float calcularEstadia(eAuto* lista,int indice);

/** \brief Hardcodea datos para autos estaionados
 *
 * \param la lista a hardcodear
 * \return
 *
 */
void hardcodeoAutos (eAuto autos[]);

/** \brief La recaudacion de todos los autos retirados
 *
 * \param lista_No_Estacionados eAuto* la lista de autos retirados
 * \param tam int el tamaño del array
 * \return float El valor de la recaudacion total
 *
 */
float recaudacionTotal(eAuto* lista_No_Estacionados,int tam);

/** \brief La recaudacion por marca
 *
 * \param lista_No_Estacionados eAuto* Lista de autos retirados
 * \param tam int El tamaño del array
 * \param marca int La marca a calcular
 * \return float La recaudacion final para la marca seleccionada
 *
 */
float recaudacionPorMarca(eAuto* lista_No_Estacionados,int tam,int marca);
int menuMarcas();
int sorteAutos(eAuto* lista, int tam, int order);
#endif // FUNCIONES_H_INCLUDED
