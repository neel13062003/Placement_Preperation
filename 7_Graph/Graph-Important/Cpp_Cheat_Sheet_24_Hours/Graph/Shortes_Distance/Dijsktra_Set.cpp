#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

class Graph {
private:
    int n;
    vector<pair<int, int>> *adj;

public:
    Graph(int n) {
        this->n = n;
        adj = new vector<pair<int, int>>[n];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dijkstra(int src) {
        set<pair<int, int>> s;                      // {distance, node}
        vector<int> dist(n, INF);

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            int u = s.begin()->second;
            s.erase(s.begin());

            for (auto v: adj[u]) {
                int neighbor = v.first;
                int weight = v.second;

                if (dist[u] + weight < dist[neighbor]) {

                    auto record  = s.find({dist[neighbor] + neighbor});

                    //if(record found)
                    if(record != s.end()){
                        s.erase({dist[neighbor], neighbor});
                    }
                    
                    //distance update
                    dist[neighbor] = dist[u] + weight;
                    //record push in set
                    s.insert({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }
};

int main() {
    int n = 5;
    Graph g(n);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    int src = 0;
    vector<int> dist = g.dijkstra(src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}
