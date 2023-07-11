class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<n && i>=0 && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        vector<vector<int>>ans;   
            int n= grid.size();
            int m= grid[0].size();
            
            queue<pair<int,int>>q;
            q.push({sr,sc});
            int fresh=0,time=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    // if(grid[i][j]==2){
                        //push_into_queue
                        // q.push({i,j});
                    // }else if(grid[i][j]==1){
                    if(grid[i][j]==1){    
                        fresh++;
                    }
                }
            }
        if(fresh==0) return 0;
             //Start BFS Traversal - Because Here We Apply BFS as Well as multiple Rotten At starting possible
        while(!q.empty()){
            int q_size = q.size();
            int temp=0;
            while(q_size !=0){
                    
                pair<int,int> p =q.front();
                q.pop();
                    
                int x1= p.first;
                int y1= p.second;
                  
                int ax[4] = {1,-1,0,0};
                int ay[4] = {0,0,1,-1};
                   
                for(int i=0;i<4;i++){
                    int x = ax[i]+x1;
                    int y = ay[i]+y1;
                      
                    if(isValid(x,y,n,m,grid)){
                        temp++;
                        grid[x][y]=2;
                        q.push({x,y});
                    }   
                }
                q_size--;
            }
            if(temp!=0) time++;
        }
        
        vector<int>temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};