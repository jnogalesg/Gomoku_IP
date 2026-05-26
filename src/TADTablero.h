/*
 * TADTablero.h
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_
#include "TADCasilla.h"

const int MAX = 19;
typedef Casilla matriz[MAX][MAX];

struct Tablero{
	matriz vTablero;
	int tamReal;
};
/*
 * PRE  : { ∃ Tablero t }
 * 		  { 5 <= tam <= MAX }
 *
 * DESC : { Inicializa la estructura de datos de tablero con el tamaño indicado
 * 		   por el parámetro tam }
 * COM	:  O(n²)
 */
void iniciarTablero(Tablero &t, int tam);

/*
 * PRE  : { Tablero t inicializado correctamente }
 * POST : { Devuelve el tamaño real del tablero (tamReal) }
 * COM	:  O(1)
 */
int obtenerTamReal(Tablero t);

/*
 * PRE  : { Tablero t inicializado correctamente
 * 		  { estaVacia == TRUE }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *        { color: 0 = negra, 1 = blanca }
 *
 * DESC : { Coloca una pieza del colorintroducido por parámetro en la casilla
 * 		    que se encuentra en la posicion [fila][col] del tablero }
 * COM	:  O(1)
 */
void ponerColor(Tablero &t, int fila, int col, int color);

/*
 * PRE  : { Tablero t iniializado correctamente }
 * 		  { estaVacia == FALSE }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *
 * POST : { Devuelve el color de la casilla que se encuentra en la posicion [fila][col] del tablero }
 * 		  { 0 = negra, 1 = blanca }
 * COM	:  O(1)
 */
int obtenerColor(Tablero &t, int fila, int col);

/*
 * PRE  : { Tablero t inicializado correctamente }
 *	 	  { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *
 * POST : { Devuelve TRUE si la casilla en la posicion [fila][col] del tablero está vacia,
 * 		   y FALSE en caso contrario }
 * COM	:  O(1)
 */
bool estaVacia(Tablero t, int fila, int col);

/*
 * PRE  : { Tablero t inicializado correctamente }
 * POST : { Devuelve TRUE si el tablero esta lleno (todas sus casillas tienen vacia = false),
 * 		   y FALSE en caso contrario }
 * COM	:  O(n²)
 */
bool estaLleno(Tablero t);

/*
 * PRE  : { Tablero t inicializado correctamente }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *        { 0 <= color <= 1}
 *
 * POST	: { Devuelve el número de casillas que hay arriba y abajo de una determinada posición }
 * COM	:  O(n)
 */
int cuantasVertical(Tablero t, int fila, int col, int color);
/*
 * PRE  : { Tablero t inicializado correctamente }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *        { 0 <= color <= 1}
 *
 * POST	: { Devuelve el número de casillas que hay a los laterales de una determinada posición }
 * COM	:  O(n)
 */
int cuantasHorizontal(Tablero t, int fila, int col, int color);

/*
 * PRE  : { Tablero t inicializado correctamente }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *        { 0 <= color <= 1}
 *
 * POST	: { Devuelve el número de casillas que diagonalmente de una determinada posición }
 * COM	:  O(n)
 */
int cuantasDiagonalAbajo(Tablero t, int fila, int col, int color);

/*
 * PRE  : { Tablero t inicializado correctamente }
 * 	      { 0 <= fila < tamReal }
 *        { 0 <= col < tamReal }
 *        { 0 <= color <= 1}
 *
 * POST	: { Devuelve el número de casillas que diagonalmente de una determinada posición }
 * COM	:  O(n)
 */
int cuantasDiagonalArriba(Tablero t, int fila, int col, int color);




#endif /* TADTABLERO_H_ */
