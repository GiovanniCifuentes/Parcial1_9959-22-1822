#include <iostream>
#include <fstream>
#include <string>
#include "datos.h"
#include "Usuarios.h"
#include "bitacora.h"
#include "aplicaciones.h"

using namespace std;

void menu();
void menuCatalogos();
void menuProcesos();
void menuInformes();

Usuario ingreso;


int main() {


    int opcion;
    do{
        system("cls");
        cout <<"\t\t\t----------------------------------"<<endl;
        cout <<"\t\t\t |           Bienvenido          |"<<endl;
        cout <<"\t\t\t----------------------------------"<<endl;
        cout<<"\t\t\t 1. Autenticacion"<<endl;
	    cout<<"\t\t\t 2. Salir"<<endl;
	    cout<<"Ingresa tu Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
        {
            bool usuarioCorrecto = ingreso.verificarUsuario();
            if (usuarioCorrecto){
            menu();
            }
            break;
        }
        case 2:
            cout<<"\n\n\n\t\t\tGracias por usar nuestro programa!!!\n\n\n"<<endl;
            system("pause");
            exit(0);
            break;
        }
    }while(opcion!= 2);


    return 0;
}

void menu()
{

    fstream file2;
    // Obtiene el tiempo actual
    time_t tiempoActual = time(0);

    //Convierte el tiempo actual a una estructura tm local
    tm* fechaHoraLocal = localtime(&tiempoActual);

    file2.open("Bitacora.txt", ios::app | ios::out);

    int choice;
	char x;
	do
    {
	system("cls");
	string usuarioAutenticado = ingreso.getUsuarioAutenticado();
    cout << "Usuario Autenticado: " <<usuarioAutenticado<< "\n"<< endl; // Mostrar el nombre de usuario autenticado
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
        system("cls");
        cout << "Usuario Autenticado: " <<usuarioAutenticado<< "\n"<< endl; // Mostrar el nombre de usuario autenticado
        menuCatalogos();
        break;
    case 2:
        system("cls");
        cout << "Usuario Autenticado: " <<usuarioAutenticado<< "\n"<< endl; // Mostrar el nombre de usuario autenticado
        menuProcesos();
        break;
    case 3:
        system("cls");
        cout << "Usuario Autenticado: " <<usuarioAutenticado<< "\n"<< endl; // Mostrar el nombre de usuario autenticado
        menuInformes();
        break;
    case 4:
	    file2 << "\t\t\tHora en que salio del programa: " << fechaHoraLocal->tm_hour << ":" << fechaHoraLocal->tm_min << ":" << fechaHoraLocal->tm_sec <<"\n" << endl;
	    main();
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

    Usuario ingreso;

    bool salir = false;
    int choice;
    char x;
	do
    {
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE CATALOGO|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Datos Para Planilla"<<endl;
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
    		bitacora metodoAccion;
    		metodoAccion.insertarAccion("706", "ING USUARIO");
		}while(x=='y'||x=='Y'); // Se repite el ciclo mientras la respuesta del usuario sea afirmativa
		break;
	case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
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


    Usuario ingreso;

    bitacora consulta;

    aplicaciones Aplicaciones;


    bool salir = false;
    int choice;
	do
    {
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE PROCESOS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Proceso Datos Plantilla"<<endl;
	cout<<"\t\t\t 2. Proceso Datos Usuarios"<<endl;
	cout<<"\t\t\t 3. Proceso De Aplicaciones"<<endl;
	cout<<"\t\t\t 4. Consulta de Bitacora"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
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
        Aplicaciones.menu();
	case 5:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 5);
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

    Usuario ingreso;

    bitacora metodoAccion;

    bool salir = false;
    int choice;
    char x;
	do
    {
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
        metodoAccion.insertarAccion("7022", "INF. PLANILLA");
		break;
	case 2:
	    ingreso.desplegarUsurios();
        metodoAccion.insertarAccion("7023", "INF. USUARIOS");
		break;
	case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
}
