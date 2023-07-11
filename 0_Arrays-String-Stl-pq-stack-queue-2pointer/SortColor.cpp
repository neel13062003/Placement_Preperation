class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count0++;
            if(nums[i]==1) count1++;
            if(nums[i]==2) count2++;
        }
        
        int n =nums.size();
        int j=0;
        while(j<n){
            while(count0--){
                nums[j] = 0;
                j++;
            }
            while(count1--){
                nums[j] = 1;
                j++;
            }
             while(count2--){
                nums[j] = 2;
                j++;
            }
        }
    }
};