//Code : Neel Soni
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=0;i<n;i++)cin>>vec[i];

        vector<int>ans(n+1);

        vector<int>vis(n+10,0);
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            if(vis[vec[i]] == 0){
                vis[vec[i]]++;
                ans[i]  = vec[i];
            }else{
                temp.push_back({vec[i],i});
            }
        }

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[ans[i]]++;

        for(int i=0;i<temp.size();i++){
            int t = temp[i].first;
            t = t+1;
            while(true){
                if(mp.find(t) == mp.end()) break;
                t = t+1;
            }
            int index = temp[i].second;
            ans[index] = t;
            mp[t]++;
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i] == 0) continue;
            else cout<<ans[i]<<" ";
        }
    }
    return 0;
}
