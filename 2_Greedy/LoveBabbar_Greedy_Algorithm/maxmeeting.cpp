//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<pair<int,int>,int>& A, pair<pair<int,int>,int>& B) {
        // if(A.first.second != B.first.second)  return A.first.second < B.first.second;
        // else return A.first.first < B.first.first;
        return A.first.second<B.first.second;
    }

    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> ans;
        vector<pair<pair<int,int>,int>> vec;
        for(int i=0; i<N; i++) {
            vec.push_back({{S[i], F[i]}, i+1});
        }
        sort(vec.begin(), vec.end(), cmp);
            
        int end = vec[0].first.second;
        ans.push_back(vec[0].second);
        
        for(int i=1; i<N; i++) {
            if(end < vec[i].first.first) {
                end = vec[i].first.second;
                ans.push_back(vec[i].second);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
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