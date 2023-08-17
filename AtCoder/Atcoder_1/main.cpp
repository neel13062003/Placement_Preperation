#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];

    vector<int>dp(n+1,-1);
    dp[0]=0;
    int a=0;
    for(int i=n-1;i>=0;i--){
        dp[i] = max(dp[i-1],dp[i-2]);
    }
    cout<<dp[0]<<endl;
    return 0;
}
