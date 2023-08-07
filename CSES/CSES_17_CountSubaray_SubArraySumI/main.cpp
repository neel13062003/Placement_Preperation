#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<long long, int> prefixSumCount;
    long long currentSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == x) {
            count++;
        }

        if (prefixSumCount.find(currentSum - x) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - x];
        }

        prefixSumCount[currentSum]++;
    }

    cout << count << "\n";

    return 0;
}
