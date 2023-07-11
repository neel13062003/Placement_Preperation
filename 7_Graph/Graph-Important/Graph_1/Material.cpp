1) Directed Graph() & Undirected Graph(Biderectional Edges)
2) Nodes/Vertices &  Edges in Graph
3) Cycle Graph => Starting node and traverse thorugh in graph and come back is called cycle in graph
4) Cyclic Graph & Acyclic Graph
5) Path => Containts lot of nodes and edges & must each of them reachable (Repetiaion is not allowed)
6) Degrees in graph => Perticular node attached edges 
   => In UnDirected Graph Total number of degrees is ['2*E'];
7) Directed Graph => Indegree(For perticular nodes edges come inside) and Outdegree(for perticular nodes edges  come  outside).
8) Edges Weight   - Unit Weight(1);

******In Questionds *********

n(no of nodes) m(no. of edges)

m lines
1 4
2 4
4 1


1) Graph Represenation using 2 Methods => 1) Adjecy Metrix & 2) AdjecylIST                    (Must Kownn how to represent) 

 1) Use adg[N+1][N+1] = N*N Matrix so space complexity can be improved
 2) Using Vctor<int>adg[N+1] storing in list Space Complexity=> O(2E); Because Every nodes has 2 edges

 directed grapg ---        no change  adj[n][n]=weight;      // When weigft is specifically given, the graph

 
