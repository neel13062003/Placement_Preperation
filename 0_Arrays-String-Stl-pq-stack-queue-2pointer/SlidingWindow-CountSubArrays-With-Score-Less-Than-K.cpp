class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0,j=0, n = nums.size();
        long long count=0, currentSum=0;
        
        while(j<n){
            
            currentSum += nums[j];
            while( currentSum*(j-i+1)  >= k){
                currentSum -= nums[i];
                i++;
            }
            
            count += j-i+1;
            j++;
        }
        return count;
    }
};

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, long long k) {
//         long long cnt = 0, csum = 0; // csum = current sum
//         int i = 0, j = 0;
//         // initial condition
//         while(j < nums.size())
//         {
//             csum += nums[j];
//             // in sliding window questions, it is common to find
//             // the condition for removal of some i here, nums[i] and
//             // incrementing i. Here the condition is given clearly.
//             while(csum * (j - i + 1) >= k)
//             {
//                 // condition for removing i done? shorten the window
//                 csum -= nums[i];
//                 i++;
//             }
//             // increment count
//             cnt += (j - i + 1);
//             j++;
//         }
//         // return ans
//         return cnt;
//     }
// };
