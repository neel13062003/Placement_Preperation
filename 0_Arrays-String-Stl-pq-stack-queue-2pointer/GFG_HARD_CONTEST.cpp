//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void generateStrings(int n, std::string &s, int k, int open, int close, std::vector<std::string> &result) {
        if (open + close == 2 * n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            generateStrings(n, s, k, open + 1, close, result);
            s.pop_back();
        }

        if (close < open && close < k) {
            s.push_back(')');
            generateStrings(n, s, k, open, close + 1, result);
            s.pop_back();
        }

        // Generate strings for '?'
        if (open + close < n) {
            s.push_back('?');
            generateStrings(n, s, k, open + 1, close, result);
            s.pop_back();

            s.push_back('?');
            generateStrings(n, s, k, open, close + 1, result);
            s.pop_back();
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    if ((s[i] == ')' && st.top() == '(')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }

    int countStrings(int n, string &s, int k) {
        vector<string> result;
        generateStrings(n, s, k, 0, 0, result);

        stack<char> st;
        vector<string> next;
        for (int i = 0; i < result.size(); i++) {
            if (isValid(result[i]))
                next.push_back(result[i]);
            else
                continue;
        }

        int ans = -1;

        for (int i = 0; i < next.size(); i++) {
            int maxi1 = 0;
            int maxi2 = 0;
            int maxi = 0;
            for (int j = 0; j < next[i].size(); j++) {
                if (next[i][j] == '(') {
                    maxi1++;
                    maxi2 = 0;
                } else {
                    maxi2++;
                    maxi1 = 0;
                }
                maxi = max(maxi, max(maxi1, maxi2));
            }
            ans = max(ans, maxi);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        string s;
        cin>>n;
        cin>>s;
        cin>>k;
        Solution ob;
        cout<<ob.countStrings(n,s,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends