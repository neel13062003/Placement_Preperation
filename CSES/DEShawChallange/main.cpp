/*
You are given a string which contains only a�s and b�s. A �good string� can be split into 3 parts. First part should contain only a�s(can contain 0 also), second should contain b�s and third should contain a�s. Now we need to find the length of the largest good string by deleting some characters from the string.
Example: s = �aaabbaabbbaa��answer�=�10
https://www.geeksforgeeks.org/d-e-shaw-internship-interview-experience-on-campus-2023/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> memo;

int helper(string &str, int index, char prev, int cb) {
    if (str.size() == index) {
        if (3 == cb) return 0;
        else return -1e9; // Return a very large negative value for invalid cases
    }
    if (-1 != memo[index][cb][prev - 'a']) return memo[index][cb][prev - 'a'];
    int ans = helper(str, index + 1, prev, cb);

    // Take
    if (prev == 'a') {
        if (1 == cb) {
            ans = max(ans, helper(str, index + 1, str[index], cb + (str[index] == 'b')) + 1);
        }
        else if (str[index] == 'a') {
            ans = max(ans, helper(str, index + 1, str[index], cb) + 1);
        }
    }
    else if (prev == 'b') {
        if (str[index] == 'a') {
            ans = max(ans, helper(str, index + 1, str[index], cb + 1) + 1);
        }
        else if (str[index] == 'b'){
            ans = max(ans, helper(str, index + 1, str[index], cb) + 1);
        }
    }
    return memo[index][cb][prev - 'a'] = ans;
}

int main() {
    string str;
    cin >> str;
    int len = str.size();
    memo = vector<vector<vector<int>>>(len, vector<vector<int>>(4, vector<int>(2, -1)));
    int ans = helper(str, 0, 'a', 1);
    cout << max(0, ans);
    return 0;
}

