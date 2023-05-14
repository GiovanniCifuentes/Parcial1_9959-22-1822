#include <iostream>
#include <fstream>
#include <string>
#include "datos.h"
#include "Usuarios.h"
#include "bitacora.h"

using namespace std;

void menu();
void menuCatalogos();
void menuProcesos();
void menuInformes();



int main() {
    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);
    bool usuarioCorrecto = ingreso.verificarUsuario();

    if (usuarioCorrecto){
        menu();
    }

    return 0;
}

void menu()
{
    fstream file2;
    // Obtiene el tiempo actual
    time_t tiempoActual = time(0);

    // Convierte el tiempo actual a una estructura tm local
    tm* fechaHoraLocal = localtime(&tiempoActual);

    file2.open("Bitacora.txt", ios::app | ios::out);

    int choice;
	char x;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t |BIENVENIDO AL MENU PRINCIPAL|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Procesos"<<endl;
	cout<<"\t\t\t 3. Informes"<<endl;
	cout<<"\t\t\t 4. Salida"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    switch(choice){
    case 1:
        menuCatalogos();
        break;
    case 2:
        menuProcesos();
        break;
    case 3:
        menuInformes();
        break;
    case 4:
	    file2 << "\t\t\tHora en que salio del programa: " << fechaHoraLocal->tm_hour << ":" << fechaHoraLocal->tm_min << ":" << fechaHoraLocal->tm_sec <<"\n" << endl;
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;
    }

	getch();
    }while(choice!= 3);
    file2.close();
}

void menuCatalogos()
{
    string nombre, apellido, genero, puesto, departamento;
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
    datos empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion5 = 7006;

    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE CATALOGO|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Datos Para Plantilla"<<endl;
	cout<<"\t\t\t 2. Ingreso Datos Para Usuarios Nuevos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.menuDatos();
		break;
	case 2:
		do // Se utiliza un do-while para permitir al usuario agregar más de una persona
    	{
    		ingreso.ingresarUsuarios(); // Se llama al método para ingresar nuevos usuarios
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x; // Se pregunta al usuario si desea agregar otra persona
    		file2<<"\t\t\tAccion: Ingreso Un Usuario - " <<accion5<<"\n"<<endl;
		}while(x=='y'||x=='Y'); // Se repite el ciclo mientras la respuesta del usuario sea afirmativa
		break;
	case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
    file2.close();
}

void menuProcesos()
{
    string nombre, apellido, genero, puesto, departamento;
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
    datos empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);


    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);

    bitacora consulta;

    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE PROCESOS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Proceso Datos Plantilla"<<endl;
	cout<<"\t\t\t 2. Proceso Datos Usuarios"<<endl;
	cout<<"\t\t\t 3. Consulta de Bitacora"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.menuProcesosEmpleado();
		break;
	case 2:
		ingreso.menuUsuarios();
		break;
    case 3:
		consulta.desplegarBitacora();
		system("pause");
		menuProcesos();
		break;
	case 4:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
}
void menuInformes()
{
    string nombre, apellido, genero, puesto, departamento;
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
    datos empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion12 = 7022;
    int accion13 = 7023;

    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE INFORMES  |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Informes Datos Para Plantilla"<<endl;
	cout<<"\t\t\t 2. Informes Datos Para Usuarios Nuevos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.desplegar();
        file2<<"\t\t\tAccion: Informes Datos para Plantilla - " <<accion12<<"\n"<<endl;
		break;
	case 2:
	    ingreso.desplegarUsurios();
	    file2<<"\t\t\tAccion: Informes Datos para Usuarios - " <<accion13<<"\n"<<endl;
		break;
	case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
    file2.close();
}
