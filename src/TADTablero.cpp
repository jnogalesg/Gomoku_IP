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

int obtenerTamReal(Tablero t){
	return t.tamReal;
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

bool estaLleno(Tablero t){
	bool lleno = true;

	for (int i = 0; i < t.tamReal; i++){
		for (int j = 0; j < t.tamReal; j++){
			if (estaVaciaCasilla(t.vTablero[i][j])){
				lleno = false;
			}
		}
	}
	return lleno;
}

int cuantasVertical(Tablero t, int fila, int col, int color) {
	int cont = 1;
	bool enc = false;
	int i = fila + 1;

	while(!enc && i < t.tamReal){
		if(!estaVacia(t, i, col) && obtenerColor(t, i, col) == color){
			cont++;
		} else{
			enc = true;
		}

		i++;
	}

	enc = false;
	i = fila - 1;

	while(!enc && i >= 0){
		if(!estaVacia(t, i, col) && obtenerColor(t, i, col) == color){
			cont++;
		} else{
			enc = true;
		}

		i--;
	}

	return cont;
}

int cuantasHorizontal(Tablero t, int fila, int col, int color) {
	int cont = 1;
	bool enc = false;
	int j = col + 1;

	while(!enc && j < t.tamReal){
		if(!estaVacia(t, fila, j) && obtenerColor(t, fila, j) == color){
			cont++;
			j++;
		} else{
			enc = true;
		}
	}

	enc = false;
	j = col - 1;

	while(!enc && j >= 0){
		if(!estaVacia(t, fila, j) && obtenerColor(t, fila, j) == color){
			cont++;
			j--;
		} else{
			enc = true;
		}
	}

	return cont;
}

int cuantasDiagonalAbajo(Tablero t, int fila, int col, int color) {
	int cont = 1;
	bool enc = false;
	int i = fila + 1;
	int j = col + 1;

	while(!enc && i < t.tamReal && j < t.tamReal){
		if(!estaVacia(t, i, j) && obtenerColor(t, i, j) == color){
			cont++;
			i++;
			j++;
		} else{
			enc = true;
		}
	}

	enc = false;
	i = fila - 1;
	j = col - 1;

	while(!enc && i >= 0 && j >= 0){
		if(!estaVacia(t, i, j) && obtenerColor(t, i, j) == color){
			cont++;
			i--;
			j--;
		} else{
			enc = true;
		}
	}

	return cont;
}


int cuantasDiagonalArriba(Tablero t, int fila, int col, int color) {
	int cont = 1;
	bool enc = false;
	int i = fila - 1;
	int j = col + 1;

	while(!enc && i >= 0 && j < t.tamReal){
		if(!estaVacia(t, i, j) && obtenerColor(t, i, j) == color){
			cont++;
			i--;
			j++;
		} else{
			enc = true;
		}
	}

	enc = false;
	i = fila + 1;
	j = col - 1;

	while(!enc && i < t.tamReal && j >= 0){
		if(!estaVacia(t, i, j) && obtenerColor(t, i, j) == color){
			cont++;
			i++;
			j--;
		} else{
			enc = true;
		}
	}

	return cont;
}
