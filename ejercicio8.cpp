#include <cassert>
#include <string>
#include <limits>
#include <iostream>
using namespace std;

// Modo recursivo:
// bool caracterCoincide(char pc, char tc) {
//     return pc == '.' || pc == tc;  // '.' es comodín
// }

// bool coincideRec(string t, string p, int i, int j) {
//     int n = t.length();      // largo del texto
//     int m = p.length();      // largo del patrón

//     // Caso base: patrón agotado
//     if (j == m)
//         return (i == n);

//     // ¿Coincide el primer carácter de ambos sufijos?
//     bool primerCoincide =
//         (i < n) &&
//         caracterCoincide(p[j], t[i]);

//     // ¿El segundo carácter del patrón es '*'?
//     if (j + 1 < m && p[j + 1] == '*') {
//         // Opción A: usar '*' 0 veces
//         bool usarCeroVeces = coincideRec(t, p, i, j + 2);
//         // Opción B: usar '*' ≥1 veces
//         bool usarAlMenosUna = primerCoincide && coincideRec(t, p, i + 1, j);
//         return usarCeroVeces || usarAlMenosUna;
//     }
//     else {
//         // Sin '*' avanzo uno en ambos
//         return primerCoincide && coincideRec(t, p, i + 1, j + 1);
//     }
// }

// int main() {
//     string texto, patron;
//     cin >> texto >> patron;

//     bool resultado = coincideRec(texto, patron, 0, 0);

//     if (resultado) {
//          cout << "true";
//     } else {
//          cout << "false";
//     }
//     cout << '\n';
//     return 0;
// }


//Memoization:

bool caracterCoincide(char pc, char tc) {
    return pc == '.' || pc == tc;  // '.' es comodín
}

int** memo;

bool coincideRec(string t, string p, int i, int j) {
    int n = t.length();
    int m = p.length();

    // Si ya lo exploramos, devolvemos lo que guardamos
    if (memo[i][j] != -1)
        return memo[i][j];

bool resultado;
    if (j == m) { // Caso base: patrón agotado
        resultado = (i == n);
    }
    else { // ¿Coincide el primer carácter?
        bool primerCoincide = (i < n) && caracterCoincide(p[j], t[i]);
        // ¿El siguiente es '*'?
        if (j + 1 < m && p[j + 1] == '*') {
            bool usarCeroVeces = coincideRec(t, p, i, j + 2);
            bool usarAlMenosUna = primerCoincide && coincideRec(t, p, i + 1, j);
            resultado = usarCeroVeces || usarAlMenosUna;
        }
        else {
            resultado = primerCoincide && coincideRec(t, p, i + 1, j + 1);
        }
    }

    memo[i][j] = resultado;
    return resultado;
}

int main() {
    string texto;
    string patron;
    cin >> texto >> patron;

    int n = texto.length();
    int m = patron.length();

    memo = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = new int[m+1];
        for (int j = 0; j <= m; j++) {
            memo[i][j] = -1;
        }
    }

    bool resultado = coincideRec(texto, patron, 0, 0);
    if (resultado) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << '\n';

    return 0;
}