class Solution {
public:
    //Sliding Window Technique
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) { // special case when k is 0 or 1
            return 0;
        }
        int count = 0;
        int left = 0; // left index of sliding window
        int product = 1; // product of elements in sliding window
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right]; // expand the sliding window by multiplying the current element
            while (product >= k) { // shrink the sliding window until the product is less than k
                product /= nums[left];
                left++;
            }
            count += (right - left + 1); // count the number of subarrays that end at the current index
        }
        return count;
    }
};