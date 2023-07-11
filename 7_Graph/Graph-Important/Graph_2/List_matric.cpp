#include <iostream>
#include <vector>
using namespace std;

void printAdjMatrix(int** adjMatrix, int n) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printAdjList(vector<int> adjList[], int n) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    // Initialize the adjacency matrix and adjacency list
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    vector<int> adjList[n];
    
    // Read the edges from input and populate the adjacency matrix and adjacency list
    int u, v;
    for (int i = 0; i < m; i++) {
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // Print the graph using adjacency matrix and adjacency list
    printAdjMatrix(adjMatrix, n);
    printAdjList(adjList, n);
    
    // Free memory used by adjacency matrix
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    
    return 0;
}
