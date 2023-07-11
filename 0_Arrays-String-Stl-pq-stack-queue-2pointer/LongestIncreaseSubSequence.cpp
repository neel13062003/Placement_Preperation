//Dp With Binary Search = Same With Russian doller = https://youtu.be/MYHajVcnXSA{love babbar}

class Solution {
public:
    
    
    int solveRec(int n,vector<int>&nums,int curr,int prev){
        if(curr == n) return 0;
        
        //include
        int take=0;
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1 + solveRec(n,nums,curr+1,curr);
        }
        //exclude
        int notTake = 0 + solveRec(n,nums,curr+1,prev);
        return max(take,notTake);
    }
    
     int solveMem(int n,vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr == n) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1]; 
         
        //include
        int take=0;
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1 + solveMem(n,nums,curr+1,curr,dp);
        }
        //exclude
        int notTake = 0 + solveMem(n,nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(take,notTake);
    }
    
    int solveTab(int n,vector<int>&nums){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
        
        for(int curr= n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev>= -1;prev--){
                //include
                int take=0;
                if(prev == -1 || nums[curr]>nums[prev]){
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
    
    int solveSpace(int n,vector<int>&nums){
        vector<int> curr1(n+1,0);
        vector<int> next1(n+1,0);
        
        for(int curr= n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev>= -1;prev--){
                //include
                int take=0;
                if(prev == -1 || nums[curr]>nums[prev]){
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
    
    
    int solveOptimal(int n,vector<int>&nums){
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // return solveRec(n,nums,0,-1);
        
        // int n =nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));        //curr,prev so 2dp
        // return solveMem(n,nums,0,-1,dp);
        
        // int n =nums.size();
        // return solveTab(n,nums);
        
        //  int n =nums.size();
        // return solveSpace(n,nums);
        
        int n =nums.size();
        return solveOptimal(n,nums);
    }
};