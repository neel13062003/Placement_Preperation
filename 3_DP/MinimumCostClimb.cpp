class Solution {
public:
      
    int solveRec(vector<int>&cost,int n){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        
        return cost[n]+ min(solveRec(cost,n-1),solveRec(cost,n-2));
    }
    
    int solveMem(vector<int>&cost,int n,vector<int>&dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        
        if(dp[n] != -1)  return dp[n];
        
        return dp[n] = cost[n]+ min(solveMem(cost,n-1,dp),solveMem(cost,n-2,dp));
    }
    
    int solveTab(vector<int>&cost,int n){
        vector<int>dp(n+2,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<=n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }
    
    int solveSpace(vector<int>& cost, int n) {
        int prev2 = cost[0];
        int prev = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }

        return min(prev, prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int ans =  min(solveRec(cost,n-2) , solveRec(cost,n-1));
        // return ans;
        
        // vector<int>dp(n+1,-1);
        // int ans = min(solveMem(cost,n-1,dp) , solveMem(cost,n-2,dp));
        // return ans;
        
        // int ans = min(solveTab(cost,n-1), solveTab(cost,n-2));
        // return ans;
        
        int ans = solveSpace(cost,n);
        return ans;
    }
};
