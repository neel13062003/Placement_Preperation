#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(vector<int> adj[], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }
    return count;
}

int main() {
    // Enter your input here
    int n = 6; // number of nodes
    int m = 5; // number of edges
    vector<int> adj[n];
    int edges[m][2] = {{0,1},{1,2},{3,4},{4,5},{3,5}}; // edges
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int numConnectedComponents = countConnectedComponents(adj, n);
    cout << "Number of connected components: " << numConnectedComponents << endl;
    return 0;
}
