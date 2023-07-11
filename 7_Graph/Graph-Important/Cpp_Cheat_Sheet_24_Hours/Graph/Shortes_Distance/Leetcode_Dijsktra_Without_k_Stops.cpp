class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create the adjacency list from the given flights array
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight:flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        // Set up the priority queue and distance vector
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {cost, node, stops}
        vector<int> dist(n, INT_MAX);
        
        // Add the source node to the queue and set its distance to 0
        pq.push({0, src, 0});
        dist[src] = 0;
        
        // Perform Dijkstra's algorithm
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0], node = cur[1], stops = cur[2];
            
            // If we have reached the destination, return the cost
            if(node == dst) return cost;
            
            // If we have made k stops, continue to the next iteration
            if(stops > k) continue;
            
            // Visit all neighbors of the current node
            for(auto neighbor:adj[node]) {
                int v = neighbor.first, w = neighbor.second;
                if(cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v, stops+1});
                }
            }
        }
        
        // If we have not found a path to the destination, return -1
        return -1;
    }
};
