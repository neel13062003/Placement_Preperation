//Link  = https://leetcode.com/submissions/detail/963886402/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n = nums.size();
        while (n > 1) {
            vector<int> newNums(n - 1);
            for (int i = 0; i < n - 1; i++) {
                newNums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = newNums;
            n--;
        }
        return nums[0];
    }
};