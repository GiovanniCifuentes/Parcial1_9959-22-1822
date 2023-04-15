#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Juego.h"
#include "Config.h"
#include "persona.h"

using namespace std;

int main()
{
    // Definición de constantes que se utilizarán en el juego
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;

    // Creación de un objeto Config para almacenar la configuración del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero());
    juego.dibujarPortada("portada.txt");
    // Inicialización de la semilla de generación de números aleatorios
    srand(getpid());

    // Variables para almacenar la selección del usuario y controlar el flujo del menú
    int opciones;
    bool repetir = true;

    do
    {
        // Limpia la pantalla
        system("cls");

        // Muestra el menú
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t1. Ingreso de Registro de Jugador" << endl;
        cout << "\t\t2. Configuracion del Juego" << endl;
        cout << "\t\t3. Iniciar el juego" << endl;
        cout << "\t\t4. Scores Guardados" << endl;
        cout << "\t\t5. Salir del Menu" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        // Lee la selección del usuario5
        cin >> opciones;

        // Ejecuta la acción correspondiente según la selección del usuario
        switch (opciones)
        {
        case 1:
            {
                string id,name,fecha;
                int tiempo, score;
                persona estudiante(id,name,fecha, tiempo, score);
                estudiante.menu();
                break;
            }
        case 2:
            {
                // Abre el menú de configuración y actualiza la configuración del juego
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 3:
            {
                system("cls");
                cout << "CARGANDO NUEVO TABLERO..." << endl;
                sleep(2);
                system("cls");
                // Crea un objeto Juego con el tablero, el número de minas y el número de vidas especificados en la configuración del juego
                Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero());

                //Jugador jugadorActivo(configuracionJuego.getvidasTablero());
                //jugadorActivo.obtenerVida();


                // Inicia el juego
                juegoTemporal.iniciar();


                // Pausa la ejecución del programa para que el usuario pueda ver los resultados
                system("pause");
                break;
            }
        case 4:
            {
                string id,name,fecha;
                int tiempo, score;
                persona estudiante(id,name,fecha, tiempo, score);
                estudiante.menu1();
                break;
            }
        case 5:
            repetir = false;
            break;
        }
    }while(repetir);
    system("cls");
    juego.dibujarPortada("creditos.txt");
    // Indica que el programa se ha ejecutado correctamente
    return 0;
}


