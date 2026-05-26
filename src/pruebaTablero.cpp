/*
 * pruebaTablero.cpp
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */
#include "pruebaTablero.h"
#include <iostream>
using namespace std;

void pruebasTablero() {
	pruebaIniciarTablero();
	pruebaPonerObtenerColorTablero();
	pruebaEstaVaciaTablero();
}

void pruebaIniciarTablero() {
//-------------- Caso 1 --------------
	Tablero t;
	iniciarTablero(t, MAX);

	bool vacia = true;
	for (int i = 0; i < t.tamReal; i++) {
		for (int j = 0; j < t.tamReal; j++) {
			if (!estaVaciaCasilla(t.vTablero[i][j])) {
				vacia = false;
			}
		}
	}

	if (!vacia) {
		cerr << "ERROR en pruebaIniciarTablero: caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	Tablero t2;
	iniciarTablero(t2, 5);

	vacia = true;
	for (int i = 0; i < t2.tamReal; i++) {
		for (int j = 0; j < t2.tamReal; j++) {
			if (!estaVaciaCasilla(t2.vTablero[i][j])) {
				vacia = false;
			}
		}
	}

	if (!vacia) {
		cerr << "ERROR en pruebaIniciarTablero: caso 2"<<endl;
	}

}

void pruebaPonerObtenerColorTablero() {
	Tablero t;
	iniciarTablero(t, MAX);

//-------------- Caso 1 --------------
	ponerColor(t, 1, 1, 0);
	if (obtenerColor(t, 1, 1) != 0) {
		cerr << "ERROR en pruebaPonerObtenerColorTablero : caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 2, 3, 1);
	if (obtenerColor(t, 2, 3) != 1) {
		cerr << "ERROR en pruebaPonerObtenerColorTablero : caso 1"<<endl;
	}

}

void pruebaEstaVaciaTablero() {
	Tablero t;
	iniciarTablero(t, MAX);

//-------------- Caso 1 --------------
	ponerColor(t, 1, 1, 0);
	if (estaVacia(t, 1, 1) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 1"<<endl;
	}
//-------------- Caso 2 --------------
	ponerColor(t, 2, 3, 1);
	if (estaVacia(t, 2, 3) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 2"<<endl;
	}
//-------------- Caso 3 --------------
	if (estaVacia(t, 3, 3) != true){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 3"<<endl;
	}

//-------------- Caso 4 --------------
	if (estaVacia(t, 0, 0) != true){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 4"<<endl;
	}

}





