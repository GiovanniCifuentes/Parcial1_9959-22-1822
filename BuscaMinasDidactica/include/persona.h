#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;

class persona
{
    public:
        persona();
        persona(string id, string name, string fecha, int tiempo, int score);
        string setId(string id);
        string getId();
        string setName(string name);
        string getName();
        string setFecha(string fecha);
        string getFecha();
        int setTiempo(int tiempo);
        int getTiempo();
        int setScore(int score);
        int getScore();

        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void buscar1();
		void borrar();
		void ingresoTiempo();

		void menu1();
		void desplegar1();

    protected:

    private:
        string id,name,fecha;
        int tiempo, score;
};

#endif // PERSONA_H"
