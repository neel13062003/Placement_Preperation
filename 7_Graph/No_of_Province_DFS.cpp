
class Solution {
    private:
    void dfs(int node,int vis[], vector<int>adjli[]){
        vis[node]=1;
        for(auto x: adjli[node]){
            if(!vis[x]){
                dfs(x,vis,adjli);
            }
        }
    }
      
    
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        //I needed Adjcency List
        vector<int>adjli[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjli[i].push_back(j);
                    adjli[j].push_back(i);
                }
            }
        }
        
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjli);
            }
            
        }
        
        return cnt;
        
        
    }
};