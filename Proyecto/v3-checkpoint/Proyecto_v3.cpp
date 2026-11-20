#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

        struct Alumno
            {string nombre; string matricula; float calificaciones[3]; string grupo;};
        struct Grupo
        
            {string nombre; string carrera;};
        struct Maestro  
            { string nombre; string materia; vector <string> grupos;};

float CalcularPromedio(const Alumno& alumno){
            float suma = 0;

            for(int j = 0; j < 3; j++){
                suma += alumno.calificaciones[j];
            }
            return suma / 3;
        }

void capturarAlumnos(vector<Alumno>& Alumnos){
    int CantidadNuevos;
    Alumno Alumno_Nuevo;
    cout<<"Ingrese la cantidad de alumnos a registrar : ";cin>> CantidadNuevos;

        if (CantidadNuevos<1){
            cout<<"La opcion no es valida, intente nuevamente."<<endl;
        }
        else 
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        for(int i = 0; i< CantidadNuevos; i++)
        {
            cout<<"\nIngrese el nombre del alumno "<<i+1<<" : "; getline(cin,Alumno_Nuevo.nombre);
            cout<<"\nIngrese la matricula del alumno "<<i+1<<" : "; cin>>Alumno_Nuevo.matricula;
            for (int j = 0; j < 3; j++)
            {
                cout<<"Ingrese la calificacion numero "<<j + 1<<" del alumno(a) "<<Alumno_Nuevo.nombre<<" : "; cin>>Alumno_Nuevo.calificaciones[j];
            }
            cout<<"Ingrese el grupo del alumno(a) "<<Alumno_Nuevo.nombre<<" : "; cin>>Alumno_Nuevo.grupo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Alumnos.push_back(Alumno_Nuevo);
        }
    }
}
void capturarGrupos(vector<Grupo>& Grupos)
{
    int ngrupos;
    Grupo Grupo_Nuevo;

    cout<<"Ingrese la cantidad de grupos a registrar: "; cin>>ngrupos;
        if(ngrupos<1){
            cout<<"La opcion no es valida"<<endl;
        }
        else{
        for (int l = 0; l < ngrupos; l++)
        {
            cout<<"\nIngrese el nombre del grupo "<<l+1<<" : "; cin>>Grupo_Nuevo.nombre;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nIngrese la carrera asociada al grupo "<<l+1<<" : "; getline(cin,Grupo_Nuevo.carrera);
            Grupos.push_back(Grupo_Nuevo);
        }
            }
}

void capturarMaestros(vector<Maestro>& Maestros)
{
    int nmaestros, cantidadgrupos;
    string nombreGrupo;
    Maestro Maestro_Nuevo;

    cout<<"Ingrese la cantidad de maestros a registrar: "; cin>>nmaestros;
        if(nmaestros < 1){
            cout<<"La opcion no es valida"<<endl;
        }
        else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int k = 0; k < nmaestros; k++)
        {
            Maestro_Nuevo = Maestro{};
            cout<<"Ingrese el nombre del profesor(a): "; getline(cin,Maestro_Nuevo.nombre);
            cout<<"Ingrese el nombre de la materia que imparte: "; getline(cin,Maestro_Nuevo.materia);

        cout<<"Ingrese cuantos grupos atiende el profesor(a): ";cin>>cantidadgrupos;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cantidadgrupos < 1){
            cout<<"La cantidad de grupos no es valida."<<endl;
        }
        else{

            for (int i = 0; i < cantidadgrupos; i++)
            {
                cout<<"Ingrese el nombre del grupo "<<i+1<<" : "; getline(cin,nombreGrupo);
                Maestro_Nuevo.grupos.push_back(nombreGrupo);
            }
            }
            Maestros.push_back(Maestro_Nuevo);
        }
    }

}

void mostrarReportes(
    const vector<Alumno>& Alumnos,
    const vector<Grupo>& Grupos,
    const vector<Maestro>& Maestros)
{
    if(Alumnos.empty() || Grupos.empty()){
            cout<<"=================================================="<<endl;
            cout<<"\nPrimero debe ingresar a los alumnos y grupos."<<endl;
        }
        else{
        for(int i = 0; i < Alumnos.size(); i++)
        {
        float promedio = CalcularPromedio(Alumnos[i]);
        cout<<"======================================================"<<endl;
        cout<<"El promedio del alumno "<<Alumnos[i].nombre<<" es: "<<promedio<<endl;
        }
        //REPORTE 2
        cout<<"======================================================"<<endl;
        for (int g = 0; g < Grupos.size(); g++)
        {
            float promayor = -1;
            string mejoralumno = "";
        
        for (int i = 0; i < Alumnos.size(); i++)
        {
            float prom2 = CalcularPromedio(Alumnos[i]);

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
//REPORTE 3
    cout<<"======================================================"<<endl;
    for (int i = 0; i < Grupos.size(); i++) 
    {
        bool carreraRepetida = false;
        for (int j = 0; j < i; j++) 
        {
            if (Grupos[j].carrera == Grupos[i].carrera)
            {
            carreraRepetida = true;
            }
        }
        if (!carreraRepetida)
        {
            int totalAlumnos = 0;
            for (int a = 0; a < Alumnos.size(); a++)
            {
                for (int b = 0; b < Grupos.size(); b++)
                {
                    if (Alumnos[a].grupo == Grupos[b].nombre && Grupos[b].carrera == Grupos[i].carrera)
                    {
                        totalAlumnos++;
                        break;
                    }
                }
            }
            cout<<"La carrera "<<Grupos[i].carrera<<" tiene un total de "<<totalAlumnos<<" alumnos inscritos."<<endl;
        }
    }   
        }
        cout<<"======================================================"<<endl;
}

void guardarDatos(
    const vector<Alumno>& Alumnos, 
    const vector<Grupo>& Grupos,
    const vector<Maestro>& Maestros
)
{
    if (Alumnos.empty() && Grupos.empty() && Maestros.empty())
{
    cout<<"======================================================"<<endl;
    cout << "No hay datos registrados para guardar." << endl;
    cout<<"======================================================"<<endl;
    return;
}
    ofstream archivo("datosGenerales.txt");
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo para guardar los datos."<<endl;
    }
    else{
        cout<<"Archivo abierto correctamente."<<endl;

        archivo<<Alumnos.size()<<endl;
        for (size_t i = 0; i < Alumnos.size(); i++)
        {
            archivo<< Alumnos[i].nombre<<endl;
            archivo<<Alumnos[i].matricula<<endl;
            for (int j = 0; j < 3; j++)
            {
                archivo<<Alumnos[i].calificaciones[j]<<endl;
            }
            archivo<<Alumnos[i].grupo<<endl;
        }
        archivo<<Grupos.size()<<endl;
        for (size_t i = 0; i < Grupos.size(); i++)
        {
            archivo<<Grupos[i].nombre<<endl;
            archivo<<Grupos[i].carrera<<endl;
        }
        archivo<<Maestros.size()<<endl;
        for (size_t i = 0; i < Maestros.size(); i++)
        {
            archivo<<Maestros[i].nombre<<endl;
            archivo<<Maestros[i].materia<<endl;
            archivo<<Maestros[i].grupos.size()<<endl;
            for (size_t l = 0; l < Maestros[i].grupos.size(); l++)
            {
                archivo<< Maestros[i].grupos[l]<<endl;
            }
        }
        cout<<"Creando archivo"<<endl;
        cout<<"El archivo se ha creado correctamente."<<endl;
        cout<<"======================================================"<<endl;
    }
}
void cargarDatos(
    vector<Alumno>& Alumnos,
    vector<Grupo>& Grupos,
    vector<Maestro>& Maestros
)
{
    ifstream archivo("datosGenerales.txt");
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo para cargar los datos."<<endl;
        return;
    }
    else{
        Alumnos.clear(); Grupos.clear(); Maestros.clear();
        int cantidadAlumnos;
        archivo>> cantidadAlumnos;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < cantidadAlumnos; i++)
        {
            Alumno Alumno_Nuevo;
            getline(archivo, Alumno_Nuevo.nombre);
            archivo>> Alumno_Nuevo.matricula;
            for (int j = 0; j < 3; j++)
            {
                archivo>>Alumno_Nuevo.calificaciones[j];
            }
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, Alumno_Nuevo.grupo);
            Alumnos.push_back(Alumno_Nuevo);
        }
        int cantidadGrupos;
        archivo>> cantidadGrupos;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int m = 0; m < cantidadGrupos; m++)
        {
        Grupo Grupo_Nuevo;
        getline(archivo, Grupo_Nuevo.nombre);
        getline(archivo, Grupo_Nuevo.carrera);
        Grupos.push_back(Grupo_Nuevo);
        }
        int cantidadMaestros;
        archivo>> cantidadMaestros;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int l = 0; l < cantidadMaestros; l++)
        {
            Maestro Maestro_Nuevo;
            getline(archivo, Maestro_Nuevo.nombre);
            getline(archivo, Maestro_Nuevo.materia);
            int grupos_maestro;
            archivo >> grupos_maestro;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            for(int k = 0; k < grupos_maestro; k++)
            {
                string grupo;
                getline(archivo,grupo);
                Maestro_Nuevo.grupos.push_back(grupo);
            }
            Maestros.push_back(Maestro_Nuevo);
        }
        cout<<"Datos cargados correctamente"<<endl;
    }
}
void GenerarReporte(const vector<Alumno>& Alumnos){
    if (Alumnos.empty()) {
    cout << "No se encontraron alumnos para generar un reporte." << endl;
    return;
}
    ofstream archivo("reporteordenado.txt");
    if(!archivo.is_open())
    {
        cout<<"No se pudo crear el archivo: Reporte, intente nuevamente."<<endl;
        return;
    }
    else{
        vector<Alumno> Alumnos_Ordenados = Alumnos;
        for (int i = 0; i < Alumnos_Ordenados.size()-1; i++)
        {       
            for(int j = 0; j < Alumnos_Ordenados.size()-1-i;j++)
            {
            if(CalcularPromedio(Alumnos_Ordenados[j])< CalcularPromedio(Alumnos_Ordenados[j+1])){
                Alumno temporal = Alumnos_Ordenados[j];
                Alumnos_Ordenados[j] = Alumnos_Ordenados[j+1];
                Alumnos_Ordenados[j+1] = temporal;
            }
        }
        }
        for (int a = 0; a < Alumnos_Ordenados.size(); a++)
        {
            archivo<<"Nombre: "<<Alumnos_Ordenados[a].nombre<<endl;
            archivo<<"Matricula: "<<Alumnos_Ordenados[a].matricula<<endl;
            archivo<<"Grupo: "<<Alumnos_Ordenados[a].grupo<<endl;
            archivo<<"Promedio: "<<CalcularPromedio(Alumnos_Ordenados[a])<<endl;
            cout<<"======================================================"<<endl;
        }
        cout<<"Reporte generado correctamente."<<endl;
    }
}
int main()
{
    int opcion;
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
    cout<<"5. Guardar datos"<<endl;
    cout<<"6. Cargar datos"<<endl;
    cout<<"7. Generar reporte"<<endl;
    cout<<"8. Salir"<<endl;
    cout<<"Ingrese una opcion: ";cin>>opcion;

        switch (opcion)
        {
        case 1:
            capturarAlumnos(Alumnos);
            break;
        case 2:
            capturarGrupos(Grupos);
            break;
        case 3:
            capturarMaestros(Maestros);
            break;
        case 4:
            mostrarReportes(Alumnos, Grupos, Maestros);
            break;
        case 5:
            guardarDatos(Alumnos, Grupos, Maestros);
            break;
        case 6:
            cargarDatos(Alumnos, Grupos, Maestros);
            break;
        case 7:
            GenerarReporte(Alumnos);
            break;
        case 8:
            cout<<"Esta saliendo del menu"<<endl;
            break;
        default:
        cout<<"La opcion no se encuentra en el menu intente nuevamente"<<endl;
            break;
        }
    } while (opcion !=8);

    return 0;
}
