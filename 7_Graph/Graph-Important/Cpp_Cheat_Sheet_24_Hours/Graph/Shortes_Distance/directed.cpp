//Directed Acyclic Graph
//Love Babbar = 94
//Topological Sort(Behind Concpet DFS STack) - concept , here weight is also given so pair stored

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

class Graph{
    public:

        void addEdge(int u,int v,int weight,vector<pair<int,int>>adj[]){
            pair<int,int> p = make_pair(v,weight);
            adj[u].push_back(p);
        }

        void printEdge(vector<pair<int,int>>adj[]){
             int n = sizeof(adj) / sizeof(adj[0]);
            for(int i=0;i<n;i++){
                cout << i << " -> ";
                for(auto j : adj[i]){
                    cout << "{" << j.first << "," << j.second << "} ";
                }
                cout << endl;
            }
        }

        void dfs(int node,vector<int>&vis,stack<int>&s,vector<pair<int,int>>adj[]){
            vis[node]=1;

            for(auto it:adj[node]){
                if(!vis[it.first]){
                    dfs(it.first,vis,s,adj);
                }
            }
            s.push(node);
        }

        void getShortest(int src,vector<int>&dist,stack<int>&s,vector<pair<int,int>>adj[]){
            dist[src]=0;
            while(!s.empty()){
                int top = s.top();
                s.pop();

                if(dist[top] != INT_MAX){
                    for(auto i:adj[top]){
                        if(dist[top]+i.second < dist[i.first]){
                            dist[i.first]= dist[top]+i.second;
                        }
                    }
                }
            }
        }


};

int main(){

    int n=6;
    vector<pair<int,int>>adj[n];
    Graph g;

    g.addEdge(0,1,5,adj);
    g.addEdge(0,2,3,adj);
    g.addEdge(1,2,2,adj);
    g.addEdge(1,3,6,adj);
    g.addEdge(2,3,7,adj);
    g.addEdge(2,5,2,adj);
    g.addEdge(3,4,-1,adj);
    g.addEdge(4,5,-2,adj);

    g.printEdge(adj);



    stack<int>s;     //topological sort
    vector<int>vis(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            g.dfs(i,vis,s,adj);
        }
    }

    int src=1;
    vector<int>dist(n,INT_MAX);
    g.getShortest(src,dist,s,adj);

    cout<<"Answer is ";

    for(int i=0;i<dist.size();i++) {
        cout<<dist[i]<<" ";
    }

    return 0;
}
