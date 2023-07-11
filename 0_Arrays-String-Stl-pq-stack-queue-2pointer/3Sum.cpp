class Solution {
public:
    //O(N^2)
     vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end()); 
         
        for(int i=0;i<nums.size();i++){
            
            //To Stop print repeating
            if(i>=1 && nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
            
                if(sum < 0){
                    left++; continue;
                }
                else if(sum > 0){
                    right --; continue;
                }else if(sum == 0){

                    vector<int>temp;
                    temp.push_back(nums[left]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[right]);
                    
                    ans.push_back(temp);

                    while(left < right  && nums[left]==nums[left+1]) left++;
                    while(left < right  && nums[right]==nums[right-1]) right--;
                }
                left++;
                right--;
            }  
        }
         return ans;
    }
};

























//TLE = o(N^3)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>>vec;
//         set<vector<int>> s;
        
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(i!=j){
//                     for(int k=j+1;k<nums.size();k++){
//                        if(i!=k && j!=k){
//                            if(nums[i]+nums[j]+nums[k]==0){
//                               vector<int> triplet = {nums[i], nums[j], nums[k]};
//                               sort(triplet.begin(), triplet.end()); // Sorting to maintain ascending order
//                               s.insert(triplet);
//                            }
//                        }
//                     }
//                 }
//             }
//         }
        
//         for (auto it = s.begin(); it != s.end(); ++it) {
//             vec.push_back(*it);
//         }
        
//         return vec;
//     }
// };