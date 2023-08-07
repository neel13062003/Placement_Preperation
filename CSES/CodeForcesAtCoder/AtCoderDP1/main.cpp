//https://atcoder.jp/contests/dp/tasks/dp_a
#include <algorithm> // For fill
#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000007;

class Solution {
public:
    int solve(const vector<int>& vec, vector<int>&dp, int n) {
        if (n == 0) return 0;
        if (n == 1) return abs(vec[0] - vec[1]);
        if (dp[n] != -1) return dp[n];
        int lastI = solve(vec,dp,n-1) + abs(vec[n - 1] - vec[n]);
        int secondLastI = solve(vec,dp,n-2) + abs(vec[n - 2] - vec[n]);
        return dp[n] = min(lastI, secondLastI);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inputArray(n);
    for (int i = 0; i < n; i++) cin >> inputArray[i];

    Solution obj;

    /*int dp[MAX_SIZE];
    fill(dp, dp + MAX_SIZE, -1);*/
    vector<int>dp(n+1,-1);

    int ans = obj.solve(inputArray, dp, n - 1);
    cout << ans << endl;
    return 0;
}
