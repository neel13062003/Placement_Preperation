#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e7;
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<int>dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});    // if directed then this line is not there.
    }
    int source;
    cin>>source;
    dist[source]=0;

    // {weight,vertex}
    set<pair<int,int>>s;
    s.insert({0,source});
    while(!s.empty()){
        auto x= *(s.begin());
        s.erase(x);
        for(auto it:graph[x.second]){
            if(dist[it.first] > dist[x.second]+it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]<inf){
            cout<<dist[i]<<" ";
        }else{
           cout<<"-1"<<endl;
        }
    }


    return 0;
}
