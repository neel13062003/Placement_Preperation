#include <bits/stdc++.h>
using namespace std;

class Solution {
    //Space Complexity = 0(N)nodes+ O(N)vis + StackSpace O(N) = O(N)        
    //Time Complexity = O(N + AllNeibours-2E)    
        
 private:
    void dfsTraversal(int node,vector<int>&dfs,int vis[],vector<int>adj[]){
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfsTraversal(it,dfs,vis,adj);
            }   
        }
    }
    
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        int start = 0;       //0-based indexing;
        vector<int> dfs;
        dfsTraversal(start,dfs,vis,adj);
        return dfs;
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}