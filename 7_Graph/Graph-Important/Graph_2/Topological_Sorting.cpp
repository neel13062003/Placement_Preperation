//Using DFS
#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution{
	public:
	void toposort(int node, unordered_map<int,bool>&vis, stack<int>&st,vector<int> adj[]){
	//void toposort(int node,vector<bool>&vis, stack<int>&st,vector<int> adj[]){
	    vis[node]=1;
	    for(auto neighbor:adj[node]){
	        if(!vis[neighbor]){
	            toposort(neighbor,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    stack<int>st;
	    unordered_map<int,bool>vis;     //vector<bool>vis(V);
	    for(int i=0;i<V;i++){        //node starting from 
	        if(!vis[i]){
	            toposort(i,vis,st,adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        int ele = st.top();
	        ans.push_back(ele);
	        st.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends