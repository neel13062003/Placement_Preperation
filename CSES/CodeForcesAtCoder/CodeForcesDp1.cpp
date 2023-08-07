//https://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    void solve(const vector<int>& vec) {
        long long int freq[100005] = {0};
        for(int i=0;i<vec.size();i++) freq[vec[i]]++;
 
        long long int dp[100001] = {0};
        dp[1] = freq[1];
        for(int i=2;i<=1e5;i++){
            dp[i] = max(dp[i-1],dp[i-2] + i*freq[i]);
        }
        cout<<dp[100000]<<endl;
    }
};
 
int main() {
    int n;
    cin >> n;
    vector<int> inputArray(n);
    for (int i = 0; i < n; i++) cin >> inputArray[i];
 
    Solution obj;
    obj.solve(inputArray);
    return 0;
}
