bool isCycleUtil(int v, vector<int> adj[], vector<bool>& visited, vector<bool>& recursionStack) {
    visited[v] = true;
    recursionStack[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            if (isCycleUtil(u, adj, visited, recursionStack)) {
                return true;
            }
        } else if (recursionStack[u]) {
            return true;
        }
    }
    recursionStack[v] = false;
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleUtil(i, adj, visited, recursionStack)) {
                return true;
            }
        }
    }
    return false;
}
