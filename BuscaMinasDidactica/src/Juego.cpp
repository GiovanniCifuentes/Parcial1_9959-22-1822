#include "Juego.h"
#include "Jugador.h"
#include "Config.h"
#include "Tablero.h"
#include <fstream>
#include <unistd.h>

int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas)
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario()
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}

	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}

	bool Juego::jugadorGana()
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar()
	{
	    const int FILASTABLERO = 5;
        const int COLUMNASTABLERO = 5;
        const int MINASENTABLERO = 3;
        const bool MODODESARROLLADOR = true;
        const int VIDASTABLERO = 3;

        Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
         Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
			    Jugador jugadorActivo(configuracionJuego.getvidasTablero());

		int fila, columna, vidasRestantes;


		while (true)
		{
			this->tablero.imprimir();
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			if (!respuestaAUsuario)
			{
			    vidasRestantes = jugadorActivo.disminuirVida();
                cout << "Perdiste una vida, Tienes: " << vidasRestantes << endl;
			}
			if(vidasRestantes == 0)
			{
                cout << "\nPERDISTE EL JUEGO!!!!!!!!!\n";
                cout << "\nESFUERZATE MAS PARA LA PROXIMA!!!!!!!!\n";
                cout << "\nTe mostramos donde estaban las minas\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

			if (this->jugadorGana())
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
		}
	}
void Juego::dibujarPortada(string nombreArchivo)
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            //Se obtiene la portada del juego
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}
