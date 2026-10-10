
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    float promedios[10][3];

    srand(time(0));

    for (int  i = 0; i < 10; i++)
    {
        promedios[i][0] = (rand() % 51 + 50) / 10.0;
        promedios[i][1] = (rand() % 51 + 50) / 10.0;

        if (promedios[i][0]>promedios[i][1])
        {
            promedios[i][2] = promedios[i][0];
        }
        else{
            promedios[i][2] = promedios[i][1];
        }
    }
        cout << fixed << setprecision(1);
        cout<<left<<setw(12)<<"--ALUMNO--"<<setw(12)<<"--GRUPO A--"<<setw(12)<<"--GRUPO B--"<<setw(18)<<"--PROMEDIO MAYOR--"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<left<<setw(12)<<i+1<<setw(12)<<promedios[i][0]<<setw(12)<<promedios[i][1]<<setw(18)<<promedios[i][2]<<endl;
    }
    
    return 0;
}

//CODIGO PARA INTRODUCIR MANUALMENTE LOS DATOS

/*
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float promedios[10][3];

    for (int  i = 0; i < 10; i++)
    {
        cout<<"Ingrese el promedio del alumno "<<i+1<<" del grupo A:"; cin>>promedios[i][0];
        cout<<"Ingrese el promedio del alumno "<<i+1<<" del grupo B:"; cin>>promedios[i][1];

        if (promedios[i][0]>promedios[i][1])
        {
            promedios[i][2] = promedios[i][0];
        }
        else{
            promedios[i][2] = promedios[i][1];
        }
    }
    
        cout<<left<<setw(12)<<"--ALUMNO--"<<setw(12)<<"--GRUPO A--"<<setw(12)<<"--GRUPO B--"<<setw(18)<<"--PROMEDIO MAYOR--"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<left<<setw(12)<<i+1<<setw(12)<<promedios[i][0]<<setw(12)<<promedios[i][1]<<setw(18)<<promedios[i][2]<<endl;
    }
    
    return 0;
}
*/