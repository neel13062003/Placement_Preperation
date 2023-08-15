#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int coinCombination(vector<int>& coins, int target) {
    int n = coins.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= target; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }

    return dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << coinCombination(coins, target) << endl;
    return 0;
}
