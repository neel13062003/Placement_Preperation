class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>>mpp;
        unordered_map<int,bool>vis;
        
        for(auto it : edges)
        {
             mpp[it[0]].push_back(it[1]);
             mpp[it[1]].push_back(it[0]);
             vis[it[0]] = false;
             vis[it[1]] = false;
        }

        queue<int>q;
        q.push(source);

        vis[source] = true;
        
        while(!q.empty()){
           int temp = q.front();
           q.pop();
           vector<int>vec = mpp[temp];
           for(int i = 0;i<vec.size();++i)
           {
              if(vis[vec[i]]==true) continue;
              else
              {
                 q.push(vec[i]);
                 vis[vec[i]] = true;
              }
            }
        }
        return vis[destination];
    }
};
