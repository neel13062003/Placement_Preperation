#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    //Graph Representation using Adjecy Matrix
    int adjmatrix[n+1][n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjmatrix[u][v]=1;
        adjmatrix[v][u]=1;
    }

    //Using AdjecyList
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);       //if directed then it's line is commected
    }

    //BFS
    vector<int> bfsGraph(int V,vector<int>adj[]){

        int vis[V]={0};        //0 based indexing =  MEAns starts from 0
        vis[0]=1;
        queue<int>q;
        q.push(0);

        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
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


    //DFS
    private:

    void dfs(int node,vector<int>& adj[],int vis[] , vector<int>&ls){
        vis[node]=1;
        ls.push_back(node);
        //traverse all neighbours
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }

    public:
    vector<int> dfsOfGraph(int V,vector<int> adj[]){
        int vis[V]={0};
        int start=0;         //start from 0 because it is 0th based indexing graph
        vector<int>ls;
        dfs(start,adj,vis,ls);
        return ls;
    }






























    return 0;
}



















//bfs

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>bfs;
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int node=q.front();
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

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
// } Driver Code Ends












//dfs
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

  private:
    void dfs(int node, vector<int> adj[],int vis[]  ,vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        //traverse through node
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }


  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        //0th based indexing so
        int start=0;
        vector<int>ls;
        dfs(start, adj, vis  ,ls);
        return ls;
    }
};

//{ Driver Code Starts.
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
// } Driver Code Ends
