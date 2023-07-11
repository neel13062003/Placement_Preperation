//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
    //   unordered_map<char, int> mp;
    //     int ans = 0;
    //     int count = 0;
    //     int start = 0;
    
    //     for (int i = 0; i < s.size(); i++) {
    //         if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
    //             start = mp[s[i]] + 1;
    //             count = i - start;
    //         }
            
    //         mp[s[i]] = i;
    //         count++;
    //         ans = max(ans, count);
    //     }
        
    //     return ans;
            vector<int> mp(256, -1);
            int n = s.size();
            int l = 0;
            int r = 0;
            int len = 0;
        
            while(r < n) {
                if(mp[s[r]] != -1) {
                    l = max(l, (mp[s[r]] + 1));
                }
            
                mp[s[r]] = r;
                len = max(len, r - l + 1);
                r++;
            }
            return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends