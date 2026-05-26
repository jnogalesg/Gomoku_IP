/*
 * TADCelda.cpp
 *
 *  Fecha: 27 nov 2023
 *  Autor: Jose Nogales
 */

#include "TADCasilla.h"
#include <iostream>
using namespace std;

void crearCasilla(Casilla &c) {
	c.vacia = true;
}

void ponerColorCasilla(Casilla &c, int color) {
	c.vacia = false;
	c.color = color;
}

int obtenerColorCasilla(Casilla c) {
	return c.color;
}

bool estaVaciaCasilla(Casilla c) {
	return c.vacia;
}
