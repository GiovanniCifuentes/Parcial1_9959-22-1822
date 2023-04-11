#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Juego.h"
#include "Config.h"
#include "Jugador.h"
#include "persona.h"

using namespace std;

int main()
{
    // Definici�n de constantes que se utilizar�n en el juego
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;

    // Creaci�n de un objeto Config para almacenar la configuraci�n del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    juego.dibujarPortada("portada.txt");
    // Inicializaci�n de la semilla de generaci�n de n�meros aleatorios
    srand(getpid());

    // Variables para almacenar la selecci�n del usuario y controlar el flujo del men�
    int opciones;
    bool repetir = true;

    do
    {
        // Limpia la pantalla
        system("cls");

        // Muestra el men�
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t1. Ingreso de Resgistro de Jugador" << endl;
        cout << "\t\t2. Configuracion del Juego" << endl;
        cout << "\t\t3. Iniciar el juego" << endl;
        cout << "\t\t4. Salir del Menu" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        // Lee la selecci�n del usuario5
        cin >> opciones;

        // Ejecuta la acci�n correspondiente seg�n la selecci�n del usuario
        switch (opciones)
        {
        case 1:
            {
                string id,name,fecha;
                persona estudiante(id,name,fecha);
                estudiante.menu();
                break;
            }
        case 2:
            {
                // Abre el men� de configuraci�n y actualiza la configuraci�n del juego
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 3:
            {
                system("cls");
                cout << "CARGANDO NUEVO TABLERO..." << endl;
                sleep(2);
                system("cls");

                // Crea un objeto Juego con el tablero y el n�mero de minas especificados en la configuraci�n del juego
                Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());

                Jugador jugadorActivo(configuracionJuego.getvidasTablero());
                jugadorActivo.obtenerVida();

                time_t tiempoInicio = time(NULL);
                // Inicia el juego
                juegoTemporal.iniciar();
                time_t tiempoFin = time(NULL);
                int tiempoTranscurrido = difftime(tiempoFin, tiempoInicio);
                cout << "\nTIEMPO OBTENIDO: " << tiempoTranscurrido << " segundos\n" << endl;

                // Pausa la ejecuci�n del programa para que el usuario pueda ver los resultados
                system("pause");
                break;
            }
        case 4:
            repetir = false;
            break;
        }
    }while(repetir);
    system("cls");
    juego.dibujarPortada("creditos.txt");
    // Indica que el programa se ha ejecutado correctamente
    return 0;
}

