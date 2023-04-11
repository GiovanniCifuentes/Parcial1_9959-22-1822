#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int vidas) : vida(vidas)
{
}

void Jugador::obtenerVida() {
    std::cout << "La vida del jugador es: " << vida << std::endl;
}

int Jugador::disminuirVida()
{
     vida--;
     return vida;
}
