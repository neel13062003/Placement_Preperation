#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void display(vector<int>& nums, int n, vector<vector<int>>& ans){
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
    }

    void findPermutations(vector<int>& nums, int n, vector<vector<int>>& ans){
        sort(nums.begin(), nums.end());
        do{
            display(nums, n, ans);
        } while(next_permutation(nums.begin(), nums.end()));
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        findPermutations(nums, n, ans);

        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> finalAns(s.begin(), s.end());
        return finalAns;
    }
};

int main(){
    vector<int> nums = {1, 1, 2};
    Solution s;
    vector<vector<int>> ans = s.permuteUnique(nums);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void display(vector<int>&nums,int n,vector<vector<int>>&ans){
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
    }

    void findPermutations(vector<int>&nums,int n,vector<vector<int>>&ans){
        sort(nums.begin(),nums.end());
        do{
            display(nums,n,ans);
        }while(next_permutation(nums.begin(),nums.end()));

    }


   vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        findPermutations(nums,n,ans);


        vector<vector<string>>vec;
        vector<string>vec1;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                vec1.push_back(to_string(ans[i][j]));
            }
            vec.push_back(vec1);
            vec1.clear();
        }

        set<vector<vector<string>>>s;
        for(int i=0;i<vec.size();i++){
            s.insert(vec[i]);
        }

        vector<vector<int>>finalAns;
        for(auto it:s){
            finalAns.push_back(*it);
        }
        return finalAns;
    }
};


int main(){

    vector<vector<int>>nums = { 1,1,2};
    Solution s;
    vector<vector<int> ans= s.permuteUnique(nums);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

*/
