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

int main(){

    Alumno alumnos[5];
    float promedio[5];

    ifstream archivo("Random.txt");
    
        if (!archivo.is_open()){
            cout<<"El archivo no se pudo abirir correctamente";
            return 1;
        }
        for (int i = 0; i < 5; i++)
        {
        getline(archivo, alumnos[i].nombre, '|');
        
        getline(archivo, alumnos[i].matricula, '|');

        for (int j = 0; j < 3; j++)
        {
            archivo>>alumnos[i].calificaciones[j];
            archivo.ignore();
        }
        archivo>>promedio[i];
        archivo.ignore();
        }

        for (int i = 0; i < 5; i++)
        {
            cout<<"El nombre del alumno es: "<<alumnos[i].nombre<<endl;
            cout<<"La matrucla del alumnos es: "<<alumnos[i].matricula<<endl;
            for (int j = 0; j < 3; j++)
            {
                cout<<"La calificacion "<<j+1<<" de "<<alumnos[i].nombre<<" es: "<<alumnos[i].calificaciones[j]<<endl;
            }
            cout<<"El promedio de "<<alumnos[i].nombre<<" es :"<<promedio[i]<<endl;
            
        }
        
    

    return 0;
}