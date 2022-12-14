#define _USE_MATH_DEFINES //Macro para valores matematicos
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int fn_suma(int x, int y){
    return (x+y);
}

double G2R(double a){        //Grados a radianes
    double r, M_PI;
    r=a*M_PI/180;
    return r;
}

double R2G (double a){
    double g,r, M_PI;
    g=r*180/M_PI;
    return g;
}
/*
double sin(double a){       //Función Seno
    double r;
    r=sin(G2R(a));
    return r;
}
*/
bool esBisiesto(int year){     //Programa año Bisiesto
    bool r=true;
    r=year%400==0||year%4==0&&year%100!=0;
    return r;
}

void jugada (int disco, int torre1, int torre2, int torre3){
    if(disco==1){
        cout<<"mover disco de "<<torre1<<" hacia la torre "<<torre3<<endl;
    }else{
        jugada(disco-1,torre1,torre3,torre2);
        cout<<"mover disco de "<<torre1<<" hacia la torre "<<torre3<<endl;
        jugada(disco-1,torre2,torre1,torre3);
    }
}

int main()
{
    char res;
    do{
    int torre1=1, torre2=2, torre3=3, disco=0;
    cout<<"Con cuantos discos quiere jugar?";
    cin>>disco;
    jugada(disco,torre1,torre2,torre3);
    cout<<"desea volver a jugar?";
    cin>>res;
    }while(res=='s');
    return 0;
}

