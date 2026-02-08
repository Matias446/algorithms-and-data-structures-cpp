#include <cassert>
#include <string>
#include <iostream>
#include <limits>

#include "./func/heap_sort_func.cpp"

using namespace std;

int main()
{
    int n;
    cout << "Inicio del programa." << endl;
    cout << "Ingrese un número entero (1 ≤ n ≤ 100000): " << endl;
    cin >> n; 
    int * conjunto = new int[n];
    cout << "Ingrese números enteros: ";
    for(int i = 0; i < n; i++){
        cin >> conjunto[i];
    }

    HeapSort<int> heapSort;
    heapSort.sortH(conjunto, n);

    //Impresion del conjunto ordenado en consola
    for (int i = 0; i < n; i++) {
        std::cout << conjunto[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}