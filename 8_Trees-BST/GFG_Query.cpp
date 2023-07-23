class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& g, vector<bool>& visited, long long& m_d, long long distance) {
        visited[node] = true;
        m_d = max(m_d, distance);

        for (auto& edge : g[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (!visited[neighbor]) {
                dfs(neighbor, g, visited, m_d, distance + weight);
            }
        }
    }

    vector<long long> longDrive(int n, vector<vector<int>>& edges, int q, vector<int>& query) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            g[u].emplace_back(v, weight);
            g[v].emplace_back(u, weight);
        }

        vector<long long> r;
        for (int i = 0; i < q; ++i) {
            int s_c = query[i];
            vector<bool> visited(n + 1, false);
            long long m_d = 0;
            dfs(s_c, g, visited, m_d, 0);
            r.push_back(m_d);
        }

        return r;
    }
}; 


class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<long long>& dp) {
        visited[node] = true;
        dp[node] = 0;

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (!visited[neighbor]) {
                if (dp[neighbor] == -1) {
                    dfs(neighbor, graph, visited, dp);
                }
                dp[node] = max(dp[node], dp[neighbor] + weight);
            }
        }
    }

    vector<long long> longDrive(int n, vector<vector<int>>& edges, int q, vector<int>& query) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }

        vector<long long> result;
        for (int i = 0; i < q; ++i) {
            int source = query[i];
            vector<bool> visited(n + 1, false);
            vector<long long> dp(n + 1, -1);
            dfs(source, graph, visited, dp);

            long long max_distance = 0;
            for (int j = 1; j <= n; ++j) {
                max_distance = max(max_distance, dp[j]);
            }

            result.push_back(max_distance);
        }

        return result;
    }
};

/**/
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<long long>& dp) {
        visited[node] = true;
        dp[node] = 0;

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, dp);
                dp[node] = max(dp[node], dp[neighbor] + weight);
            }
        }
    }

    vector<long long> longDrive(int n, vector<vector<int>>& edges, int q, vector<int>& query) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }

        vector<long long> result;
        for (int i = 0; i < q; ++i) {
            int source = query[i];
            vector<bool> visited(n + 1, false);
            vector<long long> dp(n + 1, 0);
            dfs(source, graph, visited, dp);

           
            long long max_distance = 0;
            for (int j = 1; j <= n; ++j) {
                max_distance = max(max_distance, dp[j]);
            }

            result.push_back(max_distance);
        }

        return result;
    }
};


/*
class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& g, vector<bool>& visited, long long& m_d, long long distance) {
        visited[node] = true;
        m_d = max(m_d, distance);

        for (auto& edge : g[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (!visited[neighbor]) {
                dfs(neighbor, g, visited, m_d, distance + weight);
            }
        }
    }

    vector<long long> longDrive(int n, vector<vector<int>>& edges, int q, vector<int>& query) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            g[u].emplace_back(v, weight);
            g[v].emplace_back(u, weight);
        }

        vector<long long> r;
        for (int i = 0; i < q; ++i) {
            int s_c = query[i];
            vector<bool> visited(n + 1, false);
            long long m_d = 0;
            dfs(s_c, g, visited, m_d, 0);
            r.push_back(m_d);
        }

        return r;
    }
}; */



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges(n - 1, vector<int>(3));
        for(int i = 0; i < n - 1; i++)
        {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        int q;
        cin >> q;
        vector<int> query(q);
        for(int i = 0; i < q; i++)
        {
            cin >> query[i];
        }
        Solution s;
        vector<long long> ans = s.longDrive(n, edges, q, query);
        for(long long x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends