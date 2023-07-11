//Directed Weighted Graph with negative edges = Bellmen ford algorithm  ( If you want to apply this on undirected then convert into)
//Source to destination      => Update version of Dijsktra Algotihm

//Time complexity = (n-1)*E(all edges travers) = here O(n*m)

// (n no.of nodes -1) times apply distance d[u]+w<d[v] apply on all edges
int bellmonFord(int m ,int n, int src,in dest, vector<vector<int>>&edges){
    vector<int>dist(n+1,1e9);

    //n-1 times
    for(int i=1;i<=n;i++){           //becasue node starts from 1
        //traveerse on edge
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u]!= 1e9 && !(dist[u]+w<dist[v])){
                dist[v]=dist[u]+w;
            }
        }
    }

    bool flag=true;
    //check for nefgative cycle
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u]!= 1e9 && !(dist[u]+w<dist[v])){
            flag=false;
        }
    }

    if(flag) return dist[dest];
    else return -1;
}