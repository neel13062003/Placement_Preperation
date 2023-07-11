class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        vector<int> prev(n, -1);
        
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for(int j = 0; j < n; j++) {
                for(auto edge : adj[j]) {
                    int u = j, v = edge.first, w = edge.second;
                    if(dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                        temp[v] = dist[u] + w;
                        prev[v] = u;
                    }
                }
            }
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
