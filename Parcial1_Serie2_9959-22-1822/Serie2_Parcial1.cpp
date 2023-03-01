//Autor: Giovanni Steve Cifuentes Palencia
//carné: 9959-22-1822
//Fecha de creacion: 1/03/2023

#include <iostream>

using namespace std;


class Persona
{
public:
    string hIdioma;
    Persona(string Nombre, string Apellido, string tipoIdioma)
    {
        hIdioma = tipoIdioma;
        hNombre = Nombre;
        hApellido = Apellido;
    }
    string getNombre()
    {
        return hNombre;
    }
    void setNombre(string pNombre)
    {
        hNombre = pNombre;
    }
     string getApellido()
    {
        return hApellido;
    }
    void setApellido(string pApellido)
    {
        hApellido = pApellido;
    }
    void idioma()
    {
        cout << hIdioma << endl;
    }
private:
    string hNombre;
    string hApellido;

};
int main()
{
    Persona Juan ("Juan ", "Perez", "Español");
    cout<<Juan.getNombre();
    cout<<Juan.getApellido()<<endl;
    Juan.idioma();
    cout << "Ejemplo para otra persona"<<endl;
    Persona  John ("John ", "Davies", "Ingles");
    cout<<John.getNombre();
    cout<<John.getApellido()<<endl;
    John.idioma();
    return 0;
}


