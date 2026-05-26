/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2023/2024

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto Gomoku
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificación: 30/10/2023 Allegro5

 */

#include "entorno.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>


#include <iostream>
#include <fstream>


using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno

const int COLOR_AZUL      = 1;
const int COLOR_BLANCO    = 2;
const int COLOR_ROJO      = 3;
const int COLOR_NEGRO     = 4;
const int COLOR_GRIS      = 5;
const int COLOR_AMARILLO  = 6;
const int COLOR_ORO       = 7;
const int COLOR_VERDE     = 8;
const int COLOR_GRIS_CLARO = 9;


const int MAX_CASILLAS   = 25; // el max es 19 + 2 para los bordes
const int TAMANO_CASILLA = 30; // Tamaño de cada casilla del tablero
const int ANCHO_VENTANA  =  TAMANO_CASILLA* MAX_CASILLAS;
const int ALTO_VENTANA   = 800;


 int ORIGEN_X     = 0 ; // 5 // origen de la rejilla
const int ORIGEN_Y     = 50 ;  // Origen de la rejilla

const int RADIO = TAMANO_CASILLA/4;

// definicion de las constantes para posicionar los marcadores
const int FILA_MARCADOR = 140; //210;
const int COL_MARCADOR  = 10;



ALLEGRO_DISPLAY     *display;
ALLEGRO_FONT        *font, *font_texto;
ALLEGRO_EVENT_QUEUE *colaEventos = NULL;
ALLEGRO_BITMAP 		*imagenN;
ALLEGRO_BITMAP 		*imagenB;

// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255,   69,  0);
		break;
	case COLOR_NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case COLOR_AZUL:
		alColor = al_map_rgb (50,   150, 255);
		break;
	case COLOR_GRIS:
		alColor = al_map_rgb ( 130, 130, 130);
		break;
	case COLOR_ORO:
		alColor = al_map_rgb ( 234, 190, 63);
		break;
	case COLOR_VERDE:
		alColor = al_map_rgb ( 0,100,0);
		break;
	case COLOR_GRIS_CLARO:
		alColor = al_map_rgb ( 192,192,192);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}
void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar( int tam) {

	string msg;

	if (al_init()){
	al_install_keyboard();

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_SUGGEST);
	al_set_new_display_flags (ALLEGRO_WINDOWED);

	display = al_create_display(ANCHO_VENTANA,ALTO_VENTANA);
	al_init_primitives_addon(); //

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon ( );

	font = al_load_ttf_font("./img/DroidSerif-Regular.ttf", 18, 0);


    al_clear_to_color(makecolor2(COLOR_BLANCO));
    al_set_window_title(display, "Uex Gomoku");

    colaEventos = al_create_event_queue();
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    al_register_event_source (colaEventos, al_get_display_event_source ( display ) );

    ORIGEN_X = (ANCHO_VENTANA - ((tam+1)*TAMANO_CASILLA))/2;

    al_draw_filled_rectangle(ORIGEN_X, ORIGEN_Y,
           				ORIGEN_X + (tam+1)* TAMANO_CASILLA ,
           				ORIGEN_Y + (tam+1)  * TAMANO_CASILLA , makecolor2(COLOR_VERDE) );

    al_draw_rectangle(ORIGEN_X, ORIGEN_Y,
              				ORIGEN_X + (tam+1) * TAMANO_CASILLA ,
              				ORIGEN_Y + (tam+1) * TAMANO_CASILLA , makecolor2(COLOR_NEGRO),2);

    for (int i=0; i<= tam+1 ; i++){
    	al_draw_line(ORIGEN_X + (i*TAMANO_CASILLA),
    			    ORIGEN_Y ,
    	    		ORIGEN_X + (i*TAMANO_CASILLA),
    	    		ORIGEN_Y + ((tam+1) * TAMANO_CASILLA) , makecolor2(COLOR_NEGRO) ,2);
    }

    for (int i=0; i <= tam+1; i++){
        al_draw_line(ORIGEN_X,
        		    ORIGEN_Y + i*TAMANO_CASILLA,
        	    	ORIGEN_X + ((tam+1) *TAMANO_CASILLA),
        	    	ORIGEN_Y + i*TAMANO_CASILLA , makecolor2(COLOR_NEGRO) ,2);
     }

    imagenN = al_load_bitmap("./img/negra.png");
    imagenB = al_load_bitmap("./img/blanca.png");

     msg = " Cursores: ←, →, ↑, ↓ - Enter: Selec - Esc: Salir - F1: Ayuda - F2: añadir fila/columna";
      al_draw_text(font, makecolor2(COLOR_NEGRO), 22,760,  ALLEGRO_ALIGN_LEFT, msg.c_str());

    al_flip_display();

	}
}void entornoTerminar(){

	al_destroy_display          (display);
	al_destroy_event_queue      (colaEventos);
	al_destroy_font				(font);
	al_destroy_bitmap			(imagenN);
	al_destroy_bitmap			(imagenB);
	al_shutdown_primitives_addon();
	al_shutdown_font_addon      ();

}

bool entornoCargarConfiguracion (int &tam,  int &turno,int &nLinea, int &nPiezas){

	bool leido;

	ifstream fEntrada;
	string cadena, cad;
	fEntrada.open("gomoku.cnf");
	if (fEntrada.is_open()) {
		getline(fEntrada, cadena);
		tam   = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		turno    = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		nLinea   = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		nPiezas = atoi(cadena.c_str());
		leido = true;

		fEntrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/gomoku.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero ]" << endl;

		leido = false;
	}

	return leido;
}



void entornoMarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	int x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA );
	int y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA );
	al_draw_circle(x1, y1, RADIO+4, makecolor2(COLOR_ROJO),2);
	al_flip_display();

}

void entornoDesmarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	int x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA );
	int y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA );
	al_draw_circle(x1, y1, RADIO+4, makecolor2(COLOR_VERDE),2);

	al_draw_line(x1-15,y1, x1-10, y1,  makecolor2(COLOR_NEGRO),2);
	al_draw_line(x1 +10,y1, x1+13, y1, makecolor2(COLOR_NEGRO),2);
	al_draw_line(x1,y1-15, x1, y1-10,  makecolor2(COLOR_NEGRO),2);
	al_draw_line(x1,y1+10, x1, y1+13,  makecolor2(COLOR_NEGRO),2);
	al_flip_display();


}

// color 0 negro 1 blanco
void entornoPonerPieza(int fila, int columna, int color) {

	invertirFC(fila, columna);
	int x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA/2 ) + 6;
	int y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA/2 ) + 6;
	if (color == 0) {// color negro
		al_draw_bitmap(imagenN, x1,y1,1);
	}
	else{
		al_draw_bitmap(imagenB, x1,y1,1);
	}
	al_flip_display();
}


void entornoMarcadorTurno ( int color){
	string msg;
	if (color== 0){
	msg = "Turno: Negra ";
	}else{
	msg = "Turno: Blanca";
	}

	int lonMarcador = 200;
	int x1 = ANCHO_VENTANA/2 -lonMarcador /2 ;
	al_draw_filled_rectangle( x1, COL_MARCADOR, x1 + 200, COL_MARCADOR+35, makecolor2(COLOR_GRIS_CLARO));
	al_draw_rectangle( x1, COL_MARCADOR, x1 + 200, COL_MARCADOR+35, makecolor2(COLOR_NEGRO),2);
	al_draw_text(font, makecolor2(COLOR_NEGRO),x1+40 , COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}



void entornoMostrarMensajeFin ( string msg ) {
	int i, j;
	int desplazamientoCentrado;

	for ( i = 0, j = 0; i < 40 && j < 40; i = i + 4, j = j + 4 ) {
		al_draw_filled_rectangle ( i + 180,     j + 300     , 580 - i, 	 430 - j,  makecolor2 ( COLOR_BLANCO ) );
		al_draw_filled_rectangle ( i + 180 + 2 ,j + 300 + 2 , 580 - 2 - i, 430 - 2 - j,  makecolor2 ( COLOR_GRIS ) );
		usleep(50000); // medio segundo
		al_flip_display ( );
	}
	desplazamientoCentrado = (ANCHO_VENTANA - msg.length()*11)/2;  // pixels x caracter = 11
	al_draw_text ( font, makecolor2 ( COLOR_BLANCO ), desplazamientoCentrado, 350, ALLEGRO_ALIGN_LEFT, msg.c_str ( ) );
	al_flip_display ( );
	usleep(500000); // 5 segundos
}



TipoTecla entornoLeerTecla ( ) {
	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event ( colaEventos, &evento );

	if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
		tecla = TSalir;

	else if ( evento.type == ALLEGRO_EVENT_KEY_DOWN ) {

		switch ( evento.keyboard.keycode ) {

		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;
		case ALLEGRO_KEY_F1:
			tecla = TF1;
			break;
		case ALLEGRO_KEY_F2:
			tecla = TF2;
			break;

		default:
			tecla = TNada;
			break;
		}
	};
	return tecla;
}




void entornoPausa(float pausa) {
	al_rest(pausa);
}
/*********************************************************/
// Implementación de módulos para realizar las ampliaciones
/***********************************************************/

void entornoQuitarPieza (int fila, int columna){
	invertirFC(fila, columna);
	int x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA );
	int y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA );
	al_draw_filled_circle(x1, y1, RADIO+3, makecolor2(COLOR_VERDE));

	x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA );
    y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA );
	al_draw_line(x1-15,y1, x1+15, y1, makecolor2(COLOR_NEGRO),2);
	al_draw_line(x1,y1-15, x1, y1+15, makecolor2(COLOR_NEGRO),2);
	al_flip_display();
}

void entornoMarcarLinea(int fila, int columna) {
	invertirFC(fila, columna);
	int x1 =  (ORIGEN_X + fila * TAMANO_CASILLA)+ TAMANO_CASILLA/2;
	int y1 =  (ORIGEN_Y + columna * TAMANO_CASILLA) + TAMANO_CASILLA/2;
	int x2 =  (x1 + TAMANO_CASILLA) ;
	int y2 =  (y1 + TAMANO_CASILLA) ;
	al_draw_rectangle(x1, y1, x2, y2, makecolor2(COLOR_ROJO), 2);
	al_flip_display();

}

void entornoMarcarAyuda     ( int fila,      int columna,  int pausa){
    int f = fila;
	int c= columna;
	invertirFC(fila, columna);
	int x1 = (ORIGEN_X + fila    * TAMANO_CASILLA) + (TAMANO_CASILLA );
	int y1 = (ORIGEN_Y + columna * TAMANO_CASILLA) + (TAMANO_CASILLA );
	al_draw_circle(x1, y1, RADIO+4, makecolor2(COLOR_AZUL),2);
	al_flip_display();
	entornoPausa(pausa);
	entornoDesmarcarPosicion(f, c);
	al_flip_display();
}

void entornoMarcadorNumPiezas(int numNegras, int numBlancas) {
	string msg;
	msg = "Negras: "+to_string(numNegras) + "    Blancas: "+ to_string(numBlancas);
	int x = (ANCHO_VENTANA/4) + TAMANO_CASILLA;
	int y = 700;
	al_draw_filled_rectangle(x , y,  x+ 300, y+35, makecolor2(COLOR_GRIS_CLARO));
	al_draw_rectangle(x , y,  x+ 300, y+35, makecolor2(COLOR_NEGRO), 2);
	al_draw_text(font, makecolor2(COLOR_NEGRO),x + 40, y+3, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}

void entornoAnadirFilaColumna(int tam) {
	int x, y;

	x = ORIGEN_X;
	y = ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA);
	al_draw_filled_rectangle(x, y, x + ((tam + 2) * TAMANO_CASILLA),
			y + (TAMANO_CASILLA), makecolor2(COLOR_VERDE));

	x = ORIGEN_X + (tam + 1) * TAMANO_CASILLA;
	y = ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA);

	al_draw_filled_rectangle(x, ORIGEN_Y, x + TAMANO_CASILLA,
			ORIGEN_Y + (tam + 2) * TAMANO_CASILLA, makecolor2(COLOR_VERDE));

	al_draw_line(ORIGEN_X, ORIGEN_Y + (tam+1) * TAMANO_CASILLA,
					(ORIGEN_X + ((tam+1 ) * TAMANO_CASILLA)),
					(ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA)), makecolor2(COLOR_NEGRO), 2);
	for (int i = tam + 1; i <= tam + 2; i++) {
		al_draw_line(ORIGEN_X + (i * TAMANO_CASILLA), ORIGEN_Y,
				ORIGEN_X + (i * TAMANO_CASILLA),
				ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA),
				makecolor2(COLOR_NEGRO), 2);
	}

	al_draw_line(ORIGEN_X, ORIGEN_Y + (tam + 2) * TAMANO_CASILLA,
			ORIGEN_X + ((tam + 2) * TAMANO_CASILLA),
			ORIGEN_Y + (tam + 2) * TAMANO_CASILLA, makecolor2(COLOR_NEGRO), 2);

	x = ORIGEN_X;
	y = ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA);

	for (int i = 0; i <= tam + 2; i++) {
		al_draw_line(x + (i * TAMANO_CASILLA), y, x + (i * TAMANO_CASILLA),
				y + (TAMANO_CASILLA), makecolor2(COLOR_NEGRO), 2);
	}

	x = ORIGEN_X + (tam + 1) * TAMANO_CASILLA;
	y = ORIGEN_Y + ((tam + 1) * TAMANO_CASILLA);

	for (int j = 0; j <= tam + 2; j++) {
		al_draw_line(x, ORIGEN_Y + j * TAMANO_CASILLA, x + TAMANO_CASILLA,
				ORIGEN_Y + j * TAMANO_CASILLA, makecolor2(COLOR_NEGRO), 2);
	}

	al_flip_display();

}

