#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long int x;
    cin >> n >> x;
    vector<int> vec(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int i = 0, j = n - 1;
    int count = 0;

    while (i <= j) {
        if (vec[i] + vec[j] <= x && (!vis[i] && !vis[j])) {
            count++;
            vis[i] = true;
            vis[j] = true;
            i++;
            j--;
        } else if (vec[i] + vec[j] > x) {
            vis[j] = true;
            count++;
            j--;
        } else {
            if (!vis[i])
                count++;
            i++;
        }
    }

    cout << count << endl;
    return 0;
}
