#pragma once 

const int MAX_HEAP_SIZE = 10000;

struct Nodo
{
    int elemento;
    int prioridad;
};

class MinHeap
{
    private: 
    Nodo heap[MAX_HEAP_SIZE];
    int size; // Cantidad actual de elementos que hay en el heap 

    void swap(Nodo& a, Nodo& b) {
        Nodo temp = a;
        a = b;
        b = temp;
    }
    
    int padre(int i)
    {
        return (i - 1) / 2;
    }
    int izquierdo(int i)
    {
        return 2 * i + 1;
    }
    int derecho(int i)
    {
        return 2 * i + 2;
    }

    void flotar(int i)
    {
        while (i > 0 && heap[padre(i)].prioridad > heap[i].prioridad){
            swap(heap[i], heap[padre(i)]);
            i = padre(i);
        }
    }

    void hundir(int i){
        int menor = i;
        int izq = izquierdo(i); 
        int der = derecho(i);

        if(izq < size && heap[izq].prioridad < heap[menor].prioridad){
            menor = izq; 
        }
        if(der < size && heap[der].prioridad < heap[menor].prioridad){
            menor = der;
        }
        if(menor != i){
            swap(heap[i], heap[menor]);
            hundir(menor);
        }   
    }

    public:
    MinHeap(){
        size = 0;
    }

    bool vacio() const{
        return size == 0;
    }

    void insertar(int elemento, int prioridad){
        Nodo nuevoNodo;
        nuevoNodo.elemento = elemento;
        nuevoNodo.prioridad = prioridad;
        heap[size] = nuevoNodo;
        flotar(size);
        size++;
    }

    int min() const {
        return heap[0].elemento;
    }

    int prioMin() const {
        return heap[0].prioridad;
    }

    void borrarMinimo(){ //Borro el nodo con menor prioridad 
        if(vacio()) return;
        heap[0] = heap[size - 1]; //Size - 1 indica que reemplazo el nodo raiz con el ultimo nodo
        size--;
        hundir(0);
    }
}; 