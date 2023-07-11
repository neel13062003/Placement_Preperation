vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans;    
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }     
    return ans;
}



static bool cmp(pair<int,int>&A,pair<int,int>&B){
    return A.first<B.first;
}
    
vector<int> twoSum(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    vector<int>ans;
    vector<pair<int,int>>vec;
    for(int i=0;i<nums.size();i++){
        vec.push_back({nums[i],i});
    }
    sort(vec.begin(),vec.end(),cmp);
       
    while(left<=right){
        if( vec[left].first + vec[right].first == target ){
            ans.push_back(vec[left].second);
            ans.push_back(vec[right].second);
            break;
        }else if( vec[left].first+vec[right].first > target){
            right--;
        }else{
            left++;
        }
    }
    return ans;
}

vector<int> twoSum(vector<int>& nums, int target) {    
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])== mp.end()){
            mp[nums[i]]=i;
        }else{
            return {mp[target-nums[i]],i};
        }
    }  
    return {-1,-1};
}