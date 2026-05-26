/*
 * pruebaTablero.h
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */

#ifndef PRUEBATABLERO_H_
#define PRUEBATABLERO_H_
#include "TADTablero.h"

/*
 * Prueba del módulo iniciar
 * Recorremos el tablero y comprobamos que todas sus casillas están correctamente
 * inicializadas (estaVaciaCasilla = true)
 * Caso	  || 	Tablero	   ||	  Tamaño
 * Caso 1  		  t		  	    MAX(19x19)
 * Caso 2	      t2		        5
 *
 */
void pruebaIniciarTablero();

/*
 * Pruebas del módulo ponerColor y obtenerColor
 * Caso	  || Fila || Columna || Color
 * Caso 1  	  1			1		  0
 * Caso 2	  2 		3 		  1
 *
 */
void pruebaPonerObtenerColorTablero();

/*
 * Pruebas del módulo estaVacia
 * Caso	  || Fila || Columna || Vacia || Color
 * Caso 1  	  1			1		false      0
 * Caso 2	  2 		3 		false	   1
 * Caso 3	  3  		3       true       -
 * Caso 4 	  0			0       true 	   -
 */
void pruebaEstaVaciaTablero();

/*
 * Llamada a todos los módulos de prueba de TADTablero
 */
void pruebasTablero();



#endif /* PRUEBATABLERO_H_ */
