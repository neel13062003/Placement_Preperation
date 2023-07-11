//One Edge - if we reomve no. of connected componet increase
//O(N+E) = Time Complexity
//O(N) = Space Complexity

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check if edge is a bridge
            if (low[nbr] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        } else {  
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }       
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}

int main() {
    int v = 5, e = 5;
    vector<vector<int>> edges {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the given graph are: " << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
