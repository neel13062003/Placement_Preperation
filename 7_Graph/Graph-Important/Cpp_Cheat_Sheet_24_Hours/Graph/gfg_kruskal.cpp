//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    
    void makeSet(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    } 
    
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        sort(edges.begin(), edges.end(), cmp);
    
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent, rank, n);
    
        int minWeight = 0;
    
        for (int i = 0; i < edges.size(); i++) {
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int wt = edges[i][2];
    
            if (u != v) {
                minWeight += wt;
                unionSet(u, v, parent, rank);
            }
        }
        return minWeight;
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //convert to adjceny metrix
       vector<vector<int>> edges;
        for (int u = 0; u < V; u++) {
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i][0];
                int w = adj[u][i][1];
                edges.push_back({u, v, w});
            }
        }
        
        int minWeight = minimumSpanningTree(edges, V);
        
        return minWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends