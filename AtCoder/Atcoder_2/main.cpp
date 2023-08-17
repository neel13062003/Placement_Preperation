#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&vec,int n,int k){
    vector<int>dp(n+1,0);
    dp[1] = abs(dp[1]-dp[0]);
    // for(int i=2;i<n;i++){
    //     dp[i] = min(abs(vec[i]-vec[i-1])+dp[i-1],abs(vec[i]-vec[i-2])+dp[i-2]);
    // }

    for (int i = 2; i < n; i++) {
        int minCost = INT_MAX;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            minCost = min(minCost, abs(vec[i] - vec[i - j]) + dp[i - j]);
        }
        dp[i] = minCost;
    }
    return dp[n-1];
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];

    cout<< solve(vec,n,k) << endl;

    return 0;
}
