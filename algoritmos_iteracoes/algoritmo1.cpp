// Exercicio para implementar:
// f(x) = x³ - 9x +3; I = [0,1]; E = 10⁻³
// Estimar o número de iterações



#include<iostream>
#include <stdlib.h>  
#include <time.h>
#include <cmath>

using namespace std;

int func(int a){
    int m =  pow(a, 3) - (9*a) + 3;
    return m;
}
// double func(int a){
//     double m = (((2*pow(a, 2)) + 2)/5);
//     return m;
// }
// double func(int a){
//     double m = sqrt(((5*a)- 1)/2);
//     return m;
// }
int main(){
    double a = 0;
    double b = 1;
    double e = 0.01;
    int k = 1;


    while(1){
        double x = (a+b)/2;
        double M = func(x);

        if (M*func(x) > 0) {
            a = x; 
        } else {
            b = x; 
        }

        if ((b - a) < e) {
            cout << "Número de iterações: " << k << endl;
            break; 
        }

        k++;
        
    }


    return 0;
}