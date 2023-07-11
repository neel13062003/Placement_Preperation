//Link = https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    //TC= O(N*LOGN) SC=O(N)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        int prefSum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            int remove = prefSum-k;
            count += mp[remove];
            mp[prefSum]+=1;
        }
        return count;
    }
    
    //TLE - WorstCase O(N*N)
    // int count=0;
    // int subarraySum(vector<int>& nums, int k) {
    //     for(int i=0;i<nums.size();i++){
    //         int sum=0;
    //         for(int j=i;j<nums.size();j++){
    //             sum+=nums[j];
    //             if(sum==k){
    //               count++;  
    //             } 
    //         }
    //     }
    //     return count;
    // }
};