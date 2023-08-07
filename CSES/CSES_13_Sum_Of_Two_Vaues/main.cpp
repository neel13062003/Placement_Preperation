#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& A, pair<int, int>& B) {
    return A.first < B.first;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);  // Changed n+1 to n
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<pair<int, int>> vec1;
    for (int i = 0; i < vec.size(); i++) {
        vec1.push_back({vec[i], i});
    }
    sort(vec1.begin(), vec1.end(), cmp);

    int left = 0, right = vec1.size() - 1;
    pair<int, int> p;
    int ans = 0;
    while (left < right) {
        if (vec1[left].first + vec1[right].first == x) {
            p.first = vec1[left].second;
            p.second = vec1[right].second;
            ans = 1;
            break;
        } else if (vec1[left].first + vec1[right].first < x) {
            left++;
        } else {
            right--;
        }
    }  // Removed the extra 'a' character here

    if (ans == 1)
        cout << p.first + 1 << " " << p.second + 1 << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
