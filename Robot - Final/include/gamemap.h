#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [15][15];
        void draw();
        // m�todo que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        bool setPlayerCel3(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        virtual ~gamemap();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
        void loadMapFromFile3();
        void createMapToFile3();
};

#endif // GAMEMAP_H
