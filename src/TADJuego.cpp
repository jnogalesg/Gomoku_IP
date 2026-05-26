/*
 * TADJuego.cpp
 *
 *  Fecha: 27 nov 2023
 *  Autor: Jose Nogales
 */

#include "TADJuego.h"
#include "entorno.h"
#include <iostream>
using namespace std;

void iniciar(Juego &j){
	int nPiezas;
	int fila, col, tam;

	fila = 0;
	col  = 0;
	// tam : tamaño del tablero con el que se va a jugar
	// si turno es 0 comienza el color negro; si es 1, comienza blanco
	// cadGanadora: longitud de la cadena para ganar
	// nPiezas: número inicial de piezas para cada jugador
	if (entornoCargarConfiguracion(tam, j.turno, j.cadGanadora, nPiezas)) {

		iniciarTablero(j.t, tam);
		entornoIniciar(tam);
		entornoMarcarPosicion(fila, col);
		jugar(j);
	}
}


void jugar(Juego &j){
	int fila, col;
	fila = 0;
	col  = 0;
	string msg = "";

	bool salir = false;
	TipoTecla tecla;

	while (!salir) {
		entornoMarcadorTurno(j.turno);
		tecla = entornoLeerTecla();

		switch (tecla) {
		case TEnter:
			if (estaVacia(j.t, fila, col)){
				entornoPonerPieza(fila, col, j.turno);
				ponerColor(j.t, fila, col, j.turno);

				if (estaLleno(j.t)){
					msg = "Tablero lleno";
					salir = true;

				} else if(ganar(j, fila, col)){
					msg = "¡Has ganado!";
					salir = true;

				}

				if (j.turno == 0){
					j.turno = 1;
				} else{
					j.turno = 0;
				}

			}
			break;
		case TDerecha:
			entornoDesmarcarPosicion(fila, col);

			if (col < obtenerTamReal(j.t) - 1)
				col++;
			else
				col = 0;

			entornoMarcarPosicion(fila, col);

			break;
		case TIzquierda:
			entornoDesmarcarPosicion(fila, col);

			if (col > 0)
				col--;
			else
				col = obtenerTamReal(j.t) - 1;

			entornoMarcarPosicion(fila, col);

			break;
		case TArriba:
			entornoDesmarcarPosicion(fila, col);

			if (fila > 0)
				fila--;
			else
				fila = obtenerTamReal(j.t) - 1;
			entornoMarcarPosicion(fila, col);
			break;
		case TAbajo:
			entornoDesmarcarPosicion(fila, col);

			if (fila < obtenerTamReal(j.t) - 1)
				fila++;
			else
				fila = 0;
			entornoMarcarPosicion(fila, col);

			break;
		case TF1:
			break;
		case TF2:
			break;

		case TSalir:
			msg = "Has abandonado";
			salir = true;
			break;
		case TNada:
			break;
		}
	}

	terminar(j, msg);
}

bool ganar(Juego j, int fila, int col) {
	bool ganada = false;
	if (cuantasVertical(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;
	} else if (cuantasHorizontal(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;
	} else if (cuantasDiagonalArriba(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;
	} else if (cuantasDiagonalAbajo(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;
	}

	return ganada;

}

void terminar(Juego j, string msg){

	entornoMostrarMensajeFin(msg);
	entornoPausa(1.5);
	entornoTerminar();
}

