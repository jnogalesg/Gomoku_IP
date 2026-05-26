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
 * Caso 2	      t2		       5x5
 * Caso 3		  t3			  10x10
 *
 */
void pruebaIniciarTablero();

/*
 * Pruebas del módulo ponerColor y obtenerColor
 *
 * Tablero t (10x10)
 *
 * Caso	  || Fila || Columna || Color
 * Caso 1  	  1			1		  0
 * Caso 2	  2 		3 		  1
 * Caso 3	  5			7		  0
 *
 */
void pruebaPonerObtenerColorTablero();

/*
 * Pruebas del módulo estaVacia
 * Caso	  || Fila || Columna || Vacia || Color || Tablero
 * Caso 1  	  0			0		true       -  	  t1(5x5)
 * 			  5			5		true	   -
 * 			  0			0		true	   -	  t2(10x10)
 * 			  10		10		true	   -
 * 			  0			0		true	   -	  t3(12x12)
 * 			  12		12		true	   -
 *----------------------------------------------------------
 * Caso 2	  5 		2 		false	   0	  t1
 * 			  2			3		false	   1	  t2
 * 			  3			3		false	   1	  t3
 *----------------------------------------------------------
 * Caso 3	  0			0		false      0 	  t1
 * 			  5			5		false	   0
 * 			  0			0		false	   1	  t2
 * 			  10		10		false	   1
 * 			  0			0		false	   1	  t3
 * 			  12		12		false	   1
 */
void pruebaEstaVaciaTablero();

/*
 * Pruebas del módulo estaLleno
 * Caso	  || Tablero || Lleno || nPiezas
 * Caso 1	t1(12x12)	FALSE	    0
 *
 * Caso 2	   t1		TRUE	   144
 *
 * Caso 3.1	 t2(8x8)	FALSE		0
 * Caso 3.2	   t2		FALSE		3
 *
 * Caso 4	   t2		TRUE		64
 *
 */
void pruebaEstaLleno();

/*
 * Pruebas del módulo cuantasArribaAbajo
 *
 * Tablero t (19X19 MAX)
 *
 * Caso	  || Pieza || Color || Cuantas
 * Caso 1	 (1,1)		0		  1
 * ------------------------------------
 * Caso 2	 (2,1)		0
 * 			 (0,1)		0		  3
 * ------------------------------------
 * Caso 3 	 (3,1)		1
 * 			 (4,1)		0		  3
 */
void pruebaCuantasVertical();

/*
 * Pruebas del módulo cuantasLados
 *
 * Tablero t (19X19 MAX)
 *
 * Caso	  || Pieza || Color || Cuantas
 * Caso 1	 (3,3)		1		  1
 * ------------------------------------
 * Caso 2	 (3,4)		1		  2
 * ------------------------------------
 * Caso 3 	 (3,5)		1
 * 			 (3,2)		1
 * 			 (3,8)		1		  4
 */
void pruebaCuantasHorizontal();

/*
 * Pruebas del módulo cuantasDiagonalArriba
 *
 * Tablero t (15x15)
 *
 * Caso	  || Pieza || Color || Cuantas
 * Caso 1	(10,10)		1		  1
 * ------------------------------------
 * Caso 2	 (9,11)		1  		  2
 * ------------------------------------
 * Caso 3 	 (11,9)		1
 * 			 (12,8)		1
 * 			 (13,7)     0
 * 			 (14,6) 	1		  4
 * ------------------------------------
 * Caso 4 	 (5,5)		0		  1
 * 			 (3,7)   	0		  2
 * 			 (2,8)		0
 *
 */
void pruebaCuantasDiagonalArriba();

/*
 * Pruebas del módulo cuantasDiagonalAbajo
 *
 * Tablero t (10x10)
 *
 * Caso	  || Pieza || Color || Cuantas
 * Caso 1	 (5,5)		0		  1
 * ------------------------------------
 * Caso 2	 (6,6)		0		  2
 * ------------------------------------
 * Caso 3 	 (4,4)		0
 * 			 (3,3)		1		  3
 * ------------------------------------
 * Caso 4    (2,2)		0		  1
 * 			 (1,1)		1
 */
void pruebaCuantasDiagonalAbajo();


/*
 * Llamada a todos los módulos de prueba de TADTablero
 */
void pruebasTablero();



#endif /* PRUEBATABLERO_H_ */
