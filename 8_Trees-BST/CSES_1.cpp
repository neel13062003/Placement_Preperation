#include <bits/stdc++.h>
using namespace std;
vector<int> tree[200001];
void solve(int src,int par,vector<int>&ans){
    int subords = 0;
    for(int child:tree[src]){
        if(child!=par){
            solve(child,src,ans);
            subords += 1 + ans[child];
        }
    }
    ans[src] = subords;
}

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n-1;i++){
        cin>>vec[i];
    }
    vector<int>ans(n+1);
    solve(1,0,ans);

    return 0;
}