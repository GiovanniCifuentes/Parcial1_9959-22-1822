#include "datos.h"
#include "Usuarios.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

datos::datos(int id, string nombre, string apellido, string genero, string puesto, string departamento, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr)
{
    //El valor del parámetro se asigna al miembro de la clase.
    //El operador this se usa para referirse al miembro de la clase y no al parámetro de la función que tiene el mismo nombre.
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->puesto = puesto;
    this->departamento = departamento;
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

void datos::menuDatos()
{
    bool salir = false;
    int choice;

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion0 = 7001;
    int accion1 = 7002;
    int accion2 = 7003;
    int accion3 = 7004;
    int accion4 = 7005;

	do
    {
	system("cls");

    cout <<"\t\t\t---------------------------------------"<<endl;
    cout <<"\t\t\t|MENU DE INGRESO DE DATOS DE PLANILLA|"<<endl;
    cout <<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de Datos del Empleado"<<endl;
    cout<<"\t\t\t 2. Ingreso de Percepciones del Empledo"<<endl;
	cout<<"\t\t\t 3. Ingreso de Horas Extras del Empleado"<<endl;
	cout<<"\t\t\t 4. Ingreso de Deducciones del Empleado"<<endl;
	cout<<"\t\t\t 5. Agregar los Datos del Empleado"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		menuDatosEmpleado();
		file2<<"\t\t\tAccion: Ingreso Datos del Empleado - " <<accion0<<"\n"<<endl;
		break;
    case 2:
		insertarPercepciones();
		file2<<"\t\t\tAccion: Ingreso Percepciones - " <<accion1<<"\n"<<endl;
		break;
	case 3:
		insertarHorasExtras();
		file2<<"\t\t\tAccion: Ingreso Horas Extras - " <<accion2<<"\n"<<endl;
		break;
	case 4:
		insertarDeducciones();
		file2<<"\t\t\tAccion: Ingreso Deducciones - " <<accion3<<"\n"<<endl;
		break;
    case 5:
		insertar();
		file2<<"\t\t\tAccion: Ingreso Todos los Datos - " <<accion4<<"\n"<<endl;
		break;
	case 6:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 6);
    file2.close();
}
void datos::menuDatosEmpleado()
{
    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t--------------------------------------"<<endl;
    cout <<"\t\t\t|MENU DE INGRESO DE DATOS DE EMPLEADO|"<<endl;
    cout <<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t 1. Datos Personales"<<endl;
	cout<<"\t\t\t 2. Puesto del Empleado"<<endl;
	cout<<"\t\t\t 3. Departamento del Empleado"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        insertarDatos();
        break;
	case 2:
		insertarDatosPuesto();
		break;
	case 3:
		insertarDatosDepartamento();
		break;
	case 4:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 4);
}
void datos::insertarDatos()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Datos Personales ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";//Solicita al usuario que ingrese el ID de la persona y lo almacena en la variable id.
	cin>>id;
	cout<<"\t\t\tNombre: ";//Solicita al usuario que ingrese el nombre del empleado y lo almacena en la variable nombre.
	cin >> nombre;
    cout << "\t\t\tApellido: ";//Solicita al usuario que ingrese el apellido del empleado y lo almacena en la variable apellido.
    cin >> apellido;
    cout << "\t\t\tGenero: ";//Solicita al usuario que ingrese el género del empleado y lo almacena en la variable genero.
    cin >> genero;
    cout << "\t\t\tEscriba su DPI: ";//Solicita al usuario que ingrese su número de DPI y lo almacena en la variable dpi.
    cin >> dpi;
    cout << "\t\t\tEscriba su primer numero de telefono: ";//Solicita al usuario que ingrese su primer número de teléfono y lo almacena en la variable telefono.
    cin >> telefono;
    cout << "\t\t\tEscriba su segundo numero de telefono: ";//Solicita al usuario que ingrese su segundo número de teléfono y lo almacena en la variable telefono1.
    cin >> telefono1;
    cout << "\t\t\tEscriba su numero de cuenta bancaria: ";//Solicita al usuario que ingrese su número de cuenta bancaria y lo almacena en la variable numCuenta.
    cin >> numCuenta;

        cout << "\n\t\t\tIngrese el dia actual: ";//Solicita al usuario que ingrese el día actual y comprueba que sea válido (entre 1 y 31). Si el valor es incorrecto, muestra un mensaje y vuelve a solicitar al usuario que ingrese un valor válido.
        cin >> dia;
        while (dia < 1 || mes> 31)
        {
            cout << "\t\t\tVerifique que el dia sea correcto" << endl;
            cin >> dia;
        }
        cout << "\n\t\t\tIngrese el mes actual: ";//Solicita al usuario que ingrese el mes actual y comprueba que sea válido (entre 1 y 12). Si el valor es incorrecto, muestra un mensaje y vuelve a solicitar al usuario que ingrese un valor válido.
        cin >> mes;
        while (mes < 1 || mes > 12)
        {
            cout << "\t\t\tVerifique que el mes sea correcto" << endl;
            cin >> mes;
        }
        cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertarDatosPuesto()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Puesto del Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tPuesto: ";
    cin >> puesto;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertarDatosDepartamento()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Departamento del Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tDepartamento: ";
    cin >> departamento;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertarPercepciones()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Persepciones Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tSueldo: ";//Solicita al usuario que ingrese el Sueldo de la persona y lo almacena en la variable sueldo.
    cin >> sueldo;
    cout << "\t\t\tBonificacion Incentiva: "<< bonificacionIncentiva << endl;//Se muestra la Bonificacion Incentiva.
    cout << "\t\t\tComisiones: ";////Solicita al usuario que ingrese las comisiones de la persona y lo almacena en la variable comisiones.
    cin >> comisiones;
    cout << "\t\t\tPercepciones Extraordinarias: ";//Solicita al usuario que ingrese las persepciones extraordinarias de la persona y lo almacena en la variable percepciones_extra.
    cin >> percepciones_extra;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertarHorasExtras()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Hora Extras Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tHoras Extra: ";//Solicita al usuario que ingrese las Horas Extras de la persona y lo almacena en la variable horasExtras.
    cin >> horasExtras;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertarDeducciones()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Deducciones Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tPrestamos: ";//Solicita al usuario que ingrese las Prestamos de la persona y lo almacena en la variable prestamos.
    cin >> prestamos;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void datos::insertar()
{
	    //Limpia la pantalla
    system("cls");

    //Declara variables necesarias
    char x;
    float horaOrdinaria, horasExtras;

    //Crea un objeto filestream para trabajar con archivos
    fstream file;

    //Imprime texto en la consola
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------Agregar a Empleado-----------------------------------------------------"<<endl;

    //Pide al usuario si desea agregar un empleado
    cout<<"\t\t\t\n¿Quiere agregar al empleado?(Y,N): ";
    cin>>x;

    //Si el usuario elige "y" o "Y", entra al bloque de código dentro del if
    if (x=='y'||x=='Y'){
        //Calcula el valor de la hora ordinaria y de las horas extras
        horaOrdinaria = ((((sueldo/30)/8)*1.5));
        horas_extra = horaOrdinaria * horasExtras;

        //Calcula el total de percepciones, ISR, IIGS, deducciones totales y sueldo líquido
        total_percepciones = sueldo + bonificacionIncentiva + comisiones + percepciones_extra + horas_extra;
        isr = total_percepciones * 0.05;
        iggs = total_percepciones * 0.03;
        deducciones_totales = isr + iggs + irtra + prestamos;
        sueldo_liquido = total_percepciones - deducciones_totales;

        //Abre el archivo "ParticipantRecord1.txt" en modo de agregar y escritura
        file.open("ParticipantRecord1.txt", ios::app | ios::out);

        //Escribe la información del empleado en el archivo
	   file <<"\n\n\t\t\t Id Persona: "<<id<<endl;
       file << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	   file << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << endl;
	   file << "| " << "Puesto:          " << puesto<< setw(5) << "| " << endl;
       file << "| " << "Departamento:    " << departamento <<setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
       file << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
       file << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
       file << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
       file << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
       file << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
       file << "| " << setw(120) << "|" << endl;
       file << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
       file << "| " << setw(120) << "|" << endl;
       file << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
	   file.close();//Cierra el archivo
	   cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE AL EMPLEADO!!!";
	   }else{
	       cout<<"\t\t\t\nNo se realizara ninguna operacion";
	   }

}
void datos::menuProcesosEmpleado()
{
    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion6 = 7007;
    int accion7 = 7008;
    int accion8 = 7009;

    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|MENU DE PROCESOS DE PLANILLA|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Modificar Datos Empledo"<<endl;
	cout<<"\t\t\t 2. Buscar Datos Empledo"<<endl;
	cout<<"\t\t\t 3. Borrar Datos Empledo"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		modificar();
		file2<<"\t\t\tAccion: Modifico Datos del Empleado - " <<accion6<<"\n"<<endl;
		break;
	case 2:
		buscar();
		file2<<"\t\t\tAccion: Busco a un Empleado - " <<accion7<<"\n"<<endl;
		break;
	case 3:
		borrar();
		file2<<"\t\t\tAccion: Borro a un Empleado -  "<<accion8<<endl;
		file2<<"\t\t\tId Empleado Borrado: " <<id<<"\n"<<endl;
		break;
    case 4:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 4);
    file2.close();
}
void datos::desplegar()
{
    system("cls");
    fstream file;//Se declara una variable "file" de tipo fstream para abrir el archivo.
    string line;//Se declara una variable "line" de tipo string para almacenar las líneas leídas del archivo.
    cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
    file.open("ParticipantRecord1.txt", ios::in);//Se abre el archivo en modo lectura "ios::in" y se verifica si se pudo abrir correctamente.
    if (file.is_open()) {
        while (getline(file, line)) {//Se usa un ciclo while para leer todas las líneas del archivo "ParticipantRecord1.txt" y mostrarlas en la consola con "cout << line << endl;".
            cout << line << endl;
        }
        file.close();//Se cierra el archivo "file.close();".
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
void datos::modificar()
{
    system("cls");
    fstream file,file1;
    int participant_id;
    int found=0;
    cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
    file.open("ParticipantRecord1.txt", ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion..,";
        file.close();
    } else {
        cout<<"\n Ingrese Id de la personas que quiere modificar: ";
        cin>>participant_id;
        file1.open("Record1.txt", ios::app | ios::out);
        while(file >> id >> nombre >> apellido >> genero >> dia >> mes >> dpi >> telefono >> telefono1 >> numCuenta >> sueldo >> bonificacionIncentiva >> comisiones >> percepciones_extra >> horas_extra >> total_percepciones >> isr >> iggs >> irtra >> prestamos >> deducciones_totales >> sueldo_liquido) {
			if(participant_id!=id)
			{
			     file <<"Id Persona: "<<id<<endl;
                 file << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	             file << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << endl;
	             file << "| " << "Puesto:          " << puesto<< setw(5) << "| " << endl;
                 file << "| " << "Departamento:    " << departamento <<setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
                 file << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
                 file << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
                 file << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
                 file << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
                 file << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
                 file << "| " << setw(120) << "|" << endl;
                 file << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
                 file << "| " << setw(120) << "|" << endl;
                 file << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
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

			     file1 <<"Id Persona: "<<id<<endl;
                 file1 << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	             file1 << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << endl;
	             file1 << "| " << "Puesto:          " << puesto<< setw(5) << "| " << endl;
                 file1 << "| " << "Departamento:    " << departamento <<setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
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
    cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
       // Abre el archivo en modo de lectura
    ifstream file("ParticipantRecord1.txt");

    // Lee la ID que deseas buscar
    string id_buscada;
    cout << "Ingresa la ID que deseas buscar: ";
    cin >> id_buscada;

    // Busca la ID en el archivo
    bool encontrado = false;
    string linea;
    while (getline(file, linea)) {
        if (linea.find(id_buscada) != string::npos) {
            encontrado = true;
            cout << linea << endl; // Muestra la línea que contiene la ID buscada
            while (getline(file, linea)) {
                if (linea.find("Id Persona:") != string::npos) {
                    // Se encontró una nueva ID, se detiene la búsqueda
                    break;
                }
                cout << linea << endl; // Muestra la línea siguiente
            }
        }
    }

    // Cierra el archivo
    file.close();

    // Si la ID no se encontró, se muestra un mensaje
    if (!encontrado) {
        cout << "No se encontró la ID buscada." << endl;
    }
}

void datos::borrar()
{
	system("cls");
    string id;
    cout << "Ingrese la ID del registro que desea eliminar: ";
    cin >> id;

    ifstream fileIn("ParticipantRecord1.txt"); //Abrir el archivo de lectura
    ofstream fileOut("temp.txt"); //Crear un archivo temporal para escribir los datos actualizados

    string line;
    bool encontrado = false; //Bandera para indicar si se encontró la ID

    while (getline(fileIn, line)) {
        if (line.find("Id Persona: " + id) != string::npos) { //Si se encuentra la ID
            encontrado = true; //Cambiar la bandera a verdadero para indicar que se encontró
            for (int i = 0; i < 12; i++) { //Saltar 10 líneas (que corresponden a la información del registro)
                getline(fileIn, line);
            }
        }
        else {
            fileOut << line << endl; //Escribir la línea en el archivo temporal
        }
    }

    fileIn.close(); //Cerrar el archivo de lectura
    fileOut.close(); //Cerrar el archivo temporal
    remove("ParticipantRecord1.txt"); //Eliminar el archivo original
    rename("temp.txt", "ParticipantRecord1.txt"); //Cambiar el nombre del archivo temporal al nombre original

    if (encontrado) {
        cout << "Registro eliminado exitosamente." << endl;
    }
    else {
        cout << "No se encontró ningún registro con esa ID." << endl;
    }
}

