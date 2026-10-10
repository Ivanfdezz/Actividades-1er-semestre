
#include <iostream>

using namespace std;

void cambiar(int&x, int&y)
{
    int temporal = x;
    x = y;
    y = temporal;
}

int main(){
    int a = 20, b = 30;

    cout<<"Primeros valores: a = "<<a<<" y b = "<<b<<endl;

    cambiar(a,b);

    cout<<"Despues del cambio a = "<<a<<" y b = "<<b<<endl;

    return 0;
}