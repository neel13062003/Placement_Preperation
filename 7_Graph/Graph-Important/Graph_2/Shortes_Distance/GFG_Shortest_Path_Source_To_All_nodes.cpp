//{ Driver Code Starts
// Initial Template for C++

//Link = "https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1"
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> dist(N, -1); // initialize all distances to -1
       dist[src] = 0; // distance from source vertex to itself is 0
        
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]){
                if(dist[v] == -1){ // if v is not visited yet
                    dist[v] = dist[u] + 1; // update distance of v
                    q.push(v);
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends