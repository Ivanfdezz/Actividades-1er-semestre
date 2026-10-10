
#include <iostream>

using namespace std;

int main(){
    float calificaciones[6] ={0}, suma = 0, promedio;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese la calificacion numero "<< i + 1<<" :"; cin>>calificaciones[i];

        suma = suma + calificaciones[i];
    }
    promedio = suma / 5;
    calificaciones[5] = promedio;

    for (int i = 0 ; i < 6; i++)
    {
        if ( i == 5)
        {
            cout<<"El promedio del parcial es: "<<calificaciones[5]<<endl;
        }
        else{
            cout<<"\nLa calificacion del parcial "<<i + 1<<" es: "<<calificaciones[i]<<endl;
        }
        
    }
    
    return 0;
}