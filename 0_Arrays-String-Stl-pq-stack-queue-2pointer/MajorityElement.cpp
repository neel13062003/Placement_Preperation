class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if( (it->second) > nums.size()/3 ){
                ans.push_back(it->first); 
            }
        }
        return ans;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        int maxie=nums[0];
        for(auto it:mp){
            if(it.second > maxi){
                maxi = it.second;
                maxie = it.first;
            }
        }
        return maxie;
    }
};