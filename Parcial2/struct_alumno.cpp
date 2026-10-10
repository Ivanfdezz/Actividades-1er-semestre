
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    struct Alumno
    {
        string nombre;
        string matricula;
        float calificaciones[3];
    };

    Alumno alumnos[5];
    float promedio[5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        float suma = 0;

        cout<<"\nIngrese el nombre del alumno "<<i+1<<" : ";
        getline(cin,alumnos[i].nombre); //*getline para que lea nombres con espacios*

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

    for (int l = 0; l < 5; l++)
    {
        cout<<"\nNombre del alumno: "<<alumnos[l].nombre<<endl;
        cout<<"Matricula del alumno: "<<alumnos[l].matricula<<endl;

        for (int j = 0; j < 3; j++)
        {
            cout<<"Calificacion "<<j + 1<<": "
                <<fixed<<setprecision(1)
                <<alumnos[l].calificaciones[j]<<endl;
        }

        cout<<"El promedio del alumno es: "
            <<fixed<<setprecision(1)<< promedio[l]<<endl;
    }

    return 0;
}



//CODIGO PARA QUE EL USUARIO INGRESE LOS DATOS
/*#include <iostream>
#include <string>
#include <limits>    //permite limpiar caracteres pendientes en la entrada
#include <iomanip>

using namespace std;

int main(){
    struct Alumno
    {
        string nombre;
        string matricula;
        float calificaciones[3];
    };
    Alumno alumnos[5];
    float promedio[5];
    
    for (int i = 0; i < 5; i++)
    {
        float suma = 0;

        cout<<"\nIngrese el nombre del alumno "<<i+1<<" : "; getline(cin,alumnos[i].nombre); //getline para que lea nombres con espacios
        cout<<"Ingrese la matricula del alumno "<<i+1<<" : "; cin>>alumnos[i].matricula;

        for (int j = 0; j < 3; j++)
        {
            cout<<"Ingrese la calificacion numero "<<j + 1<<" del alumno(a) "<<alumnos[i].nombre<<" : "; 
            cin>>alumnos[i].calificaciones[j];

            suma = suma + alumnos[i].calificaciones[j];
        }
        promedio[i] = suma / 3;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');      //<-----//cin.ignore: descarta caracteres de la entrada
    }                                                                    // numeric_limits<streamsize>::max() : indica una cantidad maxima que se vuekve grande de caracteres a descartar
        for ( int l = 0; l < 5; l++)                                     //'\n': indica que se detenga al encontrar el salto
        {
            cout<<"\nNombre del alumno: "<<alumnos[l].nombre<<endl;
            cout<<"Matricula del alumno: "<<alumnos[l].matricula<<endl;
            cout<<"El promedio del alumno es: "<<fixed<<setprecision(1)<< promedio[l]<<endl;    //<--------
        }                                                                                       //Ingrese fixed<<setprecision(1) para que en la salida solo se vea un decimal
        
    return 0;
}*/