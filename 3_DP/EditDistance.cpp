class Solution {
public:
    
    int solveRec(string &a, string &b,int i,int j){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        
        int ans=0;
        if(a[i]==b[j]) return solveRec(a,b,i+1,j+1);
        else {
            int insertAns = 1 + solveRec(a,b,i,j+1);
            int deleteAns = 1 + solveRec(a,b,i+1,j);
            int updateAns = 1 + solveRec(a,b,i+1,j+1);
            ans = min(insertAns,min(deleteAns,updateAns));
        }
        return ans;
    }
    
    int solveMem(string &a, string &b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        
        int ans=0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i]==b[j]) return solveMem(a,b,i+1,j+1,dp);
        else {
            int insertAns = 1 + solveMem(a,b,i,j+1,dp);
            int deleteAns = 1 + solveMem(a,b,i+1,j,dp);
            int updateAns = 1 + solveMem(a,b,i+1,j+1,dp);
            ans = min(insertAns,min(deleteAns,updateAns));
        }
        return dp[i][j]=ans;
    }
    
    
    int solveSpace(string &a, string &b){
        
        // vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        
        int maxi  = max(a.size(),b.size());
        
        vector<int>curr(maxi+1,0);
        vector<int>next(maxi+1,0);

        
        for(int j=0;j<b.length();j++){
           next[j] = b.length()-j;
        }
        
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                 curr[b.length()] = a.length()-i;
                int ans=0;
                if(a[i] == b[j]) ans = next[j+1];
                else{
                    int x = 1 + curr[j+1];
                    int y = 1 + next[j];
                    int z = 1 + next[j+1];
                    ans = min(x,min(y,z));
                }
                curr[j]=ans;
            } 
            next = curr;
        }
        
        return next[0];
    }
    
    int minDistance(string word1, string word2) {
        // return solveRec(word1,word2,0,0);
        
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // return solveMem(word1,word2,0,0,dp);
        
        // return solveTab(word1,word2,0,0);
        
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        return solveSpace(word1,word2);
    }
};