#ifndef DATOS_H
#define DATOS_H


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;


class datos
{
    public:
        datos();
        datos(int id, string nombre, string apellido, string genero, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr);

        string setNombre(string nombre);
        string getNombre();
        string setApellido(string apellido);
        string getApellido();
        string setGenero(string genero);
        string getGenero();

        int setId(int id);
        int getId();
        int setDia (int dia);
        int getDia();
        int setMes (int mes);
        int getMes();
        int setDpi (int dpi);
        int getDpi();
        int setTelefono (int telefono);
        int getTelefono();
        int setTelefono1(int telefono1);
        int getTelefono1();
        int setNumCuenta (int numCuenta);
        int getNumCuenta();

        float setSueldo(float sueldo);
        float getSueldo();
        float setComisiones(float comisiones);
        float getComisiones();
        float setPercepciones_extra(float percepciones_extra);
        float getPercepciones_extra();
        float setHoras_extra(float horas_extra);
        float getHoras_extra();
        float setIsr(float isr);
        float getIsr();
        float setIggs(float iggs);
        float getIggs();
        float setPrestamosfloatm(float prestamosfloatm);
        float getPrestamosfloatm();

        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
		void imprimirLinea();



    protected:

    private:
        string nombre, apellido, genero;
        int id;
        int dia, mes, dpi, telefono, telefono1 , numCuenta;
        float sueldo;
        float comisiones;
        float percepciones_extra;
        float horas_extra;
        float isr;
        float iggs;
        float prestamos;
        float deducciones_totales;
        float sueldo_liquido;
        float irtra = 75;
        float total_percepciones;
        float bonificacionIncentiva = 250;

};

#endif // PERSONA_H"
