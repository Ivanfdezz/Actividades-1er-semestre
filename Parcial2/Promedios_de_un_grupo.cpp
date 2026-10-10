
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    float grupo1[5] = {0}, grupo2[5] = {0}, altos[5]={};

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
            grupo1[i] = (rand() % 51 + 50) / 10.0;

        cout<<"Digite la calificacion del alumno "<<i + 1<<" del grupo 1: "<<grupo1[i]<<endl;
    }
        cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        grupo2[i] = (rand() % 51 + 50) / 10.0;

        cout<<"Digite la calificacion del alumno "<<i + 1<<" del grupo 2: "<<grupo2[i]<<endl;
    }
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        if (grupo1[i] > grupo2[i])
        {
            altos[i] = grupo1[i];
        }
        else{
            altos[i] = grupo2[i];
        }
        
    }
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"El promedio mas alto de los grupos en la posicion "<<i + 1<<" fue: "<<altos[i]<<endl;
    }

    return 0;
}


//CODIGO PARA INTROCIR MANUALMENTE LOS DATOS:

/*#include <iostream>

using namespace std;

int main(){
    float grupo1[5] = {0}, grupo2[5] = {0}, altos[5]={};

    for (int i = 0; i < 5; i++)
    {
        cout<<"Digite la calificacion del alumno "<<i + 1<<" del grupo 1: "; cin>>grupo1[i];
    }
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Digite la calificacion del alumno "<<i + 1<<" del grupo 2: "; cin>>grupo2[i];
    }
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        if (grupo1[i] > grupo2[i])
        {
            altos[i] = grupo1[i];
        }
        else{
            altos[i] = grupo2[i];
        }
        
    }
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"El promedio mas alto de los grupos en la posicion "<<i + 1<<" fue: "<<altos[i]<<endl;
    }

    return 0;
}
*/