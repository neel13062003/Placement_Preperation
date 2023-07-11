#include <iostream>

using namespace std;

const int N=1e3+10;
int graph[N][N];
//Space complexity is To Much


int main()
{
    int n;
    cout << "Enter Number of Nodes" << endl;
    cin>>n;

    int m;
    cout<<"Number of Edges"<<endl;
    cin>>m;

    //for adjcecny matrix
    //vector<int>graph2[N];
    vector<pair<int,int>>graph2[N];

    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        /*graph[v1][v2]=1;
        //if direced
        graph[v2][v1]=1;*/

         graph[v1][v2]=4;
        //if direced
        graph[v2][v1]=5;

        /*graph2[v1].push_back(v2);
        graph1[v2].push_back(v1);*/


        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});

        if(graph[i][j]==1) connected;

    }
    return 0;
}
