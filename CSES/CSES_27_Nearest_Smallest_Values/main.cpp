#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    stack<pair<int, int>> s; // Stores elements and their indices

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            cout << "0 ";
        } else {
            cout << s.top().second + 1 << " ";  //1 based indexing
        }

        s.push({arr[i], i});
    }

    cout << "\n";

    return 0;
}
