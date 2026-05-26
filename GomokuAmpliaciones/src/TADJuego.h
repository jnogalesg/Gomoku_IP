/*
 * TADJuego.h
 *
 *  Fecha: 27 nov 2023
 *  Autor: Jose Nogales
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_
#include "TADTablero.h"
#include <iostream>
using namespace std;

struct Juego{
	Tablero t;
	int turno;
	int cadGanadora;
	int nPiezas;
};

/*
 * PRE  : { j inicializado correcatemente }
 * DESC : { Inicia la estructura de datos del juego según el fichero gomoku.cnf }
 * COM	:  O(1)
 */
void iniciar(Juego &j);

/*
 * PRE  : { j inicializado correcatemente }
 * DESC : { Realiza la gestión general del juego, pulsación de teclas, actualizar el tablero,
 * 		    mostrar por pantalla, finalizar el juego... }
 * COM	:  O(n)
 */
void jugar(Juego &j);

/*
 * PRE	: { j inicializado correcatemente }
 * 	      { 0 <= fila < j.t.tamReal }
 *        { 0 <= col < j.t.tamReal }
 *
 * DESC	: { Comprueba si se ha formado la linea ganadora con el color del turno correspondiente }
 * POST : { Devuelve TRUE si se ha formado la cadena ganadora, FALSE en caso contrario }
 * COM	:  O(n)
 */
bool ganar(Juego j, int fila, int col);

/*
 * PRE	: { j inicializado correcatemente }
 *
 * DESC	: { Al pulsar la tecla F2, muestra por unos segundos la posición ideal para  que el jugador
 * 			actual forme la línea más larga posible }
 * COM	:  O(n²)
 */
void ayuda(Juego j, int &filMejor, int &colMejor);


/*
 * PRE  : { j inicializado correcatemente }
 * DESC : { Termina el juego mostrando un mensaje de despedida y cerrando el entorno gráfico }
 * COM	:  O(1)
 */
void terminar(Juego j, string msg);


#endif /* TADJUEGO_H_ */
