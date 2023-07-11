//Cycle Detection In Directed

bool cycleFound(int node,unordered_map<int,bool> &vis, unordered_map<int,bool> &dfsvis, unordered_map<int,list<int>> &adj){
    vis[node]=true;
    dfsvis[node]=true;
    for(auto neighbor : adj[node]){
        if(!vis[neighbor]){
            if(cycleFound(neighbor,vis,dfsvis,adj)) return true;
        }else if(dfsvis[nighbor]){
            return true;
        }
    }
    dfsvis[node]=false;
    return false;
}


int detectCycle(int n,vector<pair<int,int>>&edges){
    //create adjency List
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int,bool>vis;
    unordered_map<int,bool>dfsvis;
    //call dfs for all components
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycleFound(i,vis,dfsvis,adj)) return true;
        }
    }
    return false;
}