#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Alumnos
    {
        string nombre;
        string matricula;
        float calificaciones[3];
    };

int main(){
Alumnos alumno;
float promedio, prom = 0;

cout<<"Ingrese el nombre del alumno"<<endl;
getline(cin,alumno.nombre);
cout<<"Ingrese la matricula del estudiante"<<endl;
getline(cin, alumno.matricula);

for (int i = 0; i < 3; i++)
{
    cout<<"Ingrese la calificacion del parcial"<<i+1<<endl;
    cin>> alumno.calificaciones[i];
    prom += alumno.calificaciones[i];
}
promedio = prom / 3;

ofstream archivo("Datos.txt", ios::app);

if (!archivo.is_open())
{
    cout<<"El archivo no se pudo abrir."<<endl;
    return 1;
}


archivo<<alumno.nombre<<"|"<<alumno.matricula<<"|";

for (int i = 0; i < 3; i++)
{
    archivo<<alumno.calificaciones[i]<<"|";
}
    archivo<<promedio<<endl;

    archivo.close();

    return 0;
}