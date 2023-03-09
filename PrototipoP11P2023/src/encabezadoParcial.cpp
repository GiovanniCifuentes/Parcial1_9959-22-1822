#include "encabezadoParcial.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> // aqui se encuentra le rand, srand
#include <unistd.h>
#include <string.h>
#include <iomanip> //sirve para formatos de salida

using namespace std;


int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
void llenarMatriz(float matriz1[NUMERO_EMPRESAS][NUMERO_FECHAS+1])
{
    for (int y=0; y < NUMERO_EMPRESAS; y++)
    {
        float sumaNotas = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotas += (float)calificacion;
            matriz1[y][x] = calificacion;
        }
        float montoNotas = sumaNotas;
        matriz1[y][NUMERO_FECHAS]=montoNotas;
    }
}
void llenarMatriz2(float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1])
{
    for (int y=0; y < NUMERO_EMPRESAS; y++)
    {
        float sumaNotas = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotas += (float)calificacion;
            matriz2[y][x] = calificacion;
        }
        float montoNotas = sumaNotas;
        matriz2[y][NUMERO_FECHAS]=montoNotas;
    }
}
void llenarMatriz3(float matriz3[NUMERO_EMPRESAS][NUMERO_FECHAS+1])
{
    for (int y=0; y < NUMERO_EMPRESAS; y++)
    {
        float sumaNotas = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotas += (float)calificacion;
            matriz3[y][x] = calificacion;
        }
        float montoNotas = sumaNotas;
        matriz3[y][NUMERO_FECHAS]=montoNotas;
    }
}
void imprimirLineaMatriz()
{
    cout<<"+--------------";
    for (int x=0; x < NUMERO_FECHAS + 1; x++)
    {
        cout<<"--------------------";
    }
    cout<<"+\n";
}
void imprimirMatriz1(float matriz1[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara1[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float montoMayor = matriz1[0][NUMERO_FECHAS];
    float montoMenor = matriz1[0][NUMERO_FECHAS];
    char MontoMayor[MAX_LONGITUD_CADENA];
    char MontoMenor[MAX_LONGITUD_CADENA];
    memcpy(MontoMayor, camara1[0], MAX_LONGITUD_CADENA);
    memcpy(MontoMenor, camara1[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout<<"|          Empresas             |";
    for (int x=0; x < NUMERO_FECHAS; x++)
    {
        cout<<"     201"<< (int) x + 5<<"     |";
    }
    cout<<"       Monto Total     |\n";
    imprimirLineaMatriz();
    for (int y=0; y <NUMERO_EMPRESAS; y++)
    {
        cout<<"|    "<<camara1[y]<<"   |";
        float suma = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
            {
                int calificacion = matriz1[y][x];
                cout<<"\t"<<calificacion<<"   |";
            }
        float monto = matriz1[y][NUMERO_FECHAS];
        if (monto > montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara1[y], MAX_LONGITUD_CADENA);
        }
        if (monto < montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara1[y], MAX_LONGITUD_CADENA);
        }
        cout<<"\t"<< fixed << setprecision(2)<< (double) monto<<"  |\n";
        imprimirLineaMatriz();
    }
    cout<<"Monto mayor de la empresa: "<<MontoMayor<<" con " <<montoMayor<<"\n";
    cout<<"Monto menor de la empresa: "<<MontoMenor<<" con " <<montoMenor<<"\n";
}
void imprimirMatriz2(float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara2[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float montoMayor = matriz2[0][NUMERO_FECHAS];
    float montoMenor = matriz2[0][NUMERO_FECHAS];
    char MontoMayor[MAX_LONGITUD_CADENA];
    char MontoMenor[MAX_LONGITUD_CADENA];
    memcpy(MontoMayor, camara2[0], MAX_LONGITUD_CADENA);
    memcpy(MontoMenor, camara2[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout<<"|          Empresas             |";
    for (int x=0; x < NUMERO_FECHAS; x++)
    {
        cout<<"     201"<< (int) x + 5<<"     |";
    }
    cout<<"       Monto Total     |\n";
    imprimirLineaMatriz();
    for (int y=0; y <NUMERO_EMPRESAS; y++)
    {
        cout<<"|    "<<camara2[y]<<"   |";
        float suma = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
            {
                int calificacion = matriz2[y][x];
                cout<<"\t"<<calificacion<<"   |";
            }
        float monto = matriz2[y][NUMERO_FECHAS];
        if (monto > montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara2[y], MAX_LONGITUD_CADENA);
        }
        if (monto < montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara2[y], MAX_LONGITUD_CADENA);
        }
        cout<<"\t"<< fixed << setprecision(2)<< (double) monto<<"  |\n";
        imprimirLineaMatriz();
    }
    cout<<"Monto mayor de la empresa: "<<MontoMayor<<" con " <<montoMayor<<"\n";
    cout<<"Monto menor de la empresa: "<<MontoMenor<<" con " <<montoMenor<<"\n";
}
void imprimirMatriz3(float matriz3[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara3[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float montoMayor = matriz3[0][NUMERO_FECHAS];
    float montoMenor = matriz3[0][NUMERO_FECHAS];
    char MontoMayor[MAX_LONGITUD_CADENA];
    char MontoMenor[MAX_LONGITUD_CADENA];
    memcpy(MontoMayor, camara3[0], MAX_LONGITUD_CADENA);
    memcpy(MontoMenor, camara3[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout<<"|          Empresas             |";
    for (int x=0; x < NUMERO_FECHAS; x++)
    {
        cout<<"     201"<< (int) x + 5<<"     |";
    }
    cout<<"       Monto Total     |\n";
    imprimirLineaMatriz();
    for (int y=0; y <NUMERO_EMPRESAS; y++)
    {
        cout<<"|    "<<camara3[y]<<"   |";
        float suma = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
            {
                int calificacion = matriz3[y][x];
                cout<<"\t"<<calificacion<<"   |";
            }
        float monto = matriz3[y][NUMERO_FECHAS];
        if (monto > montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara3[y], MAX_LONGITUD_CADENA);
        }
        if (monto < montoMayor)
        {
            montoMayor = monto;
            memcpy(MontoMayor, camara3[y], MAX_LONGITUD_CADENA);
        }
        cout<<"\t"<< fixed << setprecision(2)<< (double) monto<<"  |\n";
        imprimirLineaMatriz();
    }

    cout<<"Monto mayor de la empresa: "<<MontoMayor<<" con " <<montoMayor<<"\n";
    cout<<"Monto menor de la empresa: "<<MontoMenor<<" con " <<montoMenor<<"\n";
}
