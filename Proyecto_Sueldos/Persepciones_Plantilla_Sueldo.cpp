 #include <iostream>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <iomanip> //sirve para formatos de salida

 using namespace std;

 const int MAX_EMPLEADOS = 100;
 const int NUMERO_MATERIAS = 5;
 const int MAX_LONGITUD_CADENA = 100;

 void imprimirMatriz(float matriz[MAX_EMPLEADOS][NUMERO_MATERIAS+1]);
 void imprimirLineaMatriz();

 struct Empleado {//esto es un registro
  string nombre;
  float sueldo;
  float bonificacionIncentiva = 250;
  float comisiones;
  float percepciones_extra;
  float horas_extra;
  float total_percepciones;
};

 int main ()
 {
     float matriz [MAX_EMPLEADOS][NUMERO_MATERIAS+1];//definimos la matriz
     imprimirMatriz(matriz);
     return 0;
 }
 void imprimirMatriz(float matriz[MAX_EMPLEADOS][NUMERO_MATERIAS+1]) //llenado de matriz
 {
    int num_empleados;
    float horaOrdinaria, horasExtras;

    Empleado empleados[MAX_EMPLEADOS];
    cout << "Ingrese el número de empleados: ";
    cin >> num_empleados;

    for (int i = 0; i < num_empleados; i++) {
    cout << "Empleado " << i+1 << ":" << endl;
    cout << "Nombre: ";
    cin >> empleados[i].nombre;
    cout << "Sueldo: ";
    cin >> empleados[i].sueldo;
    cout << "Bonificacion Incentiva: "<< empleados[i].bonificacionIncentiva << endl;
    cout << "Comisiones: ";
    cin >> empleados[i].comisiones;
    cout << "Percepciones Extraordinarias: ";
    cin >> empleados[i].percepciones_extra;
    cout << "Horas Extra: ";
    cin >> horasExtras;
    horaOrdinaria = ((((empleados[i].sueldo/30)/8)*1.5));
    empleados[i].horas_extra = horaOrdinaria * horasExtras;
    cout << "El total de horas Extra es igual a: "<<empleados[i].horas_extra << endl;

    // Cálculo del total de percepciones
    empleados[i].total_percepciones = empleados[i].sueldo + empleados[i].bonificacionIncentiva + empleados[i].comisiones + empleados[i].percepciones_extra + empleados[i].horas_extra;
  }
  imprimirLineaMatriz();
   cout << setw(10) << "| Nombre |" << setw(15) << " Sueldo |" << setw(15) << " Bonificaciones |" << setw(15) << " Comisiones |" << setw(30) << " Percepciones Extraordinarias |" << setw(15) << " Horas Extra |" << setw(25) << " Total Percepciones |" << endl;
   imprimirLineaMatriz();
  for (int i = 0; i < num_empleados; i++) {
      cout << setw(10)  << empleados[i].nombre << setw(15) << empleados[i].sueldo  << setw(15) << empleados[i].bonificacionIncentiva  << setw(15)  << empleados[i].comisiones  << setw(30) << empleados[i].percepciones_extra  << setw(15) << empleados[i].horas_extra  << setw(25)  << empleados[i].total_percepciones << endl;
      imprimirLineaMatriz();
  }
 }
 void imprimirLineaMatriz()
 {
     cout <<"+------------";
     for (int x=0; x < NUMERO_MATERIAS; x++)
     {
        cout<<"-----------------------";
     }
     cout <<"+\n";
 }
