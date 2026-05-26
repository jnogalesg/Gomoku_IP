/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 23/24

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto Gomoku
	     	 	 encargado del manejo de la interfaz del juego.
	     	 	 Versión allegro 5.2
	Autor:	Profesores de las asignaturas
    Fecha:	22/11/2023
*/

#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <iostream>
#include <string>

using namespace std;


// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------

/*
 *  La constante MAX_TAMANO define el tamaño máximo (número de filas y columas) del tablero
 */
const int MAX_TAMANO = 20;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir, TF1, TF2};


// ----------------------------------------------------------------
// Declaración de la interfaz pública (módulos que se pueden usar)
// ----------------------------------------------------------------


 /*
  *	PRE:  5 <= tam <= MAX_TAMANO
  *	DESCRIPCIÓN: Inicia la interfaz gráfica del juego, preparada para
  *		  un tablero de tam x tam casillas (intersecciones).
  */
void entornoIniciar (int tam);

 /*
  *	DESCRIPCIÓN: Libera los recursos usados por el entorno gráfico
  */
void entornoTerminar ();


/*
 *	PRE: Archivo gomoku.cnf correcto y en la carpeta raíz del proyecto
 *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
 *	POST: Devuelve:
 *	        TRUE:  si se carga correctamente la configuración del juego,
 *		    FALSE: en caso contrario.
 *   PARÁMETROS DE SALIDA:
 *		Si la configuración se lee de forma correcta se devolverá:
 *		   tam:		     	 tamaño del tablero (número de filas y columnas)
 *		   turno:            devuelve el color que inicia el juego (0 = negra, 1 = blanca)
 *		   nLinea:           Número de piezas en línea para ganar
 *		   nPiezas:			 Número de piezas para cada jugador
 *
 *		Por omisión, el archivo gomoku.cnf se encuentra en el directorio  del proyecto
 */
bool entornoCargarConfiguracion (int &tam,  int &turno,int &nLinea, int &nPiezas);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *      { 0 = negra, 1 = blanca}
 *
 * DESCRIPCIÓN: Coloca en la posición (fila,columna) del tablero una pieza del color indicado
*/
void entornoPonerPieza (int fila, int columna, int color);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Enmarca la casilla que ocupa la posición (fila, columna) en un círculo rojo
 *       Se utiliza para simular el movimiento del cursor por el tablero
 */
void entornoMarcarPosicion (int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Elimina el círculo rojo de la casilla que ocupa la posición (fila, columna)
 *       Se utiliza para simular el movimiento del cursor por el tablero
*/
void entornoDesmarcarPosicion (int fila, int columna);



/*
 * PRE: { 0 <= color <= 1}
 *
 * DESCRIPCIÓN: Muestra el color del turno en la parte superior del tablero
 *              Si color es 0, muestra Negro; si es 1, muestra Blanco
 */
void entornoMarcadorTurno (int color);

/*
 * PRE: { }
 *
 * POST:Devuelve el valor enumerado de TipoTecla que corresponde a la tecla que se haya pulsado
 */
TipoTecla entornoLeerTecla();


/*
 * PRE: "msg" está correctamente inicializado
 *
 * DESCRIPCIÓN: Muestra el mensaje "msg" en el centro de la ventana para indicar que ha finalizado el juego
 */
void entornoMostrarMensajeFin (string msg);


/*
 * PRE: {0 < pausa}
 *
 * DESCRIPCIÓN: para la ejecución durante "pausa" segundos
 */
void entornoPausa(float pausa);



/*****************************************/
// Módulos para las ampliaciones
/*****************************************/

/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 *
 * DESCRIPCIÓN: Quita en la posición (fila,columna) del tablero una pieza del color indicado
*/
void entornoQuitarPieza (int fila, int columna);

/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO
 *        pausa > 0}
 *
 * DESCRIPCIÓN: Enmarca la casilla que ocupa la posición (fila, columna) en un círculo azul,
 *              durante el tiempo que "pausa"
 * 	            Se utiliza en la ayuda para marca la celda donde se puede colocar una pieza
 */
void entornoMarcarAyuda     ( int fila, int columna, int pausa);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Enmarca en un recuadro rojo la casilla indicada
 */
void entornoMarcarLinea (int fila, int columna);


/*
 * PRE: { numNegras >= 0, numBlancas >= 0}
 *
 * DESCRIPCIÓN: Muestra el número de piezas que le quedan a cada jugador,
 *              en el marcador situado en la parte inferior del tablero
*/
void entornoMarcadorNumPiezas(int numNegras, int numBlancas);

// TODO  Yo quitaría esta función- SEGURO SE QUITA ESTA AMPLIACIÓN??
/*
 *	PRE: tam: tamaño actual del tablero, antes que sea añanda la nueva fila y columna
 *	 10 <= tam <= MAX_TAMANO
 *	DESCRIPCIÓN: Añade una fila y columna al final del tablero
 */
void entornoAnadirFilaColumna (int tam);



#endif
