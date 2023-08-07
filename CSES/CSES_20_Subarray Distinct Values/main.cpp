#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k, n;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, c = 0, ans = 0;
    while (l < n) {
        // Expand the subarray to the right until we have 'k' distinct elements.
        while (r < n && c + (cnt[a[r]] == 0) <= k) {
            cnt[a[r]]++;
            c += (cnt[a[r]] == 1);
            r++;
        }

        // Count the subarrays that satisfy the condition and update 'ans'.
        ans += r - l;

        // Move the left pointer and update the count accordingly.
        c -= (cnt[a[l]] == 1);
        cnt[a[l]]--;
        l++;
    }

    cout << ans;
}
