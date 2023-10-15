#include <bits/stdc++.h>
using namespace std;


vector<vector<vector<int>>> memo;
int helper(string &str, int index, char prev, int cb) {
    if (str.size() == index) {
        if (2 == cb) return 0;
        else return -1e9; // Return a very large negative value for invalid cases
    }
    int ans = helper(str, index + 1, prev, cb);

    if(str[index] == '?'){
        //a
            ans = max(ans, helper(str, index + 1, 'a', cb) + 1);
        //b
            ans = max(ans, helper(str, index + 1, 'b', cb) + 1);
    }

    // Take
    if (prev == 'a') {
        if (1 == cb) {
            ans = max(ans, helper(str, index + 1, str[index], cb + (str[index] == 'b')) + 1);
        }
        else if (str[index] == 'a') {
            ans = max(ans, helper(str, index + 1, str[index], cb));
        }
    }
    else if (prev == 'b') {
        if (str[index] == 'a') {
            ans = max(ans, helper(str, index + 1, str[index], cb + 1));
        }
        else if (str[index] == 'b'){
            ans = max(ans, helper(str, index + 1, str[index], cb) + 1);
        }
    }


    return memo[index][cb][prev - 'a'] = ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
            string str;
            cin >> str;
            int len = str.size();
            memo = vector<vector<vector<int>>>(len, vector<vector<int>>(4, vector<int>(2, -1)));
            int ans = helper(str, 0, 'a', 1);
            if(ans % 2 != 0 ) ans= ans- 1;
            cout << max(0, ans);
    }

    return 0;
}
