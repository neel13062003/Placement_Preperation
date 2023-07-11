//Logic = 1) Topological Sort -> Tranpose -> Count of DFS


void dfs(int node,vector<int>&vis,stack<int>&st, unordered_map<int,list<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}

void dfs1(int node,vector<int>&vis, unordered_map<int,list<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
}

int StronglyConnectedComponent(int v,vector<vector<int>>&edges){
    //Adjcey List
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //Topological sort
    stack<int>st;
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    //In Stack Topological Sort Ready

    //Create A tranpose graph
    unordered_map<int,list<int>>transponse;
    for(int i=0;i<v;i++){
        for(auto nbr:adj[i]){
            transponse[nbr].push_back(i);
        }
    }


    //DFS call using above ordering
    int count=0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            dfs1(top,vis,transponse);         //here i pass transponse
            count++;
        }
    }
    return count;
}