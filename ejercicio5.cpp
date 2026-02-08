#include <iostream>
#include "./adts/list_graph.cpp"
#include "./adts/graph.cpp"

using namespace std;

bool dfsCiclo(Graph* g, int u, bool* visitados, bool* enPila) {
    visitados[u] = true;
    enPila[u] = true;

    Iterator<Edge>* it = g->getNeighbors(u);
    while (it->hasNext()) {
        Edge e = it->next();
        int w = e.to;
        if (!visitados[w]) {
            if (dfsCiclo(g, w, visitados, enPila)) return true;
        } else if (enPila[w]) {
            return true;
        }
    }

    enPila[u] = false;
    return false;
}

bool tieneCiclo(Graph* g) {
    int V = g->vertexCount();
    bool* visitados = new bool[V + 1];
    bool* enPila = new bool[V + 1];

    for (int i = 1; i <= V; i++) {
        visitados[i] = false;
        enPila[i] = false;
    }

    for (int i = 1; i <= V; i++) {
        if (!visitados[i]) {
            if (dfsCiclo(g, i, visitados, enPila)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    ListGraph* g = new ListGraph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g->add(u, v);
    }

    if (tieneCiclo(g)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}