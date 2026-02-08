#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int nueveTab(int N, int S, int L, int* tamanios, int* lineas, int* puntos){  //Pasar 3 punteros
    int*** tab = new int**[N + 1];
    for (int i = 0; i <= N; ++i) {
        tab[i] = new int*[S + 1];
        for (int j = 0; j <= S; ++j) {
            tab[i][j] = new int[L + 1];
            for (int k = 0; k <= L; ++k) {
                tab[i][j][k] = 0;
            }
        }
    }

    for(int i=1; i<=N; i++){
        int t = tamanios[i -1];
        int l = lineas[i - 1];
        int p = puntos[i - 1];

        for(int j=0; j<=S; j++){
            for(int k=0; k<=L; k++){
                tab[i][j][k] = tab[i - 1][j][k]; 
                if (j >= t && k >= l) {
                    tab[i][j][k] = std::max(tab[i][j][k], tab[i - 1][j - t][k - l] + p);
                }
            }
        }

    }
    return tab[N][S][L];
}

int main()
{
    int N;
    int S;
    int L;
    cin>>N;
    cin>>S;
    cin>>L;

    int* t = new int[N];
    int* l = new int[N];
    int* p = new int[N];

    for(int i=0; i<N; i++){
        cin>>t[i]>>l[i]>>p[i];
    }
    
    int res = nueveTab(N, S, L, t, l, p);
    cout<<res<<endl;
    return 0;
}



