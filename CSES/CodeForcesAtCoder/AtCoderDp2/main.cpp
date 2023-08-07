//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // i : current day
    // j : activity performed in ith day
    int solve(const vector<vector<int>>& vec, vector<vector<int>>&dp,int i , int j) {
        if(i == 1 ) return vec[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        for(int k=0;k<3;k++){
            //kth activitt on ith day
            if(j != k){
                ans = max(ans,solve(vec,dp,i-1,k) + vec[i][j]);
            }
        }
        return dp[i][j] = ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> inputArray(n+1,vector<int>(3,0));
    for (int i=1;i<=n; i++){
        for(int j=0;j<3;j++){
            cin >> inputArray[i][j];
        }
    }

    Solution obj;

    vector<vector<int>>dp(n+1,vector<int>(3,-1));

    int ans = max ( obj.solve(inputArray, dp, n, 0 ), max(obj.solve(inputArray, dp, n ,1) ,obj.solve(inputArray, dp, n, 2)));
    cout << ans << endl;
    return 0;
}



