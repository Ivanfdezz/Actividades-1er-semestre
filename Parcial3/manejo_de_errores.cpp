#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string nombre = "Archivo_de_prueba.txt";

    ifstream archivo("Archivo_de_prueba.txt");

    if (!archivo.is_open())
    {
        cout<<"Error: No se pudo abrir el archivo. Verifique que exista."<<endl;
        cout << "el archivo: "<<nombre<<" a fallado"<< endl;
    }
    else
    {
        cout<<"El archivo esta funcionando con normalidad.";
    }
    
    return 0;
}