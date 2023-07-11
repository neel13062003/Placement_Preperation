class Solution {
public:
    
    int solveRec(vector<int>& arr,int n){
        //Base Case
        if(n<0) return 0;
        if(n==0) return arr[0];
        
        int include = solveRec(arr,n-2) + arr[n];
        int exclude = solveRec(arr,n-1) + 0;
        
        return max(include,exclude);
    }
    
    int solveMem(vector<int>& arr,int n,vector<int>&dp){
        //Base Case
        if(n<0) return 0;
        if(n==0) return arr[0];
        
        if(dp[n] != -1) return dp[n];
        
        int include = solveMem(arr,n-2,dp) + arr[n];
        int exclude = solveMem(arr,n-1,dp) + 0;
        
        return dp[n]=max(include,exclude);    
    }
    
    int solveTab(vector<int>& arr,int n){
        vector<int>dp(n+1,0);
        dp[0]= arr[0];
        for(int i=1;i<=n;i++){
            int include = dp[i-2]+ arr[i];
            int exclude = dp[i-1]+ 0;
            dp[i] = max(include,exclude);
        }
        return dp[n];
    }
    
    int solveSpace(vector<int>& arr,int n){
        // vector<int>dp(n+1,0);
        // dp[0]= arr[0];
        
        int prev2 = 0;
        int prev = arr[0];
        
        for(int i=1;i<=n;i++){
            int include = prev2 + arr[i];
            int exclude = prev + 0;
            int ans = max(include,exclude);
            prev2 = prev;
            prev = ans;
        }
        return prev;
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
         //Because index is 0based
        // return solveRec(nums,n-1);
        
        // vector<int>dp(n+1,-1);
        // return solveMem(nums,n-1,dp);
        
        // if(n<=0) return 0;
        // return solveTab(nums,n-1);
        
        if(n<=0) return 0;
        return solveSpace(nums,n-1);
    }
};