//https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;

    if (dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int ans = solveMem(coins, amount - coins[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    return dp[amount] = mini;
}

int solve(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int ans = solveMem(coins, amount, dp);
    if (ans == INT_MAX) return -1;
    else return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    cout << solve(vec, x) << endl;
    return 0;
}
