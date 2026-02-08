#include <cassert>
#include <string>
#include <iostream>
#include <limits>


using namespace std;

struct Edificio{
    int I;
    int F;
    int H;
};

struct Par{
    int x;
    int h;
};

struct Resultado{
    Par* pares; 
    int cant; 
};

Resultado silueta(Edificio* edificios, int inicio, int fin){
    int medio = (inicio + fin) / 2;
    
    if(inicio == fin){
        Par* resultado = new Par[2];
        resultado[0].x = edificios[inicio].I;
        resultado[0].h = edificios[inicio].H;

        resultado[1].x = edificios[inicio].F;
        resultado[1].h = 0;
        
        Resultado res; 
        res.pares = resultado;
        res.cant = 2;
        return res; 
    }
    Resultado izquierdo = silueta(edificios, inicio, medio);
    Resultado derecho = silueta(edificios, medio + 1, fin);

    int i = 0; 
    int j = 0;
    int alturaDer = 0;
    int alturaIzq = 0;
    int alturaActual = 0;

    Par* res = new Par[izquierdo.cant + derecho.cant];
    int k = 0;

    while(i < izquierdo.cant && j < derecho.cant){
        if(izquierdo.pares[i].x < derecho.pares[j].x){
            alturaIzq = izquierdo.pares[i].h;
            int nuevaAltura = std::max(alturaIzq, alturaDer);
            if(nuevaAltura != alturaActual){
                res[k++] = {izquierdo.pares[i].x, nuevaAltura};
                alturaActual = nuevaAltura;
            }
            i++;
        }else if(derecho.pares[j].x < izquierdo.pares[i].x){
            alturaDer = derecho.pares[j].h;
            int nuevaAltura = std::max(alturaIzq, alturaDer);
            if(nuevaAltura != alturaActual){
                res[k++] = {derecho.pares[j].x, nuevaAltura};
                alturaActual = nuevaAltura;
            }
            j++;
        } else {
            alturaIzq = izquierdo.pares[i].h;
            alturaDer = derecho.pares[j].h;
            int nuevaAltura = std::max(alturaIzq, alturaDer);
            if(nuevaAltura != alturaActual){
                res[k++] = {izquierdo.pares[i].x, nuevaAltura};
                alturaActual = nuevaAltura;
            }
            i++;
            j++;
        }
    }

    while(i < izquierdo.cant){
        res[k++] = izquierdo.pares[i++];
    }
    while(j < derecho.cant){
        res[k++] = derecho.pares[j++];
    }
    Resultado final;
    final.pares = res;
    final.cant = k;
    return final;
}

int main()
{
    int N;
    cin >> N;

    Edificio* conjunto = new Edificio[N];
    for(int i=0; i<N; i++){
        cin >> conjunto[i].I >> conjunto[i].F >> conjunto[i].H;
    }

    Resultado resultado = silueta(conjunto, 0, N - 1);

    for(int i=0; i<resultado.cant; i++){
        cout << resultado.pares[i].x << " " << resultado.pares[i].h << endl;
    }
}

