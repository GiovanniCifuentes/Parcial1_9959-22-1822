#include "datos.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

datos::datos(int id, string nombre, string apellido, string genero, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr)
{
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->dia = dia;
    this->mes = mes;
    this->dpi = dpi;
    this->telefono = telefono;
    this->telefono1 = telefono1;
    this->numCuenta = numCuenta;
    this->sueldo = sueldo;
    this->comisiones = comisiones;
    this->percepciones_extra = percepciones_extra;
    this->horas_extra = horas_extra;
    this->isr = isr;
}

// set y get para nid
int datos::setId(int id) {
    this->id = id;
}
int datos::getId() {
    return this->id;
}

// set y get para nombre
string datos::setNombre(string nombre) {
    this->nombre = nombre;
}
string datos::getNombre() {
    return this->nombre;
}

// set y get para apellido
string datos::setApellido(string apellido) {
    this->apellido = apellido;
}
string datos::getApellido() {
    return this->apellido;
}

// set y get para genero
string datos::setGenero(string genero) {
    this->genero = genero;
}
string datos::getGenero() {
    return this->genero;
}

// set y get para dia
int datos::setDia(int dia) {
    this->dia = dia;
}
int datos::getDia() {
    return this->dia;
}

// set y get para mes
int datos::setMes(int mes) {
    this->mes = mes;
}
int datos::getMes() {
    return this->mes;
}

// set y get para dpi
int datos::setDpi(int dpi) {
    this->dpi = dpi;
}
int datos::getDpi() {
    return this->dpi;
}

// set y get para telefono
int datos::setTelefono(int telefono) {
    this->telefono = telefono;
}
int datos::getTelefono() {
    return this->telefono;
}

// set y get para telefono1
int datos::setTelefono1(int telefono1) {
    this->telefono1 = telefono1;
}
int datos::getTelefono1() {
    return this->telefono1;
}

// set y get para numCuenta
int datos::setNumCuenta(int numCuenta) {
    this->numCuenta = numCuenta;
}
int datos::getNumCuenta() {
    return this->numCuenta;
}

// set y get para sueldo
float datos::setSueldo(float sueldo) {
    this->sueldo = sueldo;
}
float datos::getSueldo() {
    return this->sueldo;
}

// set y get para comisiones
float datos::setComisiones(float comisiones) {
    this->comisiones = comisiones;
}
float datos::getComisiones() {
    return this->comisiones;
}

// set y get para percepciones_extra
float datos::setPercepciones_extra(float percepciones_extras){
    this->percepciones_extra = percepciones_extras;
}
float datos::getPercepciones_extra(){
    return this->percepciones_extra;
}

// set y get para horas_extra
float datos::setHoras_extra(float horas_extra) {
    this->horas_extra = horas_extra;
}
float datos::getHoras_extra() {
    return this->horas_extra;
}

// set y get para isr
float datos::setIsr(float isr) {
    this->isr = isr;
}
float datos::getIsr() {
    return this->isr;
}

void datos::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL PROGRAMA DE NOMINAS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Datos Para Plantilla"<<endl;
	cout<<"\t\t\t 2. Despliegue Plantilla"<<endl;
	cout<<"\t\t\t 3. Modifice Datos"<<endl;
	cout<<"\t\t\t 4. Buscar Datos"<<endl;
	cout<<"\t\t\t 5. Borrar Datos"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrar();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void datos::insertar()
{
	system("cls");
    int num_empleados;
    float horaOrdinaria, horasExtras;
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>id;
	cout<<"\t\t\tNombre: ";
	cin >> nombre;
    cout << "\t\t\tApellido: ";
    cin >> apellido;
    cout << "\t\t\tGenero: ";
    cin >> genero;
    cout << "\t\t\tEscriba su DPI: ";
    cin >> dpi;
    cout << "\t\t\tEscriba su primer numero de telefono: ";
    cin >> telefono;
    cout << "\t\t\tEscriba su segundo numero de telefono: ";
    cin >> telefono1;
    cout << "\t\t\tEscriba su numero de cuenta bancaria: ";
    cin >> numCuenta;

            cout << "\n\t\t\tIngrese el dia actual:" << endl;
        cin >> dia;
        while (dia < 1 || mes> 31)
        {
            cout << "\t\t\tVerifique que el dia sea correcto" << endl;
            cin >> dia;
        }
        cout << "\n\t\t\tIngrese el mes actual:" << endl;
        cin >> mes;
        while (mes < 1 || mes > 12)
        {
            cout << "\t\t\tVerifique que el mes sea correcto" << endl;
            cin >> mes;
        }

    cout << "\t\t\tSueldo: ";
    cin >> sueldo;
    cout << "\t\t\tBonificacion Incentiva: "<< bonificacionIncentiva << endl;
    cout << "\t\t\tComisiones: ";
    cin >> comisiones;
    cout << "\t\t\tPercepciones Extraordinarias: ";
    cin >> percepciones_extra;
    cout << "\t\t\tHoras Extra: ";
    cin >> horasExtras;
    cout << "\t\t\tPrestamos: ";
    cin >> prestamos;
    horaOrdinaria = ((((sueldo/30)/8)*1.5));
    horas_extra = horaOrdinaria * horasExtras;

    total_percepciones = sueldo + bonificacionIncentiva + comisiones + percepciones_extra + horas_extra;

    isr = total_percepciones * 0.05;
    iggs = total_percepciones * 0.03;

    deducciones_totales = isr + iggs + irtra + prestamos;

    sueldo_liquido = total_percepciones - deducciones_totales;


	file.open("ParticipantRecord1.txt", ios::app | ios::out);
	file <<"\n\n\t\t\t Id Persona: "<<id<<endl;
    file << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	file << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
    file << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
    file << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
    file << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
    file << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
    file << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
    file << "| " << setw(120) << "|" << endl;
    file << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
    file << "| " << setw(120) << "|" << endl;
    file << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
	file.close();
}
void datos::desplegar()
{
    system("cls");
    fstream file;
    string line;
    cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
    file.open("ParticipantRecord1.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
/*{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		while(!file.eof())
		{
			total++;
			cout <<"Id Persona: "<<id<<endl;
            cout << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
            cout << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
            cout << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
            cout << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
            cout << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
            cout << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
            cout << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
            cout << "| " << setw(120) << "|" << endl;
            cout << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
            cout << "| " << setw(120) << "|" << endl;
            cout << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
			file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}*/
void datos::modificar()
{
system("cls");
	fstream file,file1;
	int participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record1.txt",ios::app | ios::out);
		file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		while(!file.eof())
		{
			if(participant_id!=id+1)
			{
			     file1 <<"Id Persona: "<<id<<endl;
			     file1 << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	             file1 << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
                 file1 << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
                 file1 << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
                 file1 << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
                 file1 << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
                 file1 << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
			}
			else{
                int num_empleados;
                float horaOrdinaria, horasExtras;
			    cout<<"\t\t\tIngresa Id Persona         : ";
	            cin>>id;
	            cout<<"\t\t\tNombre: ";
	            cin >> nombre;
                cout << "\t\t\tApellido: ";
                cin >> apellido;
                cout << "\t\t\tGenero: ";
                cin >> genero;
                cout << "\t\t\tEscriba su DPI: ";
                cin >> dpi;
                cout << "\t\t\tEscriba su primer numero de telefono: ";
                cin >> telefono;
                cout << "\t\t\tEscriba su segundo numero de telefono: ";
                cin >> telefono1;
                cout << "\t\t\tEscriba su numero de cuenta bancaria: ";
                cin >> numCuenta;

                cout << "\n\t\t\tIngrese el dia actual:" << endl;
                cin >> dia;
                while (dia < 1 || mes> 31)
                {
               cout << "\t\t\tVerifique que el dia sea correcto" << endl;
               cin >> dia;
               }
               cout << "\n\t\t\tIngrese el mes actual:" << endl;
               cin >> mes;
               while (mes < 1 || mes > 12)
               {
               cout << "\t\t\tVerifique que el mes sea correcto" << endl;
               cin >> mes;
               }

              cout << "\t\t\tSueldo: ";
              cin >> sueldo;
              cout << "\t\t\tBonificacion Incentiva: "<< bonificacionIncentiva << endl;
              cout << "\t\t\tComisiones: ";
              cin >> comisiones;
              cout << "\t\t\tPercepciones Extraordinarias: ";
              cin >> percepciones_extra;
              cout << "\t\t\tHoras Extra: ";
              cin >> horasExtras;
              cout << "\t\t\tPrestamos: ";
              cin >> prestamos;
              horaOrdinaria = ((((sueldo/30)/8)*1.5));
              horas_extra = horaOrdinaria * horasExtras;
              cout << "" << endl;

              total_percepciones = sueldo + bonificacionIncentiva + comisiones + percepciones_extra + horas_extra;

              isr = total_percepciones * 0.05;
              iggs = total_percepciones * 0.03;

              deducciones_totales = isr + iggs + irtra + prestamos;

              sueldo_liquido = total_percepciones - deducciones_totales;

                 file1  <<"Id Persona: "<<id<<endl;
                 file1 << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	             file1 << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
                 file1 << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
                 file1 << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
                 file1 << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
                 file1 << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
                 file1 << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;



            }
		    file1 >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		    }
		    file1.close();
		    file.close();
		    remove("ParticipantRecord1.txt");
		    rename("Record1.txt","ParticipantRecord.txt");
	        }
        }


void datos::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		int participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		while(!file.eof())
		{
			if(participant_id==id+1)
			{
            cout <<"Id Persona: "<<id<<endl;
			cout << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
			cout << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " << isr << setw(4) << "|" << endl;
            cout << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
            cout << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
            cout << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
            cout << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
            cout << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
            cout << "| " << setw(120) << "|" << endl;
            cout << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
            cout << "| " << setw(120) << "|" << endl;
            cout << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
				found++;
			}
			file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void datos::borrar()
{
	system("cls");
	fstream file,file1;
	int participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record1.txt",ios::app | ios::out);
		file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		while(!file.eof())
		{
			if(participant_id!= id+1)
			{
			     file1 <<"Id Persona: "<<id<<endl;
                 file1 << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	             file1 << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
                 file1 << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
                 file1 << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
                 file1 << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
                 file1 << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
                 file1 << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
                 file1 << "| " << setw(120) << "|" << endl;
                 file1 << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord1.txt");
		rename("Record1.txt","ParticipantRecord1.txt");
	}
}

