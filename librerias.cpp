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
    char *p=&arr[0];
    for (i=0;i<200;i++){
        x = rand()%26;
        arre[i]=arr[x];
        cout<<arre[i];
    }
    cout<<endl;
    cout<<&p<<endl;
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
    char a[50];
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


void imprimir(char a[]) {
    char *p = a;
    cout << endl;
    while (*p != '\0') {
        if (*p == ',') {
            cout << " ";
        }
        else if (*p == ' ') {
            cout << endl;
        }
        else {
            cout << *p;
        }
        p++;
    }
    cout << endl;
}
//jii

bool matriz(char a[], int l, int an) {

    int **matriz = new int*[l];
    for (int i = 0; i < l; i++) {
        matriz[i] = new int[an];
    }

    int k = 0;
    int colsuma = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < an; j++) {
            int h = 0;
            while (a[k] != '\0' && (a[k] < '0' || a[k] > '9')) {
                k++;
            }
            while (a[k] >= '0' && a[k] <= '9') {
                h = h * 10 + (a[k] - '0');
                k++;
            }
            matriz[i][j] = h;
        }
    }

    for (int j = 0; j < an; j++) {
        colsuma += matriz[0][j];
    }

    bool magic = true;
    for (int i = 0; i < l; i++) {
        int sunfila = 0;
        for (int j = 0; j < an; j++) {
            sunfila += matriz[i][j];
        }
        if (sunfila != colsuma) {
            magic = false;
        }
    }

    for (int i = 0; i < l; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return magic;
}

void problem_12() {
    char a[100];
    int l, an;

    cout << "largo de la matriz" << endl;
    cin >> l;
    cout << "ancho de la matriz" << endl;
    cin >> an;

    cout << "Ponga los numeros separados con comillas, y un espacio para iniciar una nueva fila" << endl;
    cin.ignore();
    cin.getline(a, 100);

    imprimir(a);

    if (matriz(a, l, an)) {
        cout << "Es un cuadrado magico" << endl;
    }
    else {
        cout << "No es un cuadrado magico" << endl;
    }
}


void imprimir_matriz(int matriz[5][5]) {
    int *p = &matriz[0][0];
    for (int i = 0; i < 25; i++) {
        cout << *(p + i) << "\t";

        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
}

void rotar_90(const int matriz[5][5]) {
    int matrizrod[5][5];
    int *p= &matrizrod[0][0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizrod[j][4 - i] = matriz[i][j];
        }
    }
    cout << p;
    imprimir_matriz(matrizrod);
}

void rotar_180(int matriz[5][5]) {
    int matrizrod[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizrod[4 - i][4 - j] = matriz[i][j];
        }
    }
    imprimir_matriz(matrizrod);
}

void rotar_270(int matriz[5][5]) {
    int matrizrod[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizrod[4 - j][i] = matriz[i][j];
        }
    }
    imprimir_matriz(matrizrod);
}

void problem_14() {
    int matriz[5][5];
    int x = 1;

    for (int i = 0; i < 5; i++) {
        for (int e = 0; e < 5; e++) {
            matriz[i][e] = x++;
        }
    }

    cout << "matriz original" << endl;
    imprimir_matriz(matriz);
    cout<<endl;

    cout << "matriz 90 grados" << endl;
    rotar_90(matriz);
    cout<<endl;

    cout << "matriz 180 grados" << endl;
    rotar_180(matriz);
    cout<<endl;

    cout << "matriz 270 grados" << endl;
    rotar_270(matriz);
    cout<<endl;
}
long long factorial(int a){
    long long cont=1;
    for (int i=1;i<=a;i++){
        cont*=i;
    }
    return cont;
}
long long operacion(int a){
    long long e=2*a;
    long long c,res;
    e= factorial (e);
    c= factorial (a);
    res =(e/(c*c));
    return res;
}
void problem_16(){
    int a;
    long long b;
    cout<<"ingrese un numero n para calcular el numero de caminos posibles en una cuadricula de nxn. (hasta 10)"<<endl;
    cin >> a ;
    b= operacion(a);
    cout << "para una malla de "<<a<<"x"<<a<<" hay "<<b<< " caminos"<<endl;

}

void pos(long long n) {
    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = numeros;
    int tam = 10;
    n--;

    for(int i = 9; i >= 0; i--) {
        long long f = factorial(i);
        int indice = n / f;

        cout << *(p + indice);

        for(int j = indice; j < tam - 1; j++) {
            *(p + j) = *(p + j + 1);
        }
        tam--;
        n %= f;
    }
    cout << endl;
}

void problem_18(){
    long long n;
    cout << "Ingrese un numero n para hallar la enesima permutacion lexicografica de los numeros entre 0 y 9: " << endl;
    cin >> n;

    cout << "La permutacion numero " << n << " es: ";
    pos(n);
}
