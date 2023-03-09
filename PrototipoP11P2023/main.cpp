//autor: Giovanni Cifuentes
//serie 3
//fecha de creacion: 08/03/2023

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> // aqui se encuentra le rand, srand
#include <unistd.h>
#include <string.h>
#include <iomanip> //sirve para formatos de salida
#include "encabezadoParcial.h"

using namespace std;


int main()
{
    char opcion;
    //le agrege la funcion para que se repita (lo hice al tiempo)
    do{
    system("cls");
    srand(getpid());
    cout << "\nCamaras de la Industia"<< endl;
    float matriz1[NUMERO_EMPRESAS][NUMERO_FECHAS+1];
    char camara1[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA] = {"Axis Communications     ", "Hikvision               ", "Bosch Security Systems  ", "Honeywell Security      ","Avigilon                "};
    llenarMatriz(matriz1);
    imprimirMatriz1(matriz1, camara1);
    float totalMonto1 = 0;
    for (int y = 0; y < NUMERO_EMPRESAS; y++)
    {
    totalMonto1 += matriz1[y][NUMERO_FECHAS];
    }
    float promedioMonto1 = totalMonto1 / NUMERO_EMPRESAS;
    cout << "\nEl promedio total para la Camara de la Industria es: " << promedioMonto1 << endl;
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    cout << "\nCamaras de la Construccion"<< endl;
    float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1];
    char camara2[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA] = {"Bechtel                 ", "Vinci                   ", "ACS                     ", "Fluor Corporation       ","China Engineering       "};
    llenarMatriz2(matriz2);
    imprimirMatriz2(matriz2, camara2);
    float totalMonto2 = 0;
    for (int y = 0; y < NUMERO_EMPRESAS; y++)
    {
    totalMonto2 += matriz2[y][NUMERO_FECHAS];
    }
    float promedioMonto2 = totalMonto2 / NUMERO_EMPRESAS;
    cout << "\nEl promedio total para la Camara de la Construccion es: " << promedioMonto2 << endl;
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    cout << "\nCamaras de Trasporte"<< endl;
    float matriz3[NUMERO_EMPRESAS][NUMERO_FECHAS+1];
    char camara3[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA] = {"FedEx                   ", "Maersk                  ", "DHL                     ", "Delta Air Lines         ","Uber                    "};
    llenarMatriz3(matriz3);
    imprimirMatriz3(matriz3, camara3);
    float totalMonto3 = 0;
    for (int y = 0; y < NUMERO_EMPRESAS; y++)
    {
    totalMonto3 += matriz3[y][NUMERO_FECHAS];
    }
    float promedioMonto3= totalMonto3 / NUMERO_EMPRESAS;
    cout << "\nEl promedio total para la Camara de Transporte es: " << promedioMonto3 << endl;
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    if (promedioMonto1 > promedioMonto2 && promedioMonto1 > promedioMonto3)
    {
        cout << "\n LA MEJOR CAMARA ES: CAMARA DE LA INDUSTRIA, CON UN PROMEDIO DE: "<< promedioMonto1 <<"!!!\n"<< endl;
    }else if (promedioMonto2 > promedioMonto1 && promedioMonto2 > promedioMonto1)
    {
        cout << "\n LA MEJOR CAMARA ES: CAMARA DE LA CONSTRUCCION, CON UN PROMEDIO DE: "<< promedioMonto2 <<"!!!\n" <<endl;
    }else
    {
        cout << "\n LA MEJOR CAMARA ES: CAMARA DE TRANSPORTE, CON UN PROMEDIO DE: "<< promedioMonto3 <<"!!!" <<endl;
    }
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << " "<< endl;
     cout << "Deseas realizar otra operacion? escribir s si Si, o n si No"<<endl;
    cin >> opcion;
    }while (opcion == 's');//ciclo para repetir otravez el codigo
    cout << " "<< endl;
    cout << "No se realizara ninguna operacion mas"<< endl;
    system ("pause > nul");
    return 0;
}
