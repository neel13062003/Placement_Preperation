//Dijsktra not support negative edges
//Time Complexity - O(ElogV)
//Space Complexity - O(N+E)

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define INF INT_MAX // macro to represent infinity

typedef pair<int, int> pii; // pair of (node, distance)

void dijkstra(vector<vector<pii>>& adj, int start, vector<int>& dist) {
    int n = adj.size();
    //priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap of (distance, node)
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit all neighbors of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            // Relaxation step - update the distance if a shorter path is found
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n = 6; // number of nodes
    int start = 0; // starting node

    // Define the graph as an adjacency list of pairs (node, distance)
    vector<vector<pii>> adj(n);
    adj[0].push_back(make_pair(1, 5));
    adj[0].push_back(make_pair(2, 3));
    adj[1].push_back(make_pair(2, 2));
    adj[1].push_back(make_pair(3, 6));
    adj[2].push_back(make_pair(3, 7));
    adj[2].push_back(make_pair(5, 2));
    adj[3].push_back(make_pair(4, -1));
    adj[4].push_back(make_pair(5, -2));

    // Initialize the distance vector to infinity for all nodes except the starting node
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Run Dijkstra's algorithm
    dijkstra(adj, start, dist);

    // Print the distances from the starting node to all other nodes
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }

    return 0;
}
