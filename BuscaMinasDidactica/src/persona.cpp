#include "persona.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <unistd.h>

using namespace std;

persona::persona(string id, string name, string fecha)
{
    this->id = id;
    this->name = name;
    this->fecha = fecha;
}
// Setter y Getter de id
string persona::setId(string id)
{
    this->id = id;
}
string persona::getId()
{
    return this->id;
}

// Setter y Getter de name
string persona::setName(string name)
{
    this->name = name;
}
string persona::getName()
{
    return this->name;
}

// Setter y Getter de phone
string persona::setFecha(string fecha)
{
    this->fecha = fecha;
}
string persona::getFecha()
{
    return this->fecha;
}


void persona::menu()
{
    int opcion;
	char x;
	bool repetir = true;

	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA REGISTRO PERSONA  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de Usuario"<<endl;
	cout<<"\t\t\t 2. Despliegue de Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificar los Usuarios"<<endl;
	cout<<"\t\t\t 4. Buscar los Usuarios"<<endl;
	cout<<"\t\t\t 5. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 6. Salir"<<endl;

	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
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
		repetir = false;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	system("pause");
    }while(repetir);
}

void persona::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>name;
	cout<<"\t\t\tFecha del Registro: ";
	cin>>fecha;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
	file.close();
}
void persona::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
			cout<<"\t\t\t Nombre Persona: "<<name<<endl;
			cout<<"\t\t\t Fecha del Registro: "<<fecha<<endl;
			file >> id >> name >> fecha;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void persona::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Persona: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Persona: ";
				cin>>name;
				cout<<"\t\t\tFecha del Registro: ";
				cin>>fecha;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
				found++;
			}
			file >> id >> name >> fecha;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void persona::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
				cout<<"\t\t\t Nombre Persona: "<<name<<endl;
				cout<<"\t\t\t Fecha del Registro:: "<<fecha<<endl;
				found++;
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
