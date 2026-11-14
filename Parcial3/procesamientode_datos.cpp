#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Alumno
{
    string nombre;
    string matricula;
    float calificaciones[3];
};

void ordenar(Alumno alumnos[], float promedio[], int cantidad){
    for (int i = 0; i < cantidad-1; i++)
    {
        for (int j = 0; j < cantidad-1-i; j++)
        {
            if(promedio[j]<promedio[j + 1])
            {
                float temporal = promedio[j];
                promedio[j] = promedio[j + 1];
                promedio[j + 1] = temporal;
                string temporalnombre = alumnos[j].nombre;
                alumnos[j].nombre = alumnos[j+1].nombre;
                alumnos[j+1].nombre = temporalnombre;
                string temporalMatricula = alumnos[j].matricula;
                alumnos[j].matricula = alumnos[j + 1].matricula;
                alumnos[j + 1].matricula = temporalMatricula;
                for (int l = 0; l < 3; l++)
                {
                    float temporalCalificacion = alumnos[j].calificaciones[l];
                    alumnos[j].calificaciones[l] = alumnos[j + 1].calificaciones[l];
                    alumnos[j + 1].calificaciones[l] = temporalCalificacion;
                }
            }
        }
        
    }
    
}

int main()
{
    Alumno alumnos[5];
    float promedio[5];

    ifstream archivo("Alumno.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        string calificacion;

        getline(archivo, alumnos[i].nombre, '|');
        getline(archivo, alumnos[i].matricula, '|');

        for (int j = 0; j < 3; j++)
        {
            getline(archivo,calificacion, '|');
            alumnos[i].calificaciones[j] = stof(calificacion);
        }
        
        getline(archivo, calificacion);
        promedio[i] = stof(calificacion);
    }
    ordenar(alumnos, promedio, 5);

    ofstream archivito("reporte.txt");
    if (!archivito.is_open())
    {
        cout<<"El archivo no se pudo abrir con exito."<<endl;
        return 1;
    }
    archivito << fixed << setprecision(1);

    for (int i = 0; i < 5; i++)
    {
        archivito<<alumnos[i].nombre<<'|'<<alumnos[i].matricula;
        for (int m = 0; m < 3; m++)
        {
            archivito<<alumnos[i].calificaciones[m]<<'|';
        }
        archivito<<promedio[i]<<endl;
    }
    return 0;
}