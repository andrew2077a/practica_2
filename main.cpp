#include <iostream>
#include <cstdlib>
#include <ctime>

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
            break;
        default:
            cout<<"Ingreso un numero incorrecto"<<endl;
        }
        i+=1;
    }
}
