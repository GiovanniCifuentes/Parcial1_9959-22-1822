#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "datos.h"

using namespace std;

int main()
{
    vector<string> usuarios;
    vector<string> contrasenas;

    usuarios.push_back("Giovanni");
    usuarios.push_back("Favio");
    usuarios.push_back("Kevin");
    usuarios.push_back("Daniel");

    contrasenas.push_back("147");
    contrasenas.push_back("258");
    contrasenas.push_back("369");
    contrasenas.push_back("753");

    string usuario, contrasena;

    int contador = 0;
    bool ingresa = false;

    do{
        system("cls");
        cout <<"\t\t\t-----------------"<<endl;
        cout <<"\t\t\t| LONGIN DE USUARIO |"<<endl;
        cout <<"\t\t\t-----------------"<<endl;
        cout <<"\n\t¡¡¡Advertencia: Solo tienes permetido 3 intetos!!!"<<endl;
        cout <<"\t---------------------------------------------------"<<endl;
        cout <<"\n\tIngrese su usuario: ";
        cin >> usuario;
        cout <<"\n\tIngrese su password: ";
        char caracter;
        caracter = getch();

        contrasena = "";

        while (caracter != 13){
                if(caracter != 8)
                {
                    contrasena.push_back(caracter);
                    cout<< "*";
                }else{
                    if(contrasena.length()>0)
                    {
                        cout<<"\b \b";
                        contrasena = contrasena.substr(0, contrasena.length() - 1);
                    }
                }

            caracter = getch();
        }

        for(int i = 0; i < usuarios.size(); i++)
        {
            if(usuarios[i] == usuario && contrasenas[i] == contrasena){
                ingresa = true;
            }
        }

        if(!ingresa){
            cout << "\n"<<endl;
                cout << "\n\tUSUARIO Y/O PASSWORD INCORRECTOS"<<endl;
                cout << "\n\tPerdio un intento, Intente de nuevo"<<endl;
                cout << "\n"<<endl;
                contador++;
                system("pause");
        }
    }while(ingresa == false && contador < 3);

    if(ingresa == false)
    {
        system("cls");
        cout << "\n\tPERDIO LOS 3 INTENTOS"<<endl;
        cout << "\n\tNO PODRA INGRESAR MAS INTENTOS"<<endl;
    }else{
        system("cls");
        string nombre, apellido, genero;
        int id;
        int dia, mes, dpi, telefono, telefono1 , numCuenta;
        float sueldo;
        float bonificacionIncentiva = 250;
        float comisiones;
        float percepciones_extra;
        float horas_extra;
        float total_percepciones;
        float isr;
        float iggs;
        float irtra = 75;
        float prestamos;
        float deducciones_totales;
        float sueldo_liquido;
        datos estudiante(id, nombre, apellido,genero, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);
        estudiante.menu();
    }



    return 0;
}
