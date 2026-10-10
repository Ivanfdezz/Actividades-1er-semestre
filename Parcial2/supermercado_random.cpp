#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    float ventas[100], total = 0;
    int i;

    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        ventas[i] = (rand() % 1000000 + 100) / 100.0;

        total = total + ventas[i];

        cout<<"Venta del cliente "<<i + 1<<" : "<<ventas[i]<<endl;
    }
        
        cout<<"El total es: "<<total<<endl;

    return 0;
}

//CODIGO PARA QUE EL USUARIO INGRESE LAS VENTAS MANUALMENTE

/*#include <iostream>

using namespace std;

int main(){
    float ventas[100], total = 0;

    for (int i = 0; i < 100; i++)
    {
        cout<<"Ingrese la venta del cliente "<<i+1<<" :"; cin>>ventas[i];

        total = total + ventas[i];
    }
        cout<<"El total es: "<<total<<endl;

    return 0;
}
*/