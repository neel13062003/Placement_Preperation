// Study = https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=ans;
    
        for(int i=1;i<nums.size();i++){
            if(sum<0) sum=0;
            sum += nums[i]; 
            ans = max(sum,ans);
        }
        
        return ans;
    }
};