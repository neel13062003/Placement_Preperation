//Code : Neel Soni
//O(nlogn) = Two Pointer
//https://leetcode.com/contest/weekly-contest-358/problems/max-pair-sum-in-an-array/
class Solution {
private:

    static bool cmp(pair<int,int>&A,pair<int,int>&B){
        return A.second>B.second || (A.second == B.second && A.first > B.first);
    }

    int large(int n){ //finding largest digit of the number
        int largest = -1;
        while(n){
            int rem = n % 10;
            largest = max(largest, rem);
            n = n/10;
        }
        return largest;
    }

public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vec(n+1);
        for(int i=0;i<n;i++){
            int x = large(nums[i]);
            vec.push_back({nums[i],x});
        }

        sort(vec.begin(),vec.end(),cmp);
        int ans = -1;
        int maxans = 0;

        cout<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].first<<" ";
        }
        cout<<endl;

        if(n<2){
            return -1;
        }else{

            int left=0;
            int right = left+1;
            int p = 0;
            for(int i=0;i<vec.size();i++){
                if(vec[left].second == vec[right].second &&  p != vec[left].second ){
                     maxans = vec[left].first + vec[right].first;
                     ans = max(ans,maxans);
                     p = vec[left].second;
                }else{
                    left = i;
                    right = left+1;
                    if(vec[left].second == vec[right].second){
                         maxans = vec[left].first + vec[right].first;
                         ans = max(ans,maxans);
                         p = vec[left].second;
                    }
                }
                if(right == n) break;
            }
        }

        return ans;
    }
};
