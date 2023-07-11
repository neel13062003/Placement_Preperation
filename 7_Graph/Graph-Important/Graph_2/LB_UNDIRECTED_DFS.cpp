//Cycle Detection Problem - Concept of Parent.
#include <unorderd_map>
#include <list>
#include <queue>

//Space Complexity = vis(O(n)) + adj(O(n)) + recursivestackspace(O(n))= O(n) tIime Complexity = O(n)
bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &vis,unordered_map<int,list<int>>&adj){
    
    vis[node]=true;

    for(auto neighbor : adj[node]){
        if(!vis[neighbor]){
            if(isCyclicDFS(neighbor,node,vis,adj)) return true;
        }else if(neighbor!=parent){
            return true;   //cycle present.
        }
    } 
    return false;
}


bool cycleDetection(vector<vector<int>>&edges,int n,int m){
    //Create Adjecy List
    unordered_map<int,list<int>>adj;       //vector<int>adj[];
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //For Handle disconnected components
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCyclicDFS(i,vis,adj)) return true;
        }
    }
    return false;
}