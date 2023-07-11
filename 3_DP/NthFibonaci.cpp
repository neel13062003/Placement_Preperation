class Solution {
public:
    
    //Recursive     TC-O(n) , SC-O(n) {Recursiive stack space}
    int solveRec(int n){
        if(n==0 || n==1) return n;
        if(n==2) return 1; 
        return solveRec(n-1) + solveRec(n-2) + solveRec(n-3); 
    }
    
    //Recursive + DP = memoization         TC-O(n) , SC-O(n)
    int solveMem(int n,vector<int>&dp){
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n]=solveMem(n-1,dp) + solveMem(n-2,dp) + solveMem(n-3,dp); 
    }
    
    //Iterative  + DP = tabulation         TC-O(n) , SC-O(n){ dp vector }
    int solveTab(int n){
        vector<int>dp(n+2,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
    
    
    //Space optimization = prev,prev2,curr variable  TC-O(n) , SC-O(1)
    int solveSpaceOpt(int n){
        int prevOfprevOfprev = 0;
        int prevOfprev=1;
        int prev=1;
        
        if(n==0) return 0;
        
        for(int i=3;i<=n;i++){
           int curr= prev + prevOfprev + prevOfprevOfprev;
           prevOfprevOfprev = prevOfprev;
           prevOfprev = prev;
           prev = curr; 
        }
        return prev;
    }
    
    int tribonacci(int n) {
         // return solveRec(n);
        
        // vector<int>dp(n+1,-1);
        // return solveMem(n,dp);
        
        // return solveTab(n);
        
        return solveSpaceOpt(n);
    }
};