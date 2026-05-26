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
 * PRE  : {∃ Tablero t, 0 < tam < 20}
 * DESC : {Inicializa la estructura de datos de tablero con el tamaño indicado
 * 		   por el parámetro tam}
 * COM	:  O(n²)
 */
void iniciarTablero(Tablero &t, int tam);

/*
 * PRE  : {Tablero t inicializado correctamente && estaVacia == TRUE}
 * DESC : {Pone el color introducido por parámetro en la casilla que se encuentra
 *    	   en la posicion [fila][col] del tablero}
 * COM	:  O(1)
 */
void ponerColor(Tablero &t, int fila, int col, int color);

/*
 * PRE  : {Tablero t iniializado correctamente && estaVacia == FALSE}
 * POST : {Devuelve el color de la casilla que se encuentra en la posicion [fila][col] del tablero
 * 		   0 si la casilla es de color negro, 1 si es blanco}
 * COM	:  O(1)
 */
int obtenerColor(Tablero &t, int fila, int col);

/*
 * PRE  : {Tablero t inicializado correctamente}
 * POST : {Devuelve TRUE si la casilla en la posicion [fila][col] del tablero está vacia,
 * 		   y FALSE en caso contrario}
 * COM	:  O(1)
 */
bool estaVacia(Tablero t, int fila, int col);



#endif /* TADTABLERO_H_ */
