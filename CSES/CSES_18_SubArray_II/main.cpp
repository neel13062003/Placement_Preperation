#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];
    unordered_map<ll,ll>mp;

    ll count=0;
    ll current_sum = 0;
    for(int i=0;i<n;i++){
        current_sum = current_sum + vec[i];
        if(current_sum == x) count++;

        if(mp.find(current_sum - x) != mp.end()) count += mp[current_sum-x];
        mp[current_sum]++;
    }
    cout<<count <<"\n";
    return 0;
}

/*
Input:
5 7
2 4 1 2 7

Output:
3*/
