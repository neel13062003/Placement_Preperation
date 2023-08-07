#include <bits/stdc++.h>

using namespace std;

void solve(int tc = 0) {
    int n; cin >> n;
    vector<bool> vis(n);
    int ans = 0;
    while (n--) {
        int x; cin >> x; x--;
        if (x == 0 || !vis[x - 1]) ans++;
        vis[x] = true;
    }
    cout << ans << "\n";
}
// 0 1 = 1
// 1 0 =
int main()
{
    solve();
    return 0;
}
