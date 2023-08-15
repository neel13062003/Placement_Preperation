//https://leetcode.com/problems/combination-sum-iv/ - Exact , first cses dp is similar
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solveMem(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {  // Corrected this line (start from 0)
            if (i >= nums[j]) {
                dp[i] = (dp[i] + dp[i - nums[j]]) % mod;
            }
        }
    }

    return dp[target];
}

int solve(vector<int>& vec, int target) {
    return solveMem(vec, target);
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> vec(n);  // Corrected the size here
    for (int i = 0; i < n; i++) cin >> vec[i];

    cout << solve(vec, target) << endl;
    return 0;
}
