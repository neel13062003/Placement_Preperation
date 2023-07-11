//Cycle Detection Problem - Concept of Parent.
#include <unorderd_map>
#include <list>
#include <queue>


bool isCyclicBFS(int src,unordered_map<int,bool> &vis,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent[src]=-1;
    vis[src]=-1;

    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbor :adj[front]){
            if(vis[neighbor]== true &&  neighbor!=parent[front]){
                return true;
            }else if(!vis[neighbor]){
                q.push(neighbor);
                vis[neighbor]=1;
                parent[neighbor]=front;
            }
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
            if(isCyclicBFS(i,vis,adj)) return true;
        }
    }
    return false;
}