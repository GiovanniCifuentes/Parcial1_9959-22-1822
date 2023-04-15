#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;// Inicializa la variable cantidadMinas como entero
	int vidasTablero;// Inicializa la variable vidasTablero como entero

	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();
public:
    Juego(Tablero tablero, int cantidadMinas, int vidasTablero);
	void colocarMinasAleatoriamente();
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana();
	void iniciar();
	void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
