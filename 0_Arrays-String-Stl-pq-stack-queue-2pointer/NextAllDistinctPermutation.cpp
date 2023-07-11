//Link =  https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    
     void display(vector<int>& nums, int n, vector<vector<int>>& ans){
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
    }

    void findPermutations(vector<int>& nums, int n, vector<vector<int>>& ans){
        sort(nums.begin(), nums.end());
        do{
            display(nums, n, ans);
        } while(next_permutation(nums.begin(), nums.end()));
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        findPermutations(nums, n, ans);

        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> finalAns(s.begin(), s.end());
        return finalAns;
    }
};