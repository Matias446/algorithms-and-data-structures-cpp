#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int filas, columnas;
int **tablero;
int bloqueFilas, bloqueColumnas, k;
bool esSolucion = false;

bool puedoRealizarMovimiento(int f, int c, int num) {
    // 1) Fila
    for (int j = 0; j < columnas; j++)
        if (tablero[f][j] == num) return false;
    // 2) Columna
    for (int i = 0; i < filas; i++)
        if (tablero[i][c] == num) return false;
    // 3) Bloque
    int bf = (f / bloqueFilas) * bloqueFilas;
    int bc = (c / bloqueColumnas)   * bloqueColumnas;
    for (int i = 0; i < bloqueFilas; i++)
        for (int j = 0; j < bloqueColumnas; j++)
            if (tablero[bf + i][bc + j] == num)
                return false;
    return true;
}

void imprimirSolucion() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << tablero[i][j];
            if (j + 1 < columnas)
                cout << ' ';
            else
                cout << '\n';
        }
    }
}
void backtracking(int r, int c) {
    if (esSolucion) return;

    if (r == filas) {
        imprimirSolucion();
        esSolucion = true;
        return;
    }

    int nr;
    if (c + 1 == columnas) {
        nr = r + 1;
    } else {
        nr = r;
    }

    int nc;
    if (c + 1 == columnas) {
        nc = 0;
    } else {
        nc = c + 1;
    }

    if (tablero[r][c] != 0) {
        backtracking(nr, nc);
    }
    else {
        for (int num = 1; num <= k; num++) {
            if (puedoRealizarMovimiento(r, c, num)) { 
                tablero[r][c] = num; // Realizar el movimiento
                backtracking(nr, nc); // Backtracking
                tablero[r][c] = 0; // Deshacer el movimiento
                if (esSolucion) return;
            }
        }
    }
}

int main() {
    cin >> filas >> columnas;

    tablero = new int*[filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new int[columnas];
        for (int j = 0; j < columnas; j++)
            cin >> tablero[i][j];
    }

    bloqueFilas = filas / 3;
    bloqueColumnas = columnas / 3;
    k = bloqueFilas * bloqueColumnas;

    backtracking(0, 0);

    for (int i = 0; i < filas; i++) delete[] tablero[i];
    delete[] tablero;

    return 0;
}