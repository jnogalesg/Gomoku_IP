/*
 * pruebaCasilla.h
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */

#ifndef PRUEBACASILLA_H_
#define PRUEBACASILLA_H_
#include "TADCasilla.h"

/*
 * Prueba del módulo crearCasilla
 * Caso	  || 	Casilla	   ||	  Vacia
 * Caso 1  		  c		  	      true
 * Caso 2	      c2		      true
 */
void pruebaCrear();

/*
 * Prueba del módulo ponerColorCasilla y obtenerColorCasilla
 * Caso	  || 	Casilla	   ||	  Color
 * Caso 1  		  c		  	        0
 * Caso 2	      c2		        1
 */
void pruebaPonerObtenerColor();

/*
 * Prueba del módulo estaVaciaCasilla
 * Caso	  || 	Casilla	   ||	  Color		|| 		Vacia
 * Caso 1  		  c		  	        0				false
 * Caso 2	      c2		        1				false
 */
void pruebaEstaVacia();

/*
 * Llamada a todos los modulos de prueba de TADCasilla
 */
void pruebasCasilla();



#endif /* PRUEBACASILLA_H_ */
