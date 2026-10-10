#include <iostream>
#include <string>   //Habilita el uso de string para manipular cadenas de texto
#include <cctype>  //proporciona fuentes para analizar caracteres
using namespace std;

int main(){
    string nombre_completo, nombre, apellido;
    

    cout<<"Ingrese su nombre completo: ";

    getline(cin, nombre_completo);  //lee hasta que se presiona enter

    int lugar = nombre_completo.find(" ");  //busca el primer espacio en los datos ingresados por el usuario en el string

    if (lugar == string::npos) // comprueba que .find no encontro espacio [(" ")]
    
    {
        cout<<"Debe ingresar un nombre y apellido.";
        return 0;
    }
    else{

    nombre = nombre_completo.substr(0,lugar);       //Extrae la cadena desde 0 hasta lugar. lugar = espacio
    apellido = nombre_completo.substr(lugar + 1);   //Extrae la cadena desde un espacio adelante del lugar 
        }
    bool nombre_valido = true;
    bool apellido_valido = true;
    

    for (int i = 0; i < nombre.length(); i++)     
    {
        if (isdigit(nombre[i]))                     //<-----------------
        {                                           //El for compruba si hay numeros en el nombre
            nombre_valido = false;
        }
        
    }
    for (int i = 0; i < apellido.length(); i++)
    {
        if (isdigit(apellido[i]))                   //<---------------
        {                                           //El for comprueba si hay numeros en el apellido
            apellido_valido = false;
        }
    }
    if (nombre_valido && apellido_valido)          //<---------------
    {                                              //El if actua solo si ambas condiciones son verdaderas
        cout<<"El nombre es valido."<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Apellidos: "<<apellido<<endl;
    }
    else{                                                                       //<--------------
        cout<<"El nombre es invalido porque contiene algun numero.";            //En caso contrario se muestra el else
    }
    
    return 0;
}
