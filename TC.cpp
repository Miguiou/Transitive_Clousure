#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir la matriz de adyacencia
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Función para calcular la clausura transitiva usando Floyd-Warshall
void transitiveClosure(vector<vector<int>>& graph) {
    int n = graph.size();

    // Aplicar el algoritmo de Floyd-Warshall para la clausura transitiva
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Si hay un camino de i a k y de k a j, entonces hay un camino de i a j
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {

    // Matriz de adyacencia inicial
    vector<vector<int>> graph = {
        {0, 0, 0, 0}, 
        {1, 0, 1, 0}, 
        {1, 0, 0, 1}, 
        {1, 0, 1, 0}, 
    };

    cout << "Matriz de adyacencia inicial:\n";
    printMatrix(graph);

    // Calcular la clausura transitiva
    transitiveClosure(graph);

    cout << "\nClausura transitiva del grafo:\n";
    printMatrix(graph);

    return 0;
}
