#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./adts/closed_hash_map.cpp"
#include "./adts/open_hash_map.cpp"

using namespace std;

int main(){
    int n;
    int m;
    //cout << "Inicio del programa." << endl;
    //cout << "Ingrese un número entero (1 ≤ n ≤ 1000000): " << endl;
    cin >> n; 
    assert(n >= 1 && n <= 1000000 && "Número inválido, debe estar en el rango [1, 1000000]");

    string palabra;
    string consulta;
    Map<string, int> * diccionario = new ClosedHashMap<string, int>(n);
    int count = 0;
    for(int i = 0; i < n; i++){
        //cout << "Ingrese una palabra de máximo " << 20 << " caracteres: ";
        cin >> palabra;

        assert(palabra.length() <= 20 && "Palabra demasiado larga, debe tener un máximo de 20 caracteres.");
        diccionario->set(palabra, count);
        count++;
        //cout << "Palabra ingresada correctamente" << endl;
    }

    //cout << "Ingrese un número entero (1 ≤ m ≤ 1000000): " << endl;
    cin >> m;
    assert(m >= 1 && m <= 1000000 && "Número inválido, debe estar en el rango [1, 1000000]");

    for(int i=0; i < m; i++){
        //cout << "Ingrese una palabra de máximo " << 20 << " caracteres: " << endl;
        cin >> consulta;
        assert(consulta.length() <= 20 && "Palabra demasiado larga, debe tener un máximo de 20 caracteres.");
        if(diccionario->contains(consulta)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}

