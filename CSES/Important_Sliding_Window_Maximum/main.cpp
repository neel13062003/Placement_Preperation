//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque<int>q;
        // int n=nums.size();
        // int i=0,j=0;
        // vector<int>res;
        // while(j<n){
        //     while(!q.empty() && q.back()<nums[j]) q.pop_back();
        //     q.push_back(nums[j]);
        //     if(j-i+1<k) j++;
        //     else if(j-i+1==k){
        //         res.push_back(q.front());
        //         if(q.front()==nums[i]) q.pop_front();
        //         i++;
        //         j++;
        //     }
        // }
        // return res;
        multiset<int> s;
        vector<int> ret;
        for (int i = 0; i < k; i++) { s.insert(nums[i]); }
        for (int i = k; i < nums.size(); i++) {
            ret.push_back(*s.rbegin());
            s.erase(s.find(nums[i - k]));
            s.insert(nums[i]);
        }
        ret.push_back(*s.rbegin());
        return ret;
    }
};
