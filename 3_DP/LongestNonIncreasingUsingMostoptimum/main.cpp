#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//lower bound = this no. or ena thi nana,
//upper bound = ena thi tarat moto
int solveOptimalLNIS(int n, vector<int>& nums) {
    if (n == 0) return 0;
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] <= ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), nums[i], greater<int>()) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int main() {
    vector<int> nums = {1, 3, 1, 5, 4, 4, 6, 1};
    int result = solveOptimalLNIS(nums.size(), nums);

    cout << "Length of Longest Non-Increasing Subsequence: " << result << endl;

    return 0;
}
