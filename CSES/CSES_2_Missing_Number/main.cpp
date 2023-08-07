#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    unordered_map<long long int ,long long int>mp;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for(int i=1;i<=n;i++){
        if(mp.find(i) == mp.end()) cout<<i<<endl;
    }
    return 0;
}
