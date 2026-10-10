
#include <iostream>

using namespace std;

void cambiar(int* x, int* y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}

int main(){
    int a = 20, b = 30;

    int* ptrA = &a;
    int* ptrB = nullptr;          /*<---- la linea no funciona porque al puntero (prtB) se le asigno nullptr, el cual 
                                           anula el puntero y no permite que se ejecute correctamente.
                                           Se puede arreglar muy facilmente ya que solo consiste en cambiar el valor de ptrB por (ptrB = &b)*/

    cout<<"Primeros valores: a = "<<a<<" y b = "<<b<<endl;

    cambiar(ptrA, ptrB);

    cout<<"Despues del cambio a = "<<a<<" y b = "<<b<<endl;

    return 0;
}


//CODIGO ARREGLADO


/*#include <iostream>

using namespace std;

void cambiar(int* x, int* y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}

int main(){
    int a = 20, b = 30;

    int* ptrA = &a;
    int* ptrB = &b;          

    cout<<"Primeros valores: a = "<<a<<" y b = "<<b<<endl;

    cambiar(ptrA, ptrB);

    cout<<"Despues del cambio a = "<<a<<" y b = "<<b<<endl;

    return 0;
}*/