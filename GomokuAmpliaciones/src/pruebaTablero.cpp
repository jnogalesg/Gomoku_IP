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
	pruebaEstaLleno();
	pruebaCuantasVertical();
	pruebaCuantasHorizontal();
	pruebaCuantasDiagonalAbajo();
	pruebaCuantasDiagonalArriba();
	pruebaAnadirFilaColumna();
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

//-------------- Caso 3 --------------
	Tablero t3;
	iniciarTablero(t3, 10);

	vacia = true;
	for (int i = 0; i < t3.tamReal; i++) {
		for (int j = 0; j < t3.tamReal; j++) {
			if (!estaVaciaCasilla(t3.vTablero[i][j])) {
				vacia = false;
			}
		}
	}

	if (!vacia) {
		cerr << "ERROR en pruebaIniciarTablero: caso 3"<<endl;
	}
}

void pruebaPonerObtenerColorTablero() {
	Tablero t;
	iniciarTablero(t, 10);

//-------------- Caso 1 --------------
	ponerColor(t, 1, 1, 0);
	if (obtenerColor(t, 1, 1) != 0) {
		cerr << "ERROR en pruebaPonerObtenerColorTablero : caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 2, 3, 1);
	if (obtenerColor(t, 2, 3) != 1) {
		cerr << "ERROR en pruebaPonerObtenerColorTablero : caso 2"<<endl;
	}

//-------------- Caso 3 --------------
	ponerColor(t, 5, 7, 0);
	if (obtenerColor(t, 5, 7) != 0) {
		cerr << "ERROR en pruebaPonerObtenerColorTablero : caso 3"<<endl;
	}

}

void pruebaEstaVaciaTablero() {
	Tablero t1;
	iniciarTablero(t1, 5);

	Tablero t2;
	iniciarTablero(t2, 10);

	Tablero t3;
	iniciarTablero(t3, 12);

//-------------- Caso 1 --------------
	if (estaVacia(t1, 0, 0) != true && estaVacia(t1, 5, 5) != true){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 1 - t1"<<endl;
	}

	if (estaVacia(t2, 0, 0) != true && estaVacia(t2, 10, 10) != true){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 1 - t2"<<endl;
	}

	if (estaVacia(t3, 0, 0) != true && estaVacia(t3, 12, 12) != true){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 1 - t3"<<endl;
	}

	//-------------- Caso 2 --------------

	ponerColor(t1, 5, 2, 0);
	if (estaVacia(t1, 5, 2) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 2 - t1"<<endl;
	}

	ponerColor(t2, 2, 3, 1);
	if (estaVacia(t2, 2, 3) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 2 - t2"<<endl;
	}

	ponerColor(t3, 3, 3, 1);
	if (estaVacia(t3, 3, 3) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 2 - t3"<<endl;
	}


//-------------- Caso 3 --------------

	ponerColor(t1, 0, 0, 0);
	ponerColor(t1, 5, 5, 0);
	if (estaVacia(t1, 0, 0) != false && estaVacia(t1, 5, 5) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 3 - t1"<<endl;
	}

	ponerColor(t2, 0, 0, 1);
	ponerColor(t2, 10, 10, 1);
	if (estaVacia(t2, 0, 0) != false && estaVacia(t2, 10, 10) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 3 - t2"<<endl;
	}

	ponerColor(t3, 0, 0, 1);
	ponerColor(t3, 12, 12, 1);
	if (estaVacia(t3, 0, 0) != false && estaVacia(t3, 12, 12) != false){
		cerr <<"ERROR en pruebaEstaVaciaTablero: caso 3 - t3"<<endl;
	}

}


void pruebaEstaLleno() {
//-------------- Caso 1 --------------
	Tablero t1;
	iniciarTablero(t1, 12);

	if (estaLleno(t1) != false){
		cout << "ERROR en pruebaEstaVacio: caso 1" <<endl;
	}

//-------------- Caso 2 --------------

	for (int i = 0; i<obtenerTamReal(t1); i++){
		for (int j = 0; j<obtenerTamReal(t1); j++){
			ponerColor(t1, i, j, 1);
		}
	}

	if (estaLleno(t1) != true){
		cout << "ERROR en pruebaEstaVacio: caso 2" <<endl;
	}

//-------------- Caso 3 --------------
	Tablero t2;
	iniciarTablero(t2, 8);
//1
	if (estaLleno(t2) != false){
		cout << "ERROR en pruebaEstaVacio: caso 3.1" <<endl;
	}

//2
	ponerColor(t2, 0, 0, 0);
	ponerColor(t2, 1, 1, 0);
	ponerColor(t2, 8, 8, 0);
	if (estaLleno(t2) != false){
		cout << "ERROR en pruebaEstaVacio: caso 3.2" <<endl;
	}

//-------------- Caso 4 --------------
	for (int i = 0; i<obtenerTamReal(t2); i++){
		for (int j = 0; j<obtenerTamReal(t2); j++){
			if (estaVacia(t2, i, j)){
				ponerColor(t2, i, j, 1);
			}
		}
	}

	if (estaLleno(t2) != true){
		cout << "ERROR en pruebaEstaVacio: caso 4" <<endl;
	}
}

void pruebaCuantasVertical() {
	Tablero t;
	iniciarTablero(t, MAX);

//-------------- Caso 1 --------------
	ponerColor(t, 1, 1, 0);
	if(cuantasVertical(t, 1, 1, 0) != 1){
		cout<<"Error en pruebaCuantasVertical caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 2, 1, 0);
	ponerColor(t, 0, 1, 0);
	if(cuantasVertical(t, 1, 1, 0) != 3){
		cout<<"Error en pruebaCuantasVertical caso 2"<<endl;
	}

//-------------- Caso 3 --------------
	ponerColor(t, 3, 1, 1);
	ponerColor(t, 4, 1, 0);
	if(cuantasVertical(t, 1, 1, 0) != 3){
		cout<<"Error en pruebaCuantasVertical caso 3"<<endl;
	}

}

void pruebaCuantasHorizontal(){
	Tablero t;
	iniciarTablero(t, MAX);

//-------------- Caso 1 --------------
	ponerColor(t, 3, 3, 1);
	if (cuantasHorizontal(t, 3, 3, 1) != 1){
		cout << "Error en pruebaCuantasHorizontal caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 3, 4, 1);
	if (cuantasHorizontal(t, 3, 3, 1) != 2){
		cout << "Error en pruebaCuantasHorizontal caso 2"<<endl;
	}

//-------------- Caso 3 --------------4
	ponerColor(t, 3, 5, 1);
	ponerColor(t, 3, 2, 1);
	ponerColor(t, 3, 8, 1);
	if (cuantasHorizontal(t, 3, 3, 1) != 4){
		cout << "Error en pruebaCuantasHorizontal caso 3"<<endl;
	}
}

void pruebaCuantasDiagonalArriba() {
	Tablero t;
	iniciarTablero(t, 15);

//-------------- Caso 1 --------------
	ponerColor(t, 10, 10, 1);
	if (cuantasDiagonalArriba(t, 10, 10, 1) != 1){
		cout << "Error en pruebaCuantasDiagonalArriba caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 9, 11, 1);
	if (cuantasDiagonalArriba(t, 10, 10, 1) != 2){
		cout << "Error en pruebaCuantasDiagonalArriba caso 2"<<endl;
	}

//-------------- Caso 3 --------------
	ponerColor(t, 11, 9, 1);
	ponerColor(t, 12, 8, 1);
	ponerColor(t, 13, 7, 0);
	ponerColor(t, 14, 6, 1);
	if (cuantasDiagonalArriba(t, 10, 10, 1) != 4){
		cout << "Error en pruebaCuantasDiagonalArriba caso 3"<<endl;
	}

//-------------- Caso 4 --------------
	ponerColor(t, 5, 5, 0);
	ponerColor(t, 3, 7, 0);
	ponerColor(t, 2, 8, 0);
	if (cuantasDiagonalArriba(t, 5, 5, 0) != 1){
		cout << "Error en pruebaCuantasDiagonalArriba caso 4.1"<<endl;
	}
	if (cuantasDiagonalArriba(t, 3, 7, 0) != 2){
		cout << "Error en pruebaCuantasDiagonalArriba caso 4.2"<<endl;
	}
}

void pruebaCuantasDiagonalAbajo() {
	Tablero t;
	iniciarTablero(t, 10);

//-------------- Caso 1 --------------
	ponerColor(t, 5, 5, 0);
	if (cuantasDiagonalAbajo(t, 5, 5, 0) != 1){
		cout << "Error en pruebaCuantasDiagonalAbajo caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	ponerColor(t, 6, 6, 0);
	if (cuantasDiagonalAbajo(t, 5, 5, 0) != 2){
		cout << "Error en pruebaCuantasDiagonalAbajo caso 2"<<endl;
	}

//-------------- Caso 3 --------------
	ponerColor(t, 4, 4, 0);
	ponerColor(t, 3, 3, 1);
	if (cuantasDiagonalAbajo(t, 5, 5, 0) != 3){
		cout << "Error en pruebaCuantasDiagonalAbajo caso 3"<<endl;
	}

//-------------- Caso 4 --------------
	ponerColor(t, 2, 2, 0);
	ponerColor(t, 1, 1, 1);
	if (cuantasDiagonalAbajo(t, 2, 2, 0) != 1){
		cout << "Error en pruebaCuantasDiagonalAbajo caso 4"<<endl;
	}

}

void pruebaAnadirFilaColumna() {

//-------------- Caso 1 --------------
	Tablero t1;
	iniciarTablero(t1, 5);

	anadirFilaColumna(t1);
	if (obtenerTamReal(t1) != 6){
		cout << "Error en pruebaAnadirFilaColumna caso 1"<<endl;
	}

//-------------- Caso 2 --------------
	Tablero t2;
	iniciarTablero(t2, 9);

	anadirFilaColumna(t2);
	if(obtenerTamReal(t2) != 10){
	cout << "Error en pruebaAnadirFilaColumna caso 2"<<endl;
	}

//-------------- Caso 3 --------------
	Tablero t3;
	iniciarTablero(t3, 13);

	anadirFilaColumna(t3);
	if(obtenerTamReal(t3) != 14){
	cout << "Error en pruebaAnadirFilaColumna caso 3"<<endl;
	}

//-------------- Caso 4 --------------
	Tablero t4;
	iniciarTablero(t4, 18);

	anadirFilaColumna(t4);
	if(obtenerTamReal(t4) != 19){
	cout << "Error en pruebaAnadirFilaColumna caso 4"<<endl;
	}
}
