//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        pair<pair<int,int>,int> arr[N];
        vector<int> res;
        for(int i=0;i<N;i++)
            arr[i] = {{F[i],i+1},S[i]};
        sort(arr,arr+N);
        res.push_back(arr[0].first.second);
        int c = arr[0].first.first;
        for(int i = 1;i < N; i++) {
            if(arr[i].second > c) {
                res.push_back(arr[i].first.second);
                c = arr[i].first.first;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
