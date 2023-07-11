#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;       // node/vertices - edges


    //Time Complexity  = O(N) , Space complexity = O(N*N);
    int add[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v>>endl;
        add[u][v]=1;
        // add[v][u]=1;   // if directed means one directional then it not come
    }


    //O(2*E-E) = Space Complexity - Adjecey Metrix Method
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);         
        // adj[v].push_back(u);   if directed then it not come only one side edge
    }
    return 0;
}