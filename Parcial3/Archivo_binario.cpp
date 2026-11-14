#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

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

ifstream archivo("Nose.txt");
if(!archivo.is_open())
{
    cout<<"No se pudo abrir el archivo de texto."<<endl;
    return 1;
}

    ofstream binario("alumnos.bin",ios::binary);
    if (!binario.is_open())
    {
        cout<<"No se pudo abrir el archivo."<<endl;
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

    archivo.close();
    
    for (int i = 0 ; i<5; i++)
    {
    int long_nombres = alumnos[i].nombre.size();
    binario.write(reinterpret_cast<const char*>(&long_nombres), sizeof(long_nombres));
    binario.write(alumnos[i].nombre.c_str(),long_nombres);
    int long_matricula = alumnos[i].matricula.size();
    binario.write(reinterpret_cast<const char*>(&long_matricula), sizeof(long_matricula));
    binario.write(alumnos[i].matricula.c_str(),long_matricula);
    binario.write(reinterpret_cast<const char*>(alumnos[i].calificaciones), sizeof(alumnos[i].calificaciones));
    binario.write(reinterpret_cast<const char*>(&promedio[i]), sizeof(promedio[i]));
    }
    binario.close();

    cout<<"Tamaño del archivo binario: "
        <<filesystem::file_size("alumnos.bin")<<" Bytes"<<endl;
    cout<<"Tamaño del archivo de texto: "
        <<filesystem::file_size("Alumnos.txt")<<" Bytes"<<endl;

    return 0;
}