/*
 * TADCelda.h
 *
 *  Fecha: 27 nov 2023
 *  Autor: Jose Nogales
 */

#ifndef TADCASILLA_H_
#define TADCASILLA_H_

struct Casilla{
	bool vacia;
	int color;
};

/*
 * PRE  : {∃ Casilla c}
 * DESC : {Inicializa la estructura de datos, con vacia = TRUE}
 * COM	:  O(1)
 */
void crearCasilla(Casilla &c);

/*
 * PRE  : {Casilla c inicializada correctamente && c.vacia = TRUE
 * 		   && (color == 1 || color == 0)}
 * DESC : {Modifica c.vacia = FALSE, y pone el valor introducido por parámetro,
 * 		   c.color = color, siendo 0 color negro, y 1 color blanco}
 * COM	:  O(1)
 */
void ponerColorCasilla(Casilla &c, int color);

/*
 * PRE  : {Casilla c inicializada correctamente && c.vacia = FALSE}
 * POST : {Devuelve 0 si el color de la casilla es NEGRO,
 * 		   1 si el color es BLANCO}
 * COM	:  O(1)
 */
int obtenerColorCasilla(Casilla c);

/*
 * PRE  : {Casilla c inicializada correctamente}
 * POST : {Devuelve TRUE si la casilla está vacia, FALSE en caso contrario}
 * COM	:  O(1)
 */
bool estaVaciaCasilla(Casilla c);


#endif /* TADCASILLA_H_ */
