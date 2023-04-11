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
        persona(string id, string name, string fecha);
        string setId(string id);
        string getId();
        string setName(string name);
        string getName();
        string setFecha(string fecha);
        string getFecha();
        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();

    protected:

    private:
        string id,name,fecha;
};

#endif // PERSONA_H"
