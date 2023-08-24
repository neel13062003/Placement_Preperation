#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int MAXN = 200001; // Define maximum number of nodes

vector<int> tree[MAXN];
int diameter[MAXN];
int downPath[MAXN];

void eval_downPaths(int src, int par)
{
    int bestChildDownPath = 0;
    bool leaf = true; // Corrected "leaf" initialization
    for(int child : tree[src])
    {
        if(child != par)
        {
            leaf = false;
            eval_downPaths(child, src);
            bestChildDownPath = max(bestChildDownPath, downPath[child]);
        }
    }
    if(leaf) downPath[src] = 0;
    else downPath[src] = 1 + bestChildDownPath;
}

void solve(int src, int par)
{
    int ans = 0;
    vector<int> childrenDownPaths;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src);
            childrenDownPaths.push_back(downPath[child]);
            ans = max(ans, diameter[child]);
        }
    }
    int numOfchildren = childrenDownPaths.size();
    sort(all(childrenDownPaths));

    if(numOfchildren == 0) diameter[src] = 0;
    else if(numOfchildren == 1) diameter[src] = 1 + childrenDownPaths[0];
    else diameter[src] = 2 + childrenDownPaths[numOfchildren - 1] + childrenDownPaths[numOfchildren - 2];

    diameter[src] = max(diameter[src], ans);
}

int main() {
   fast_io;
   ll t, n, m, x, i, j, k, q;
   cin >> t;
   while(t--)
   {
        cin >> n;
        for(int i = 1; i <= n; i++) // Initialize for each test case
        {
            tree[i].clear();
            diameter[i] = 0;
            downPath[i] = 0;
        }
        fr(0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        eval_downPaths(1, 0);
        solve(1, 0);
        cout << diameter[1] << endl;
   }
   return 0;
}
