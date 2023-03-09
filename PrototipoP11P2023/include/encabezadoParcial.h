#ifndef ENCABEZADOPARCIAL_H
#define ENCABEZADOPARCIAL_H
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

const int NUMERO_EMPRESAS = 5;
const int NUMERO_FECHAS = 4;
const int MAX_CALIFICACION = 1000000;
const int MIN_CALIFICACION = 0;
const int MAX_LONGITUD_CADENA = 50;

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz1[NUMERO_EMPRESAS][NUMERO_FECHAS+1]);
void llenarMatriz2(float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1]);
void llenarMatriz3(float matriz3[NUMERO_EMPRESAS][NUMERO_FECHAS+1]);
void imprimirLineaMatriz();
void imprimirMatriz1(float matriz[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara1[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA]);
void imprimirMatriz2(float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara2[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA]);
void imprimirMatriz3(float matriz2[NUMERO_EMPRESAS][NUMERO_FECHAS+1], char camara3[NUMERO_EMPRESAS][MAX_LONGITUD_CADENA]);

#endif // ENCABEZADOPARCIAL_H
