#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int n,int m,int s,int t){
    //Adjacency List
    int V = n + 1;
    vector<int> adj[V];
    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        // adj[u].push_back({v, 1});
        adj[u].push_back(v);          //here weight is not given if given then take accoridngly
        adj[v].push_back(u);
    }

    // unorderd_map<int,list<int>>adj;
    // for(int i=0;i<edges.size();i++){
    //     int u = edges[i].first;
    //     int v = edges[i].second;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    //Do BFS
    vector<int> vis(V, 0);
    vector<int> parent(V, -1);

    queue<int> q;
    q.push(s);  //s=source node
    vis[s] = 1;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto it : adj[front]){
            int neighbor = it.first;
            if(!vis[neighbor]){
                vis[neighbor] = 1;
                parent[neighbor] = front;
                q.push(neighbor);
            }
        }
    }

    //Prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;        //node edges source destinaition

    vector<pair<int,int>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> path = shortestPath(edges, n, m, s, t);
    if(path.size() == 0) {
        cout << "No path found!" << endl;
    } else {
        for(int node : path) {
            cout << node << " ";
        }
    }
    return 0;
}
