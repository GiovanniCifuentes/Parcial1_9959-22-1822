#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "gamemap2.h"
#include "gamemap3.h"

using namespace std;

int main()
{
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022


    gamemap map;
    gamemap2 map2;
    gamemap3 map3;

    player hero;
    map.drawPortada();
    //map.draw();
    cout << "---------------------------------------------------------------------------------------\n";
    cout << " _____  _____  _____ __  __ ______ _____     _   _ _______      ________ _      \n";
    cout << "|  __ \\|  __ \\|_   _|  \\/  |  ____|  __ \\   | \\ | |_   _\\ \\    / /  ____| |     \n";
    cout << "| |__) | |__) | | | | \\  / | |__  | |__) |  |  \\| | | |  \\ \\  / /| |__  | |     \n";
    cout << "|  ___/|  _  /  | | | |\\/| |  __| |  _  /   | . ` | | |   \\ \\/ / |  __| | |     \n";
    cout << "| |    | | \\ \\ _| |_| |  | | |____| | \\ \\   | |\\  |_| |_   \\  /  | |____| |____ \n";
    cout << "|_|    |_|  \\_\\_____|_|  |_|______|_|  \\_\\  |_| \\_|_____|   \\/   |______|______|\n";
    cout << "---------------------------------------------------------------------------------------\n";
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
        //system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
      }
      //map.draw();

    }

    if (map.isGameOver==true){
     cout << "---------------------------------------------------------------------------------------\n";
    cout << "  _____ ______ _____ _    _ _   _ _____   ____     _   _ _______      ________ _      \n";
    cout << " / ____|  ____/ ____| |  | | \\ | |  __ \\ / __ \\   | \\ | |_   _\\ \\    / /  ____| |     \n";
    cout << "| (___ | |__ | |  __| |  | |  \\| | |  | | |  | |  |  \\| | | |  \\ \\  / /| |__  | |     \n";
    cout << " \\___ \\|  __|| | |_ | |  | | . ` | |  | | |  | |  | . ` | | |   \\ \\/ / |  __| | |     \n";
    cout << " ____) | |___| |__| | |__| | |\\  | |__| | |__| |  | |\\  |_| |_   \\  /  | |____| |____ \n";
    cout << "|_____/|______\\_____|____/|_| \\_|_____/ \\____/   |_| \\_|_____|   \\/   |______|______|\n";
    cout << "---------------------------------------------------------------------------------------\n";
    hero.resetToSafePosition();
    while(map2.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map2.setPlayerCel2(hero.getValueX(), hero.getValueY()))
      {
        map2.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
      }
      //map.draw();

    }
    }
    if (map2.isGameOver==true){
    cout << "---------------------------------------------------------------------------------------\n";
    cout << " _______ ______ _____   _____ ______ _____     _   _ _______      ________ _      \n";
    cout << "|__   __|  ____|  __ \\ / ____|  ____|  __ \\   | \\ | |_   _\\ \\    / /  ____| |     \n";
    cout << "   | |  | |__  | |__) | |    | |__  | |__) |  |  \\| | | |  \\ \\  / /| |__  | |     \n";
    cout << "   | |  |  __| |  _  /| |    |  __| |  _  /   | . ` | | |   \\ \\/ / |  __| | |     \n";
    cout << "   | |  | |____| | \\ \\| |____| |____| | \\ \\   | |\\  |_| |_   \\  /  | |____| |____ \n";
    cout << "   |_|  |______|_|  \\_\\\\_____|______|_|  \\_\\  |_| \\_|_____|   \\/   |______|______|\n";
    cout << "---------------------------------------------------------------------------------------\n";

    hero.resetToSafePosition();
      while(map3.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map3.setPlayerCel3(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map3.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
      }
      //map.draw();

    }
    }


    return 0;
}
