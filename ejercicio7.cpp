#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    string numero;
    cin >> numero;

    int frecuencia[10] = {0}; //Frecuencia de los numeros del 0 al 9 por eso es de tamaño 10
    for(int i=0; i < numero.length(); i++){
        int digito = numero[i] - '0';
        frecuencia[digito]++;
    }

    int cantImp = 0;
    int digitoImpar = -1;
    string mitad = "";

    for(int i=0; i<10; i++){
        if(frecuencia[i] % 2 == 1){
            cantImp++;
            digitoImpar = i;
        }
    }

    if(cantImp>1){
        cout << "No" << endl;
        return 0;
    }

    for(int i=9; i>=0; i--){
        for(int j=0; j < frecuencia[i] / 2; j++){
            mitad += (char)('0' + i);
        }
    }

    string palindromo = mitad;

    if(digitoImpar != -1){
        palindromo += (char)('0' + digitoImpar);
    }
    
    for(int i = mitad.length() - 1; i>=0; i--){
        palindromo += mitad[i];
    }

    cout << palindromo << endl;
    
    return 0;
}