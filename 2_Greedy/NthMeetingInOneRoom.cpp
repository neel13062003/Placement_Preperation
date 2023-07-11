https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    static bool cmp(pair<int,int>& A, pair<int,int>& B){
        //return A.second < B.second || (A.second == B.second && A.first < B.first);
     return A.second < B.second;
    
        
    }

    
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        int count=1;
    
        int start1 = vec[0].first;
        int end1 = vec[0].second;
        for(int i=1;i<n;i++){
            if(end1 < vec[i].first){
                end1 = vec[i].second;
                count++;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends