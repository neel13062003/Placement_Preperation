https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/solutions/3803784/easy-c-approach-reverse-traverse-short-c-code/
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> nums2;
        for (auto &x : nums)
            nums2.push_back(x);

        // Perform the operation on the nums2 vector
        for (int i = nums2.size() - 1; i > 0; i--) {
            if (nums2[i - 1] <= nums2[i]) {
                nums2[i - 1] = nums2[i - 1] + nums2[i];
                nums2.erase(nums2.begin() + i); // Erase the i-th element from nums2
            }
        }

        // Return the maximum element from the resulting nums2 vector
        return *max_element(nums2.begin(), nums2.end());
    }
};
