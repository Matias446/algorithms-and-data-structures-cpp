#include <iostream>
#include <climits>
#include "./adts/list_graph.cpp"
#include "./adts/minHeap.cpp"

using namespace std;

int* dijkstra(Graph* g, int origen) {
    int V = g->vertexCount();
    bool* visitado = new bool[V + 1];
    int* distancia = new int[V + 1];

    for (int i = 1; i <= V; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = false;
    }

    distancia[origen] = 0;
    MinHeap heap;
    heap.insertar(origen, 0);

    while (!heap.vacio()) {
        int u = heap.min();
        heap.borrarMinimo();
        if (visitado[u]) continue;
        visitado[u] = true;

        Iterator<Edge>* it = g->getNeighbors(u);
        while (it->hasNext()) {
            Edge e = it->next();
            int v = e.to;
            int peso = e.weight;

            if (distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                heap.insertar(v, distancia[v]);
            }
        }
    }

    return distancia;
}

int main() {
    int V, E;
    cin >> V >> E;

    ListGraph* g = new ListGraph(V);

    for (int i = 0; i < E; i++) {
        int v, w, c;
        cin >> v >> w >> c;
        g->addW(v, w, c);
    }

    int N;
    cin >> N;
    int* origenes = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> origenes[i];
    }

    for (int i = 0; i < N; i++) {
        int* dist = dijkstra(g, origenes[i]);
        for (int j = 1; j <= V; j++) {
            if (j == origenes[i] || dist[j] == INT_MAX)
                cout << -1 << endl;
            else
                cout << dist[j] << endl;
        }
    }

    return 0;
}