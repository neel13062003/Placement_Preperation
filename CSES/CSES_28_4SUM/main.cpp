#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first < b.first;
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> vec1;  // Remove the initial size n here
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        vec1.push_back({val, i});
    }

    sort(vec1.begin(), vec1.end(), cmp);

     for (int j = 0; j < n - 3; ++j) {
        for (int i = j+1; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {  // Change <= to < here
                if ( vec1[j].first + vec1[i].first + vec1[left].first + vec1[right].first == x) {
                    cout << vec1[j].second + 1 << " " <<  + vec1[i].second + 1 << " " << vec1[left].second + 1 << " " << vec1[right].second + 1;
                    return 0;
                } else if (vec1[j].first + vec1[i].first + vec1[left].first + vec1[right].first > x) {
                    right--;
                } else {
                    left++;
                }
            }
        }
     }

    cout << "IMPOSSIBLE";
    return 0;
}
