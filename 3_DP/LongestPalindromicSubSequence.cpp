class Solution {
public:
    
    int solveRec(string &a,string &b,int i,int j){
        if(i==a.length()) return 0;
        if(j==b.length()) return 0;

        int ans=0;
        if(a[i]==b[j]) ans = 1 + solveRec(a,b,i+1,j+1);
        else{
            ans = max(solveRec(a,b,i+1,j),solveRec(a,b,i,j+1));
        }
        return ans;
    }
    int solveMem(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()) return 0;
        if(j==b.length()) return 0;

        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans=0;
        if(a[i]==b[j]) ans = 1 + solveMem(a,b,i+1,j+1,dp);
        else{
            ans = max(solveMem(a,b,i+1,j,dp),solveMem(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    
    int solveTab(string &a,string &b,int i,int j){
       vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
      
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]) ans = 1+ dp[i+1][j+1];
                else ans = max(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=ans;
            }
        }
        
       return dp[0][0]; 
    }
    
    int solveSpace(string &a,string &b,int i,int j){
       // vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        
       int maxi = max(a.length(),b.length()); 
       vector<int> curr(maxi+1,0);
       vector<int> next(maxi+1,0); 
        
        
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]) ans = 1+ next[j+1];
                else ans = max(next[j],curr[j+1]);
                curr[j]=ans;
            }
            next = curr;
        }
        
       return next[0]; 
    }
    
    int longestPalindromeSubseq(string s) {
        
         string strRev = s;
         reverse(strRev.begin(),strRev.end());
         
        
         string text1 = s;
         string text2 = strRev;
         
         // return solveRec(text1,text2,0,0);
        
        // int n = text1.size(); int m = text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solveMem(text1,text2,0,0,dp);
        
        //return solveTab(text1,text2,0,0);
        
        
        return solveSpace(text1,text2,0,0);
    }
};