https://leetcode.com/problems/longest-ideal-subsequence/

//Link = https://leetcode.com/problems/longest-increasing-subsequence/ Base Problem

class Solution {
public:
    
    int solveRec(int n,vector<int>&nums,int curr,int prev,int k){
        if(curr == n) return 0;
        
        //include
        int take=0;
        if(prev == -1 || abs(nums[curr]-nums[prev])<=k  ) {
            take = 1 + solveRec(n,nums,curr+1,curr,k);
        }
        //exclude
        int notTake = 0 + solveRec(n,nums,curr+1,prev,k);
        return max(take,notTake);
    }
    
     int solveMem(int n,vector<int>&nums,int curr,int prev,vector<vector<int>>&dp,int k){
        if(curr == n) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1]; 
         
        //include
        int take=0;
        if(prev == -1 || abs(nums[curr]-nums[prev])<=k) {
            take = 1 + solveMem(n,nums,curr+1,curr,dp,k);
        }
        //exclude
        int notTake = 0 + solveMem(n,nums,curr+1,prev,dp,k);
        return dp[curr][prev+1] = max(take,notTake);
    }
    
    int solveTab(int n,vector<int>&nums,int k){
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int curr= n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev>= -1;prev--){
                //include
                int take=0;
                if(prev == -1 || abs(nums[curr]-nums[prev])<=k){
                    take = 1 + dp[curr+1][curr+1];
                }
                //exclude
                int notTake = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take,notTake);
            }
        }
        // return dp[0][-1+1];
        return dp[0][0];
    }
    
    int solveSpace(int n,vector<int>&nums,int k){
        vector<int> curr1(n+1,0);
        vector<int> next1(n+1,0);
        
        for(int curr= n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev>= -1;prev--){
                //include
                int take=0;
                if(prev == -1 || abs(nums[curr]-nums[prev])<=k){
                    take = 1 + next1[curr+1];
                }
                //exclude
                int notTake = 0 + next1[prev+1];
                curr1[prev+1] = max(take,notTake);
            }
            next1 = curr1;
        }
        return next1[0];
    }
    
    
    int solveOptimal(int n,vector<int>&nums,int k){
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(abs(nums[i]-ans.back())<=k) {
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    
    int bruteForce(string s,int k){
        int n = s.length();
        vector<int> dp(n, 1); // dp[i] represents the length of the longest ideal string ending at position i

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(s[i] - s[j]) <= k) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
    
    int longestIdealString(string s, int k) {
        
        vector<int>nums;
        for(int i=0;i<s.size();i++){
            nums.push_back(s[i]-'a');
        }
        
        
        // int n =nums.size();
        // return solveRec(n,nums,0,-1,k);
        
        //  int n =nums.size();
        //  vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(n,nums,0,-1,dp,k);
        
        // int n =nums.size();
        // return solveTab(n,nums,k);
        
        //  int n =nums.size();
        // return solveSpace(n,nums,k);
        
        // int n =nums.size();
        // return solveOptimal(n,nums,k);
         int dp[150] = {}, res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};

