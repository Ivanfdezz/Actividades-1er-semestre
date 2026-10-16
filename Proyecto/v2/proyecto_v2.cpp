
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main()
{
        struct Alumno
            {string nombre; string matricula; float calificaciones[3]; string grupo;};
        struct Grupo
            {string nombre; string carrera;};
        struct Maestro  
            { string nombre; string materia; vector <string> grupos;};

    int opcion, nalumnos = 0, ngrupos = 0, nmaestros = 0, cantidadgrupos;

    vector <Alumno> Alumnos;
    vector <Grupo> Grupos;
    vector <Maestro> Maestros;
    do
    {
    cout<<"BIENVENIDO AL MENU"<<endl;
    cout<<"Ingrese una opcion:"<<endl;
    cout<<"1. Capturar alumnos"<<endl;
    cout<<"2. Capturar grupos y carreras"<<endl;
    cout<<"3. Capturar maestros"<<endl;
    cout<<"4. Mostrar reportes"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Ingrese una opcion: ";cin>>opcion;

        switch (opcion)
        {
        case 1:
        cout<<"Ingrese la cantidad de alumnos a registrar :";cin>> nalumnos;
        if (nalumnos<1){
            cout<<"La opcion no es valida, intente nuevamente."<<endl;
        }
        else 
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Alumnos.resize(nalumnos);

        for(int i = 0; i< nalumnos; i++)
        {
            cout<<"\nIngrese el nombre del alumno "<<i+1<<" : "; getline(cin,Alumnos[i].nombre);
            cout<<"\nIngrese la matricula del alumno"<<i+1<<" : "; cin>>Alumnos[i].matricula;
            for (int j = 0; j < 3; j++)
            {
                cout<<"Ingrese la calificacion numero "<<j + 1<<" del alumno(a) "<<Alumnos[i].nombre<<" : "; cin>>Alumnos[i].calificaciones[j];
            }
            cout<<"Ingrese el grupo del alumno(a) "<<Alumnos[i].nombre<<" : "; cin>>Alumnos[i].grupo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
            break;
        case 2:
        cout<<"Ingrese la cantidad de grupos a registrar:"; cin>>ngrupos;
        if(ngrupos<1){
            cout<<"La opcion no es valida"<<endl;
        }
        else{
        Grupos.resize(ngrupos);
        for (int l = 0; l < ngrupos; l++)
        {
            cout<<"\nIngrese el nombre del grupo "<<l+1<<" : "; cin>>Grupos[l].nombre;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nIngrese la carrera asociada al grupo "<<l+1<<" : "; getline(cin,Grupos[l].carrera);
        }
            }
            break;
        case 3:
        cout<<"Ingrese la cantidad de maestros a registrar"; cin>>nmaestros;
        if(nmaestros < 1){
            cout<<"La opcion no es valida"<<endl;
        }
        else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Maestros.resize(nmaestros);
        for (int k = 0; k < nmaestros; k++)
        {
            cout<<"Ingrese el nombre del profesor :"; getline(cin,Maestros[k].nombre);
            cout<<"Ingrese el nombre de la materia que imparte: "; getline(cin,Maestros[k].materia);

        cout<<"Cuantos grupos atiende el maestro?: ";cin>>cantidadgrupos;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cantidadgrupos < 1){
            cout<<"La cantidad de grupos no es valida."<<endl;
        }
        else{
            Maestros[k].grupos.resize(cantidadgrupos);

            for (int i = 0; i < cantidadgrupos; i++)
            {
                cout<<"Ingrese el nombre del grupo"<<i+1<<" : "; getline(cin,Maestros[k].grupos[i]);
            }
            
            
            }
        }
    }   

            break;
        case 4:
        if(nalumnos == 0 || ngrupos==0){
            cout<<"\nPrimero debe ingresar a los alumnos y grupos."<<endl;
        }
        else{
        for(int i = 0; i < Alumnos.size(); i++)
        {
        float suma = 0, promedio = 0;

        for (int j = 0; j < 3; j++)
        {
            suma = suma + Alumnos[i].calificaciones[j];
        }
        promedio = suma / 3.0;

        cout<<"El promedio del alumno "<<Alumnos[i].nombre<<" Es: "<<promedio<<endl;
        }
        //REPORTE 2
        for (int g = 0; g < Grupos.size(); g++)
        {
            float promayor = -1;
            string mejoralumno = "";
        
        for (int i = 0; i < Alumnos.size(); i++)
        {
            float prom2 =0, suma2 = 0;

            for(int j = 0; j < 3; j++){

            suma2 += Alumnos[i].calificaciones[j];
            }
            prom2 = suma2 / 3.0;

            if (Alumnos[i].grupo == Grupos[g].nombre) {
            
            if (prom2 > promayor) {
            promayor = prom2;
            mejoralumno = Alumnos[i].nombre;
            }
        }
    }
    if (mejoralumno != ""){
        cout<<"El mejor alumno del grupo "<<Grupos[g].nombre<<" es "<<mejoralumno<<" con promedio de "<<promayor<<endl;
    }
    else{
        cout<<"No hay alumnos registrados en el grupo "<<Grupos[g].nombre<<endl;
    }
    bool hayMaestros = false;
    cout<<"Maestros del grupo "<<Grupos[g].nombre<<" : "<<endl;

    for(int k = 0; k < Maestros.size(); k++){
        for(int i = 0; i < Maestros[k].grupos.size(); i++) {
            if (Maestros[k].grupos[i] == Grupos[g].nombre){
                cout<<Maestros[k].nombre<<" -Materia: "<< Maestros[k].materia<<endl;

                hayMaestros = true;
            }
        }
    }
    if (!hayMaestros){
        cout<<"No hay maestros registrados para este grupo."<<endl;
    }
}

        }
            break;
        case 5:
        cout<<"Esta saliendo del menu"<<endl;
        break;
        
        default:
        cout<<"La opcion no se encuentra en el menu intente nuevamente"<<endl;
            break;
        }

    } while (opcion !=5);

    return 0;
}