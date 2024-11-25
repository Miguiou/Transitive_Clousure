#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función para encontrar la clausura transitiva usando BFS
vector<vector<int>> transitiveClosureBFS(const vector<vector<int>>& graph) {
    int n = graph.size(); // Número de nodos
    vector<vector<int>> closure(n, vector<int>(n, 0)); // Matriz de clausura transitiva inicializada en 0

    // Realizamos BFS para cada nodo
    for (int start = 0; start < n; ++start) {
        queue<int> q;
        vector<bool> visited(n, false);

        // Iniciar BFS desde el nodo `start`
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // En la clausura, el nodo `start` puede alcanzar `current`
            closure[start][current] = 1;

            // Recorrer los vecinos del nodo actual
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    return closure;
}

int main() {
    // Ejemplo de grafo en formato de lista de adyacencia
    vector<vector<int>> graph = {
        {1},       // Nodo 0 conectado al nodo 1
        {2},       // Nodo 1 conectado al nodo 2
        {0, 3},    // Nodo 2 conectado al nodo 0 y 3
        {}         // Nodo 3 sin conexiones
    };

    // Obtener la clausura transitiva
    vector<vector<int>> closure = transitiveClosureBFS(graph);

    // Mostrar la matriz de clausura transitiva
    cout << "Clausura Transitiva (Matriz):\n";
    for (int i = 0; i < closure.size(); ++i) {
        for (int j = 0; j < closure[i].size(); ++j) {
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
