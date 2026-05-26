/*
 * pruebaCasilla.cpp
 *
 *  Fecha: 30 nov 2023
 *  Autor: Jose Nogales
 */

#include "pruebaCasilla.h"
#include <iostream>
using namespace std;

void pruebasCasilla() {
	pruebaCrear();
	pruebaPonerObtenerColor();
	pruebaEstaVacia();
}

void pruebaCrear() {
//-------- Caso 1 --------
	Casilla c;
	crearCasilla(c);
	if (c.vacia != true){
		cerr << "ERROR en pruebaCrear : caso 1"<<endl;
	}

//-------- Caso 2 --------
	Casilla c2;
	crearCasilla(c2);
	if (c2.vacia != true){
		cerr << "ERROR en pruebaCrear : caso 2"<<endl;
	}
}

void pruebaPonerObtenerColor() {
//-------- Caso 1 --------
	Casilla c;
	crearCasilla(c);
	ponerColorCasilla(c, 0);
	if (obtenerColorCasilla(c) != 0){
		cerr <<"ERROR en pruebaPonerObtenerColor : caso 1"<<endl;
	}

//-------- Caso 2 --------
	Casilla c2;
	ponerColorCasilla(c2, 1);
	if (obtenerColorCasilla(c2) != 1){
		cerr <<"ERROR en pruebaPonerObtenerColor : caso 2"<<endl;
	}
}

void pruebaEstaVacia() {
//-------- Caso 1 --------
	Casilla c;
	crearCasilla(c);
	if (estaVaciaCasilla(c) != true){
		cerr <<"ERROR en pruebaEstaVacia : casilla c"<<endl;
	}

//-------- Caso 2 --------
	Casilla c2;
	crearCasilla(c2);
	ponerColorCasilla(c2, 1);
	if (estaVaciaCasilla(c2) != false){
		cerr <<"ERROR en pruebaEstaVacia : casilla c2"<<endl;
	}
}
