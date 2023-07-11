//Graph Representation using Adjcency List.

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool direction){
        //direction 0->undirected
        //direction 1->directed

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<< "->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};

int main()
{
    int n;
    cout << "Enter Number of Nodes" << endl;
    cin>>n;

    int m;
    cout<<"Number of Edges"<<endl;
    cin>>m;

    Graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter Your Edges"<<endl;
        cin>>u>>v;
        g.addEdge(u,v,0);        //undirected gfraph
    }

    //print graph
    g.printAdj();
    return 0;
}
