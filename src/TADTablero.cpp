/*
 * TADTablero.cpp
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */

#include "TADTablero.h"
#include <iostream>
using namespace std;

void iniciarTablero(Tablero &t, int tam) {
	t.tamReal = tam;

	for (int i = 0; i < t.tamReal; i++){
		for (int j = 0; j < t.tamReal; j++){
			crearCasilla(t.vTablero[i][j]);
		}
	}
}

void ponerColor(Tablero &t, int fila, int col, int color) {
	ponerColorCasilla(t.vTablero[fila][col], color);
}

int obtenerColor(Tablero &t, int fila, int col) {
	return obtenerColorCasilla(t.vTablero[fila][col]);
}

bool estaVacia(Tablero t, int fila, int col) {
	return estaVaciaCasilla(t.vTablero[fila][col]);
}
