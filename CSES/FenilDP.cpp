#include <bits/stdc++.h>
using namespace std;

int solveMem(string &a, int i, int j, vector<vector<int>> &dp, int &sum, vector<pair<int, int>> &p,vector<bool>&vis) {
    int ans = 0;
    if(i>j) return ans;
    if (dp[i][j] != -1) return dp[i][j];


    if (a[i] == a[j] && (p[i].first == p[j].first && p[i].first == p[j - 1].second - p[i].second) && vis[j]==false && vis[i]==false) {
        vis[i] = true;
        vis[j] = true;
        ans = 1 + solveMem(a, i + 1, j - 1, dp, sum, p,vis);
    } else {
        int op1 = solveMem(a, i, j - 1, dp, sum, p,vis);
        int op2 = solveMem(a, i + 1, j, dp, sum, p,vis);
        int op3 = solveMem(a, i + 1, j - 1, dp, sum, p,vis);
        ans = max(op1,max(op2,op3));
        cout<<op1<<" "<<op2<<" "<<op3<<endl;
    }

    return dp[i][j] = ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    string word1;
    cin >> word1;

    int sum= 0;
    for (int i = 0; i < word1.size(); i++) {
        sum += word1[i] - '0';
    }
    int size_word = word1.size();
    vector<vector<int>> dp(size_word, vector<int>(size_word, -1));

    vector<pair<int, int>> p;
    int sum1 = 0;
    for (int i = 0; i < word1.size(); i++) {
        sum1 += word1[i] - '0';
        p.push_back({word1[i] - '0', sum1});
    }
    vector<bool>vis(size_word,false);
    cout << solveMem(word1, 0, size_word - 1, dp, sum, p,vis) << endl;
 }   return 0;
}