//============================================================================
// Name        : Gomoku.cpp
// Author      : Jose Nogales Gallardo
// Version     : 2023
// Copyright   : Your copyright notice
// Description : Módulo principal del programa, donde se ejecuta el juego de Gomoku. 
//               Contiene la función main que inicia el juego y llama a las pruebas de las casillas y el tablero (comentadas).
//============================================================================

#include <iostream>
#include "entorno.h"
#include "pruebaCasilla.h"
#include "pruebaTablero.h"
#include "TADJuego.h"

using namespace std;

int main() {

	//pruebasCasilla();
	//pruebasTablero();

	Juego j;
	iniciar(j);

	return 0;
}
