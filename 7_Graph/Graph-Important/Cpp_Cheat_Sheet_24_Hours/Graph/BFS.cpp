#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    
    //Number of Nodes=V , adjecely list=adj
    //Space Complexity = 0(3N)-O(N)-Queue+Vector+array
    //Time Complexity = O(Nodes + Total Digree(2E));
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
         int vis[V]={0};
         vis[0]=1;
         
         queue<int>q;
         q.push(0);       //assuming graph is 0 indexing.
         
         vector<int>bfs;
         while(!q.empty()){
             int node = q.front();
             q.pop();
             bfs.push_back(node);
             
             for(auto it:adj[node]){
                 if(!vis[it]){
                     vis[it]=1;
                     q.push(it);
                 }
             }
         }
         return bfs;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}