#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./adts/open_hash_map.cpp"


using namespace std;


int main(){
    int n;
    cout << "Inicio del programa." << endl;
    cout << "Ingrese un número entero (2 ≤ n ≤ 100000): " << endl;
    cin >> n;
    assert(n >= 2 && n <= 100000 && "Número inválido, debe estar en el rango [2, 100000]");
    cout << "Número ingresado correctamente: " << n << endl;

    OpenHashMap<string, int> mails(n);

    string email;
    int unicos = 0;
    int repetidos = 0;
    for (int i = 0; i < n; i++) {
        cin >> email;
        if(!mails.contains(email)) {
            mails.set(email, 1);
        }else{
            int count = mails.get(email);
            if(count == 1){
                repetidos++;
            }
            mails.set(email, count + 1);
        }
    }
    int total = mails.size();
    unicos = total - repetidos;
    cout << "total: " << total << endl;
    cout << "repetidos: " << repetidos << endl;
    cout << "unicos: " << unicos << endl;
    cout << unicos << endl;
    return unicos;
}
