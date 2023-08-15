#include <bits/stdc++.h>
using namespace std;

int solveMem(string a,string b,int i,int j,vector<vector<int>>&dp){
    if(a.length() == i) return b.length()-j;
    if(b.length() == j) return a.length()-i;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) return solveMem(a,b,i+1,j+1,dp);
    else{
        int x = 1 + solveMem(a,b,i+1,j,dp);
        int y = 1 + solveMem(a,b,i,j+1,dp);
        int z = 1 + solveMem(a,b,i+1,j+1,dp);
        ans  = min(x,min(y,z));
    }
    return dp[i][j] = ans;
}

 int solveSpace(string &a, string &b){

        // vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));

        int maxi  = max(a.size(),b.size());

        vector<int>curr(maxi+1,0);
        vector<int>next(maxi+1,0);


        for(int j=0;j<b.length();j++){
           next[j] = b.length()-j;
        }

        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                 curr[b.length()] = a.length()-i;
                int ans=0;
                if(a[i] == b[j]) ans = next[j+1];
                else{
                    int x = 1 + curr[j+1];
                    int y = 1 + next[j];
                    int z = 1 + next[j+1];
                    ans = min(x,min(y,z));
                }
                curr[j]=ans;
            }
            next = curr;
        }

        return next[0];
    }

int solve(string a,string b){
   /* int n = a.size();
    int m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solveMem(a,b,0,0,dp);*/
     if(a.size()==0) return b.size();
     if(b.size()==0) return a.size();
     return solveSpace(a,b);
}

int main()
{
    string a , b;
    cin>>a>>b;
    int ans = solve(a, b);
    cout<<ans<<endl;
    return 0;
}
