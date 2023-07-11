//Time Complexity = O(N + 2E(all edgency))
//Space Complexity = ADJCEYVECTOR+ QUEUE +  VIS VECTOR + PARENT VECTOR
//Love Babbar =93
//Logic = Build Parent

vector<int> shortestPath(vector<pair<int,int>>edges,int n,int m,int s,int t){
    //create adjency list 
    vector<int>adj[n];      // n = nodes
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n,0);
    vector<int>parent(n,0);

    parent[s]=-1;

    queue<int>q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto it:adj[front]){     //respected enter node in queue's we find all adjecy node
            if(!vis[it]){
                vis[it]=1;
                parent[it]=front;
                q.push(it);
            }
        }
    }

    //prepare shortest path - logic reverse to destination
    vector<int>ans;

    int currentNode=t;
    ans.push_back(t);

    while(currentNode!=s){
        currentNode = parent[currentNode]];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


//n = numbers of nodes,m= numbers of edges,s = source nodes,t=destination nodes