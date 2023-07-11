//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        vector<int> hash(26, 0);
        
        int uniq = 0, start = 0, count = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (hash[S[i] - 'a'] == 0) {
                ++uniq;
            }
            ++hash[S[i] - 'a'];
            
            if (i - start + 1 == K) {
                if (uniq == K - 1) {
                    ++count;
                }
                --hash[S[start] - 'a'];
                if (hash[S[start] - 'a'] == 0) {
                    --uniq;
                }
                ++start;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends