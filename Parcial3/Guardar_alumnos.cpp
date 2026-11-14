#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>                                                                                                                

using namespace std;

struct Alumno
    {
        string nombre;
        string matricula;
        float calificaciones[3];
    };

int main(){

    Alumno alumnos[5];
    float promedio[5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        float suma = 0;

        cout<<"\nIngrese el nombre del alumno "<<i+1<<" : ";
        getline(cin,alumnos[i].nombre);

        alumnos[i].matricula = "";
        for (int j = 0; j < 7; j++)
        {
            alumnos[i].matricula += to_string(rand() % 10);
        }

        for (int j = 0; j < 3; j++)
        {
            alumnos[i].calificaciones[j] = (rand() % 51 + 50) / 10.0;

            suma = suma + alumnos[i].calificaciones[j];
        }

        promedio[i] = suma / 3;
    }

    ofstream archivo("Alumnos.txt");

    if (!archivo.is_open())
    {
        cout<<"El archivo no se pudo abrir.";

        return 1;
    }
    archivo << fixed << setprecision(1);
    

    for (int l = 0; l < 5; l++)
    {
        archivo<<alumnos[l].nombre<<"|"<<alumnos[l].matricula<<"|";

        for (int j = 0; j < 3; j++)
        {
            archivo<<alumnos[l].calificaciones[j]<<"|";
        }

        archivo<<promedio[l]<<endl;
    }

    return 0;
}


//("Z:/CarpetaInexistente/Alumnos.txt"); <----- Para crear un archivo de texto con error, lo use para causar errores
