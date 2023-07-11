class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        // int count=0;
        // int n = nums.size();
        // while( nums[0]!=1 || nums[n-1]!=n){
        //     next_permutation(nums.begin(),nums.end());
        //     count++;
        // }
        // return count;
        
        //Previos for swapping condition is given you can swap adjecent ele only
        int ans=0;
        int n = nums.size();
        // int max_element = max_element(nums.begin(),nums.end());
        // int min_element = min_element(nums.begin(),nums.end());
        
        // Find the index of the maximum element
        auto maxElementIter = max_element(nums.begin(), nums.end());
        int maxElementIndex = distance(nums.begin(), maxElementIter);

        // Find the index of the minimum element
        auto minElementIter = min_element(nums.begin(), nums.end());
        int minElementIndex = distance(nums.begin(), minElementIter);
        
        
         cout << "Max Element: " << *maxElementIter << ", Index: " << maxElementIndex << endl;
         cout << "Min Element: " << *minElementIter << ", Index: " << minElementIndex << endl;

         if(nums[maxElementIndex]== n-1 && nums[minElementIndex]==1) ans=0; 
         else if(maxElementIndex <  minElementIndex ) ans = minElementIndex+ n - maxElementIndex-1-1;
         else ans= minElementIndex+ n - maxElementIndex-1;
        
        
        return ans;
        
    }
};

//Link  = https://leetcode.com/problems/semi-ordered-permutation/