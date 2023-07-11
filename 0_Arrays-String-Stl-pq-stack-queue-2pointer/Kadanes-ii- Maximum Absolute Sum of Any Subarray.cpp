class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr1=0;
        int curr2=0;
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int i=0; i<nums.size(); i++){
            curr1+=nums[i]; curr2+=nums[i];
            
            if(curr1>mx)  mx=curr1;
            if(curr2<mn)  mn=curr2;
            if(curr1<0)   curr1=0;
            if(curr2>0)   curr2=0;
        }
        return max(abs(mn),mx);
    }
};