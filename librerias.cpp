#include "librerias.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
void problem_2(){
    char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char arre[200];
    srand(time(0));
    int i,x,con=0,e;
    char *p=arr;
    for (i=0;i<200;i++){
        x = rand()%26;
        arre[i]=arr[x];
        cout<<arre[i];
    }
    cout<<endl;
    for (i=0;i<26;i++){
        for (e=0;e<200;e++){

            if (*p==arre[e]){
                con++;
            }
        }
        cout<<*p<<":"<<con<<endl;
        p++;
        con=0;
    }
}

void problem_4(){
    char a[100];
    cout << "Ingrese una cadena de caracteres numericos" << endl;
    cin >> a;

    int h = 0;

    for(int i = 0; a[i] != '\0'; i++){
        h = h * 10 + (a[i] - '0');
    }

    int *p = &h;

    cout << "El numero entero es " << h << " sumado mas dos es: " << *p + 2 << endl;
}

string mayusculas_minusculas(string a){
    char *p=&a[0];
    while(*p!='\0'){
        if (*p>=97&&*p<=122){
            *p-=32;
        }
        p+=1;
    }
    return a;

}
void problem_6(){
    string a,b;
    cout<<"Ingrese una cadena de caracteres: "<<endl;
    cin>>a;
    b= mayusculas_minusculas(a);
    cout<<"Original: " << a<<" En mayuscula: " << b<<endl;

}

string cadena(string a, string &b){
    char *p=&a[0];
    string e;
    while(*p!='\0'){
        if (*p >= 48 && *p <= 57){
            b+=*p;
        }
        else{
            e+=*p;
        }
        p+=1;
    }
    return e;
}

void problem_8(){
    string a,b,c;
    cout<<"Ingrese una cadena de caracteres: "<<endl;
    cin>>a;
    c = cadena(a,b);
    cout<<"Original: "<< a <<endl<< "Texto: "<< c << " Numero: "<< b<<endl;
}

int contar(string a){
    int b=0,c=1001;
    char *p=&a[0];
    while(*p!='\0'){
        switch (*p) {
        case 'M':
            if(c < 1000){
                b += 1000 - 2 * c;
            }
            else{
                b += 1000;
            }
            c = 1000;
            break;
        case 'D':
            if(c < 500){
                b += 500 - 2 * c;
            }
            else{
                b += 500;
            }
            c = 500;
            break;
        case 'C':
            if(c < 100){
                b += 100 - 2 * c;
            }
            else{
                b += 100;
            }
            c = 100;
            break;
        case 'L':
            if(c < 50){
                b += 50 - 2 * c;
            }
            else{
                b += 50;
            }
            c = 50;
            break;
        case 'X':
            if(c < 10){
                b += 10 - 2 * c;
            }
            else{
                b += 10;
            }
            c = 10;
            break;
        case 'V':
            if(c < 5){
                b += 5 - 2 * c;
            }
            else{
                b += 5;
            }
            c = 5;
            break;
        case 'I':
            if(c < 1){
                b += 1 - 2 * c;
            }
            else{
                b += 1;
            }
            c = 1;
            break;
        }
        p+=1;

    }
    return b;

}

void problem_10(){
    string a;
    int b;
    cout<<"Ingrese numeros romanos (en mayuscula)"<<endl;
    cin>>a;
    b= contar(a);
    cout<<" El numero ingresado fue: "<< a <<endl<<" Que corresponde a: "<< b<<endl;

}
