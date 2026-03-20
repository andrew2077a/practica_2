#include <iostream>
#include "librerias.h"

using namespace std;



int main(){
    int x,i=0;
    while (i<3){
        cout<<"Ingrese un problema"<<endl;
        cin>>x;
        switch(x){
        case 2:
            problem_2();
            break;
        case 4:
            problem_4();
            break;
        case 6:
            problem_6();
            break;
        case 8:
            problem_8();
            break;
        case 10:
            problem_10();
            break;
        default:
            cout<<"Ingreso un numero incorrecto"<<endl;
        }
        i+=1;
    }
}
