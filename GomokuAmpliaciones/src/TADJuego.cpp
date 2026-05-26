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
	int fila, col, tam;

	fila = 0;
	col  = 0;
	// tam : tamaño del tablero con el que se va a jugar
	// si turno es 0 comienza el color negro; si es 1, comienza blanco
	// cadGanadora: longitud de la cadena para ganar
	// nPiezas: número inicial de piezas para cada jugador
	if (entornoCargarConfiguracion(tam, j.turno, j.cadGanadora, j.nPiezas)) {

		iniciarTablero(j.t, tam);
		entornoIniciar(tam);
		entornoMarcarPosicion(fila, col);
		jugar(j);
	}
}


void jugar(Juego &j){
	int fila, col, nBlancas, nNegras, filMejor, colMejor;
	fila = 0;
	col  = 0;
	nBlancas = j.nPiezas;
	nNegras = j.nPiezas;
	string msg = "";

	bool salir = false;
	bool ampliado = false;
	TipoTecla tecla;

	while (!salir) {
		entornoMarcadorTurno(j.turno);
		entornoMarcadorNumPiezas(nNegras, nBlancas);
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
					nNegras--;
					j.turno = 1;
				} else{
					nBlancas--;
					j.turno = 0;
				}

				entornoMarcadorNumPiezas(nNegras, nBlancas);
				if (nBlancas == 0 && nNegras == 0){
					msg = "Empate";
					salir = true;
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

			ayuda(j, filMejor, colMejor);

			entornoMarcarAyuda(filMejor, colMejor, 1);


			break;

		case TF2:
			if (!ampliado && obtenerTamReal(j.t) < MAX_TAMANO){
			entornoAnadirFilaColumna(obtenerTamReal(j.t));
			anadirFilaColumna(j.t);
			ampliado = true;
			}

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
	int x = fila;
	int y = col;

	if (cuantasVertical(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;

		while(x <= obtenerTamReal(j.t) && !estaVacia(j.t, x, col) && obtenerColor(j.t, x, col) == j.turno){
			entornoMarcarLinea(x, col);
			x++;
		}

		x = fila;
		while(x >= 0 && !estaVacia(j.t, x, col) && obtenerColor(j.t, x, col) == j.turno){
			entornoMarcarLinea(x, col);
			x--;
		}

	} else if (cuantasHorizontal(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;

		while(y <= obtenerTamReal(j.t) && !estaVacia(j.t, fila, y) && obtenerColor(j.t, fila, y) == j.turno){
			entornoMarcarLinea(fila, y);
			y++;
		}

		y = col;
		while(y >= 0 && !estaVacia(j.t, fila, y) && obtenerColor(j.t, fila, y) == j.turno){
			entornoMarcarLinea(fila, y);
			y--;
		}

	} else if (cuantasDiagonalArriba(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;

		while(x >= 0 && y <= obtenerTamReal(j.t)
				&& !estaVacia(j.t, x, y) && obtenerColor(j.t, x, y) == j.turno){
			entornoMarcarLinea(x, y);
			x--;
			y++;
		}

		x = fila;
		y = col;
		while(x <= obtenerTamReal(j.t) && y >= 0 && !estaVacia(j.t, x, y) && obtenerColor(j.t, x, y) == j.turno){
			entornoMarcarLinea(x, y);
			x++;
			y--;
		}

	} else if (cuantasDiagonalAbajo(j.t, fila, col, j.turno) == j.cadGanadora){
		ganada = true;

		while(x <= obtenerTamReal(j.t) && y <= obtenerTamReal(j.t)
				&& !estaVacia(j.t, x, y) && obtenerColor(j.t, x, y) == j.turno){
			entornoMarcarLinea(x, y);
			x++;
			y++;
		}

		x = fila;
		y = col;
		while(x >= 0 && y >= 0 && !estaVacia(j.t, x, y) && obtenerColor(j.t, x, y) == j.turno){
			entornoMarcarLinea(x, y);
			x--;
			y--;
		}

	}

	return ganada;

}

void ayuda(Juego j, int &filMejor, int &colMejor) {

	filMejor = -1;
	colMejor = -1;
	int cadMayor = 1;

	for (int x = 0; x < obtenerTamReal(j.t); x++){
		for(int y = 0; y < obtenerTamReal(j.t); y++){
				if (estaVacia(j.t, x, y)){
					if(cuantasHorizontal(j.t, x, y, j.turno) > cadMayor
							&&(estaVacia(j.t, x+1, y+1) || estaVacia(j.t, x-1, y-1))){
						cadMayor = cuantasHorizontal(j.t, x, y, j.turno);
						filMejor = x;
						colMejor = y;
					}
					if (cuantasVertical(j.t, x, y, j.turno) > cadMayor
							&&(estaVacia(j.t, x+1, y+1) || estaVacia(j.t, x-1, y-1))){
						cadMayor = cuantasVertical(j.t, x, y, j.turno);
						filMejor = x;
						colMejor = y;
					}
					if (cuantasDiagonalArriba(j.t, x, y, j.turno) > cadMayor
							&&(estaVacia(j.t, x-1, y+1) || estaVacia(j.t, x+1, y-1))){
						cadMayor = cuantasDiagonalArriba(j.t, x, y, j.turno);
						filMejor = x;
						colMejor = y;
					}
					if (cuantasDiagonalAbajo(j.t, x, y, j.turno) > cadMayor
							&&(estaVacia(j.t, x+1, y+1) || estaVacia(j.t, x-1, y-1))){
						cadMayor = cuantasDiagonalAbajo(j.t, x, y, j.turno);
						filMejor = x;
						colMejor = y;
					}
				}
			}
		}
}

void terminar(Juego j, string msg){

	entornoMostrarMensajeFin(msg);
	entornoPausa(1.5);
	entornoTerminar();
}

